# Native Linux build of the tbox database connection test.
#
#   make -C tests/host run
#
# The Android build uses jni/Android.mk.  Both builds share the tbox source
# list in config/tbox_sources.mk and the same jni/main.c.

ROOT  := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
BUILD := $(ROOT)/build-host

TBOX_SRC   := $(ROOT)/thirdparty/tbox/src
TB_DIR     := $(TBOX_SRC)/tbox
SQLITE_DIR := $(ROOT)/thirdparty/sqlite3
CONFIG_DIR := $(ROOT)/config/host

CC     ?= cc
CFLAGS := -std=c99 -O2 -g -fPIC \
          -I$(CONFIG_DIR) -I$(TBOX_SRC) -I$(SQLITE_DIR)
LDLIBS := -lpthread -ldl -lm

include $(ROOT)/config/tbox_sources.mk

TBOX_SRCS := $(addprefix $(TB_DIR)/,$(TBOX_SRCFILES))
SRCS      := $(TBOX_SRCS) $(SQLITE_DIR)/sqlite3.c $(ROOT)/jni/main.c
OBJS      := $(patsubst $(ROOT)/%.c,$(BUILD)/%.o,$(SRCS))

BIN := $(BUILD)/dbtest
DB  := $(BUILD)/tbox_test.db

.PHONY: all run clean

all: $(BIN)

$(BIN): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(OBJS) -o $@ $(LDLIBS)

$(BUILD)/%.o: $(ROOT)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(BIN)
	@rm -f $(DB)
	$(BIN) $(DB)

clean:
	rm -rf $(BUILD)
