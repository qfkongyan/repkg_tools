#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([trees.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE(zlib, 1.0)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AC_PROG_CPP
AC_PROG_OBJC

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lc':
AC_CHECK_LIB([c], [main])
# FIXME: Replace `main' with a function in `-lz':
AC_CHECK_LIB([z], [main])
LT_INIT

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h limits.h malloc.h stddef.h stdlib.h string.h sys/time.h unistd.h utime.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_CHOWN
AC_FUNC_ERROR_AT_LINE
AC_FUNC_FSEEKO
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_CHECK_FUNCS([ftruncate memchr memmove memset mkdir munmap strchr strdup strerror strrchr strtol utime])

#AC_CONFIG_FILES([Makefile
#                 contrib/blast/Makefile
#                 contrib/puff/Makefile
#                 contrib/untgz/Makefile
#                 nintendods/Makefile])
#AC_CONFIG_SUBDIRS([contrib/minizip])
AC_OUTPUT([Makefile])
