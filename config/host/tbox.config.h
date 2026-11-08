/*!The Treasure Box Library
 *
 * Hand-written tbox configuration for a native Linux host build.
 *
 * Used only by the CI host-run of the database connection test; the
 * Android build uses config/android/tbox.config.h.
 */
#ifndef TB_CONFIG_H
#define TB_CONFIG_H

/* version: keep in sync with thirdparty/tbox */
#define TB_CONFIG_VERSION           "1.8.2"
#define TB_CONFIG_VERSION_MAJOR     1
#define TB_CONFIG_VERSION_MINOR     8
#define TB_CONFIG_VERSION_ALTER     2
#define TB_CONFIG_VERSION_BUILD     0

/* platform */
#define TB_CONFIG_OS_LINUX          1

/* defines */
#define _GNU_SOURCE                 1
#define _REENTRANT                  1

/* types */
#define TB_CONFIG_TYPE_HAVE_FLOAT   1

/* features */
#define TB_CONFIG_FORCE_UTF8        1
#define TB_CONFIG_API_HAVE_DEPRECATED 1
#define TB_CONFIG_FEATURE_HAVE_ANONYMOUS_UNION 1

/* modules */
#define TB_CONFIG_MODULE_HAVE_DATABASE 1

/* packages */
#define TB_CONFIG_PACKAGE_HAVE_SQLITE3 1

/* libc functions available in glibc */
#define TB_CONFIG_LIBC_HAVE_MEMCPY      1
#define TB_CONFIG_LIBC_HAVE_MEMSET      1
#define TB_CONFIG_LIBC_HAVE_MEMMOVE     1
#define TB_CONFIG_LIBC_HAVE_MEMCMP      1
#define TB_CONFIG_LIBC_HAVE_MEMMEM      1
#define TB_CONFIG_LIBC_HAVE_STRCAT      1
#define TB_CONFIG_LIBC_HAVE_STRNCAT     1
#define TB_CONFIG_LIBC_HAVE_STRCPY      1
#define TB_CONFIG_LIBC_HAVE_STRNCPY     1
#define TB_CONFIG_LIBC_HAVE_STRLCPY     1
#define TB_CONFIG_LIBC_HAVE_STRLEN      1
#define TB_CONFIG_LIBC_HAVE_STRNLEN     1
#define TB_CONFIG_LIBC_HAVE_STRCHR      1
#define TB_CONFIG_LIBC_HAVE_STRRCHR     1
#define TB_CONFIG_LIBC_HAVE_STRSTR      1
#define TB_CONFIG_LIBC_HAVE_STRCASESTR  1
#define TB_CONFIG_LIBC_HAVE_STRCMP      1
#define TB_CONFIG_LIBC_HAVE_STRCASECMP  1
#define TB_CONFIG_LIBC_HAVE_STRNCMP     1
#define TB_CONFIG_LIBC_HAVE_STRNCASECMP 1

#define TB_CONFIG_LIBC_HAVE_WCSCAT      1
#define TB_CONFIG_LIBC_HAVE_WCSNCAT     1
#define TB_CONFIG_LIBC_HAVE_WCSCPY      1
#define TB_CONFIG_LIBC_HAVE_WCSNCPY     1
#define TB_CONFIG_LIBC_HAVE_WCSLEN      1
#define TB_CONFIG_LIBC_HAVE_WCSNLEN     1
#define TB_CONFIG_LIBC_HAVE_WCSSTR      1
#define TB_CONFIG_LIBC_HAVE_WCSCMP      1
#define TB_CONFIG_LIBC_HAVE_WCSNCMP     1
#define TB_CONFIG_LIBC_HAVE_WCSTOMBS    1
#define TB_CONFIG_LIBC_HAVE_MBSTOWCS    1
#define TB_CONFIG_LIBC_HAVE_TOWLOWER    1
#define TB_CONFIG_LIBC_HAVE_TOWUPPER    1

