#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([rhash],[rhash_library_init],[],[AC_MSG_ERROR([There is no rhash library])])

# Checks for header files.
AC_CHECK_HEADERS([string.h])
AC_CHECK_HEADERS([rhash.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

AC_ARG_ENABLE([readline],
    AS_HELP_STRING([--use-readline], [Use input with readline library]),
    AC_DEFINE(USE_READLINE,[],[Use readline])
)

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
