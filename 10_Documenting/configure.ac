#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([guessnumber], [0.0], [ac17@bk.ru])
AM_INIT_AUTOMAKE([foreign])
DX_INIT_DOXYGEN(guessnumber)
AC_CONFIG_SRCDIR([guessnumber.c])
AC_CONFIG_HEADERS([config.h])


# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.


# Checks for library functions.
AC_CHECK_FUNCS([realpath setlocale])

AC_CONFIG_FILES([Makefile doxyfile])

AC_OUTPUT