#define TB_CONFIG_LIBC_HAVE_GMTIME      1
#define TB_CONFIG_LIBC_HAVE_MKTIME      1
#define TB_CONFIG_LIBC_HAVE_LOCALTIME   1
#define TB_CONFIG_LIBC_HAVE_GETTIMEOFDAY 1
#define TB_CONFIG_LIBC_HAVE_SIGNAL      1
#define TB_CONFIG_LIBC_HAVE_SETJMP      1
#define TB_CONFIG_LIBC_HAVE_SIGSETJMP   1
#define TB_CONFIG_LIBC_HAVE_KILL        1
#define TB_CONFIG_LIBC_HAVE_BACKTRACE   1
#define TB_CONFIG_LIBC_HAVE_SETLOCALE   1
#define TB_CONFIG_LIBC_HAVE_FPUTC       1
#define TB_CONFIG_LIBC_HAVE_FGETC       1
#define TB_CONFIG_LIBC_HAVE_UNGETC      1
#define TB_CONFIG_LIBC_HAVE_FPUTS       1
#define TB_CONFIG_LIBC_HAVE_FGETS       1
#define TB_CONFIG_LIBC_HAVE_FREAD       1
#define TB_CONFIG_LIBC_HAVE_FWRITE      1
#define TB_CONFIG_LIBC_HAVE_SRANDOM     1
#define TB_CONFIG_LIBC_HAVE_RANDOM      1

/* libm functions */
#define TB_CONFIG_LIBM_HAVE_SINCOS      1
#define TB_CONFIG_LIBM_HAVE_SINCOSF     1
#define TB_CONFIG_LIBM_HAVE_LOG2        1
#define TB_CONFIG_LIBM_HAVE_LOG2F       1
#define TB_CONFIG_LIBM_HAVE_SQRT        1
#define TB_CONFIG_LIBM_HAVE_SQRTF       1
#define TB_CONFIG_LIBM_HAVE_ACOS        1
#define TB_CONFIG_LIBM_HAVE_ACOSF       1
#define TB_CONFIG_LIBM_HAVE_ASIN        1
#define TB_CONFIG_LIBM_HAVE_ASINF       1
#define TB_CONFIG_LIBM_HAVE_POW         1
#define TB_CONFIG_LIBM_HAVE_POWF        1
#define TB_CONFIG_LIBM_HAVE_FMOD        1
#define TB_CONFIG_LIBM_HAVE_FMODF       1
#define TB_CONFIG_LIBM_HAVE_TAN         1
#define TB_CONFIG_LIBM_HAVE_TANF        1
#define TB_CONFIG_LIBM_HAVE_ATAN        1
#define TB_CONFIG_LIBM_HAVE_ATANF       1
#define TB_CONFIG_LIBM_HAVE_ATAN2       1
#define TB_CONFIG_LIBM_HAVE_ATAN2F      1
#define TB_CONFIG_LIBM_HAVE_COS         1
#define TB_CONFIG_LIBM_HAVE_COSF        1
#define TB_CONFIG_LIBM_HAVE_SIN         1
#define TB_CONFIG_LIBM_HAVE_SINF        1
#define TB_CONFIG_LIBM_HAVE_EXP         1
#define TB_CONFIG_LIBM_HAVE_EXPF        1

