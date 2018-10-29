AC_PREREQ(2.59)
AC_INIT(xbin, 1.0)

AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE([foreign -Wall -Werror])

dnl CFLAGS+=" -static"

AC_PROG_CC([arm-linux-gnueabi-gcc])

AM_PROG_CC_C_O 

AC_CONFIG_FILES(Makefile 
                src/Makefile
                test/Makefile)

AC_OUTPUT

