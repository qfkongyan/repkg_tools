#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(mkbootfs, 1.0, [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([mkbootfs.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE(mkbootfs, 1.0)

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UINT64_T

# Checks for library functions.
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset strchr strdup strtol])
AC_CHECK_LIB([pthread], [main])

AC_OUTPUT(Makefile)