/* posix functions available in glibc */
#define TB_CONFIG_POSIX_HAVE_POLL                1
#define TB_CONFIG_POSIX_HAVE_SELECT              1
#define TB_CONFIG_POSIX_HAVE_EPOLL_CREATE        1
#define TB_CONFIG_POSIX_HAVE_EPOLL_WAIT          1
#define TB_CONFIG_POSIX_HAVE_PTHREAD_MUTEX_INIT  1
#define TB_CONFIG_POSIX_HAVE_PTHREAD_CREATE      1
#define TB_CONFIG_POSIX_HAVE_PTHREAD_SETSPECIFIC 1
#define TB_CONFIG_POSIX_HAVE_PTHREAD_GETSPECIFIC 1
#define TB_CONFIG_POSIX_HAVE_PTHREAD_KEY_CREATE  1
#define TB_CONFIG_POSIX_HAVE_PTHREAD_KEY_DELETE  1
#define TB_CONFIG_POSIX_HAVE_PTHREAD_SETAFFINITY_NP 1
#define TB_CONFIG_POSIX_HAVE_SOCKET              1
#define TB_CONFIG_POSIX_HAVE_OPENDIR             1
#define TB_CONFIG_POSIX_HAVE_DLOPEN              1
#define TB_CONFIG_POSIX_HAVE_OPEN                1
#define TB_CONFIG_POSIX_HAVE_STAT64              1
#define TB_CONFIG_POSIX_HAVE_LSTAT64             1
#define TB_CONFIG_POSIX_HAVE_GETHOSTNAME         1
#define TB_CONFIG_POSIX_HAVE_GETIFADDRS          1
#define TB_CONFIG_POSIX_HAVE_SEM_INIT            1
#define TB_CONFIG_POSIX_HAVE_GETPAGESIZE         1
#define TB_CONFIG_POSIX_HAVE_SYSCONF             1
#define TB_CONFIG_POSIX_HAVE_SCHED_YIELD         1
#define TB_CONFIG_POSIX_HAVE_SCHED_SETAFFINITY   1
#define TB_CONFIG_POSIX_HAVE_READV               1
#define TB_CONFIG_POSIX_HAVE_WRITEV              1
#define TB_CONFIG_POSIX_HAVE_PREADV              1
#define TB_CONFIG_POSIX_HAVE_PWRITEV             1
#define TB_CONFIG_POSIX_HAVE_PREAD64             1
#define TB_CONFIG_POSIX_HAVE_PWRITE64            1
#define TB_CONFIG_POSIX_HAVE_FDATASYNC           1
#define TB_CONFIG_POSIX_HAVE_SENDFILE            1
#define TB_CONFIG_POSIX_HAVE_POSIX_SPAWNP        1
#define TB_CONFIG_POSIX_HAVE_EXECVP              1
#define TB_CONFIG_POSIX_HAVE_EXECVPE             1
#define TB_CONFIG_POSIX_HAVE_FORK                1
#define TB_CONFIG_POSIX_HAVE_VFORK               1
#define TB_CONFIG_POSIX_HAVE_WAITPID             1
#define TB_CONFIG_POSIX_HAVE_GETDTABLESIZE       1
#define TB_CONFIG_POSIX_HAVE_GETRLIMIT           1
#define TB_CONFIG_POSIX_HAVE_GETADDRINFO         1
#define TB_CONFIG_POSIX_HAVE_GETNAMEINFO         1
#define TB_CONFIG_POSIX_HAVE_GETHOSTBYNAME       1
#define TB_CONFIG_POSIX_HAVE_GETHOSTBYADDR       1
#define TB_CONFIG_POSIX_HAVE_FCNTL               1
#define TB_CONFIG_POSIX_HAVE_PIPE                1
#define TB_CONFIG_POSIX_HAVE_PIPE2               1
#define TB_CONFIG_POSIX_HAVE_MKFIFO              1
#define TB_CONFIG_POSIX_HAVE_MMAP                1
#define TB_CONFIG_POSIX_HAVE_FUTIMENS            1
#define TB_CONFIG_POSIX_HAVE_UTIMENSAT           1
#define TB_CONFIG_POSIX_HAVE_REGCOMP             1
#define TB_CONFIG_POSIX_HAVE_REGEXEC             1

/* linux functions */
#define TB_CONFIG_LINUX_HAVE_INOTIFY_INIT        1
#define TB_CONFIG_LINUX_HAVE_IFADDRS             1

/* bsd functions */
#define TB_CONFIG_BSD_HAVE_FLOCK                 1

#endif /* TB_CONFIG_H */
