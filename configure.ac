AC_PREREQ(2.59)
AC_INIT(libdyldcache, 1.0)
AM_CONFIG_HEADER(config.h)
AM_PROG_LIBTOOL

AC_PROG_INSTALL
AC_PROG_MAKE_SET

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE(libdyldcache, 1.0)

AM_PROG_CC_C_O
AC_LANG_C

AC_HEADER_STDC
AC_CONFIG_MACRO_DIR([m4])

PKG_CHECK_MODULES(libcrippy, libcrippy-1.0 >= 1.0)
PKG_CHECK_MODULES(libmacho, libmacho-1.0 >= 1.0)

AC_CONFIG_FILES(Makefile src/Makefile include/Makefile tools/Makefile libdyldcache-1.0.pc)

AC_OUTPUT
