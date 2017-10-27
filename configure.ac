#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(repkg_tools, 1.0, young_yang@sdmctech.com)
AC_CONFIG_SRCDIR([external/libselinux/utils/sefcontext_compile.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE(repkg_tools,1.0)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_MAKE_SET

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lcutils':
AC_CHECK_LIB([cutils], [main])
# FIXME: Replace `main' with a function in `-llog':
AC_CHECK_LIB([log], [main])
# FIXME: Replace `main' with a function in `-lmincrypt':
AC_CHECK_LIB([mincrypt], [main])
# FIXME: Replace `main' with a function in `-lpcre':
AC_CHECK_LIB([pcre], [main])
# FIXME: Replace `main' with a function in `-lpthread':
AC_CHECK_LIB([pthread], [main])
# FIXME: Replace `main' with a function in `-lselinux':
AC_CHECK_LIB([selinux], [main])
# FIXME: Replace `main' with a function in `-lsparse':
AC_CHECK_LIB([sparse], [main])
# FIXME: Replace `main' with a function in `-lz':
AC_CHECK_LIB([z], [main])

LT_INIT
AC_PROG_LN_S

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h inttypes.h limits.h malloc.h mntent.h netdb.h netinet/in.h stddef.h stdint.h stdlib.h string.h strings.h sys/ioctl.h sys/mount.h sys/param.h sys/socket.h sys/time.h sys/vfs.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_UID_T
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_CHECK_MEMBERS([struct stat.st_rdev])
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_CHOWN
AC_FUNC_ERROR_AT_LINE
AC_FUNC_FORK
AC_FUNC_FSEEKO
AC_FUNC_GETGROUPS
AC_FUNC_GETMNTENT
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_HEADER_MAJOR
AC_FUNC_MALLOC
AC_FUNC_MKTIME
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_FUNC_STRNLEN
AC_CHECK_FUNCS([alarm atexit bzero clock_gettime ftruncate getmntent gettimeofday isascii localtime_r memmove memset mkdir munmap realpath regcomp select setenv socket sqrt strcasecmp strchr strcspn strdup strerror strncasecmp strndup strpbrk strrchr strstr strtol strtoul strtoull tzset])

m4_pushdef([AC_CONFIG_SUBDIRS], []) 
AC_CONFIG_SUBDIRS([external/libselinux
                   external/zlib/src
				   ])
AC_OUTPUT([Makefile
			external/libselinux/Makefile
			external/zlib/src/Makefile
			external/sgs4ext4fs/Makefile
			system/core/libsparse/Makefile
			system/core/libcutils/Makefile
			system/core/liblog/Makefile
			system/core/libmincrypt/Makefile
			system/core/cpio/Makefile
			system/extras/ext4_utils/Makefile
			system/core/mkbootimg/Makefile
			])
