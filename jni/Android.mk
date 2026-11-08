# Builds:
#   libsqlite3.a : SQLite amalgamation (fetched by scripts/fetch-sqlite3.sh)
#   libtbox.a    : tbox (git submodule at thirdparty/tbox)
#   test         : tbox database connection test executable
#
# tbox is configured by config/android/tbox.config.h and its source list is
# shared with the host Makefile via config/tbox_sources.mk.

LOCAL_PATH := $(call my-dir)
TB_ROOT    := $(LOCAL_PATH)/..

# LOCAL_C_INCLUDES must be absolute (relative paths are resolved against the
# directory ndk-build is invoked from, not against LOCAL_PATH).
TB_SRC_DIR      := $(TB_ROOT)/thirdparty/tbox/src
TB_SRC_REL      := ../thirdparty/tbox/src/tbox
TB_CONFIG_DIR   := $(TB_ROOT)/config/android
TB_SQLITE_DIR   := $(TB_ROOT)/thirdparty/sqlite3

include $(TB_ROOT)/config/tbox_sources.mk

# --------------------------------------------------------------------------
# SQLite
# --------------------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE     := sqlite3
LOCAL_SRC_FILES  := ../thirdparty/sqlite3/sqlite3.c
LOCAL_C_INCLUDES := $(TB_SQLITE_DIR) $(TB_CONFIG_DIR)
LOCAL_CFLAGS     := -fPIC -DSQLITE_THREADSAFE=1 -DSQLITE_OMIT_LOAD_EXTENSION=1
include $(BUILD_STATIC_LIBRARY)

# --------------------------------------------------------------------------
# tbox
# --------------------------------------------------------------------------
# Not compiled directly: platform/android/backtrace.c, platform/android/print.c
# and platform/android/dns.c are #included by their platform wrappers.
include $(CLEAR_VARS)
LOCAL_MODULE     := tbox
LOCAL_SRC_FILES  := $(addprefix $(TB_SRC_REL)/,$(TBOX_SRCFILES)) \
                    $(TB_SRC_REL)/platform/android/android.c \
                    $(TB_SRC_REL)/platform/android/directory.c
LOCAL_C_INCLUDES := $(TB_SRC_DIR) $(TB_CONFIG_DIR) $(TB_SQLITE_DIR)
LOCAL_CFLAGS     := -fPIC
include $(BUILD_STATIC_LIBRARY)

# --------------------------------------------------------------------------
# test executable
# --------------------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE           := test
LOCAL_SRC_FILES        := main.c
LOCAL_C_INCLUDES       := $(TB_SRC_DIR) $(TB_CONFIG_DIR) $(TB_SQLITE_DIR)
LOCAL_STATIC_LIBRARIES := tbox sqlite3
LOCAL_LDLIBS           := -llog -lm -ldl
include $(BUILD_EXECUTABLE)
