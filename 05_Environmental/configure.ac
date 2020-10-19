#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([PCRE show], [1.0], [ac17@bk.ru])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([pcreshow.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AM_INIT_AUTOMAKE

# Checks for libraries.
AC_CHECK_LIB([ncursesw], [initscr],[],  AC_MSG_ERROR([Curses is needed]))


# Checks for header files.
AC_CHECK_HEADERS([locale.h string.h stdio.h locale.h] ,[],  AC_MSG_ERROR([No some file *.h] ))
AC_CHECK_HEADERS([ncurses.h] ,[],  AC_MSG_ERROR([No ncurses.h] ))

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
