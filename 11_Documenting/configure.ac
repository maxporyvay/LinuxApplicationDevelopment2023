#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([Bisect Guess Program], [0.0], [maximporyvay@yandex.ru], [bisect])
AM_INIT_AUTOMAKE([foreign])
DX_INIT_DOXYGEN([bisect])
AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_REQUIRE_VERSION(0.21)
GETTEXT_PACKAGE=bisect
AC_SUBST(GETTEXT_PACKAGE, $PACKAGE)
ALL_LINGUAS="ru"
AC_CONFIG_SRCDIR([src/bisect.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
IT_PROG_INTLTOOL

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([realpath setlocale])

AC_CONFIG_FILES([Makefile src/Makefile Doxyfile po/Makefile.in])
AC_OUTPUT
