#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Growable Memory Buffers for C99], [0.0], [ac17@bk.ru])
AM_INIT_AUTOMAKE([foreign])
LT_INIT([disable-static])
AC_CONFIG_SRCDIR([src/buf.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4])

PKG_CHECK_MODULES([CHECK],[check])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stddef.h stdint.h stdlib.h sys/time.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([gettimeofday strtoull])

AC_ARG_ENABLE([gcov],
  [AS_HELP_STRING([--enable-gcov],
    [use Gcov to test the test suite])],
    [],
    [enable_gcov=no])

AC_CONFIG_FILES([Makefile src/Makefile tests/Makefile])
AM_CONDITIONAL([COND_GCOV],[test '!' "$enable_gcov" = no])
AC_OUTPUT


#adding script 
define([FILES], [src/buf.c] [src/buf.h] [src/libbuf.c])
define([TEMPLATE], [..........])
define(STR, [COMMENT:: Growable Memory Buffers for C99, 0.0: [0-9][0-9].[0-9][0-9].[0-9][0-9][0-9][0-9]])

define([TODAY], [date])
define([TODAYSTR], [/* COMMENT:: Growable Memory Buffers for C99, 0.0: $(date +%d.%m.%y) */])
define([REPLYSTR], [COMMENT:: Growable Memory Buffers for C99, 0.0: $(date +%d.%m.%y)])



sed -i -e "1s/STR//g" FILES
sed 't l'
sed -i -e "1i TODAYSTR" FILES
sed -e ':l'


