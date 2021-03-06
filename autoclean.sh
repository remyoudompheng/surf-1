#!/bin/sh
test -e Makefile && (echo "running make distclean..." && make distclean)
rm -f install-sh
rm -f mkinstalldirs
rm -f missing
rm -f config.guess
rm -f config.sub
rm -f configure
rm -f Makefile.in */Makefile.in
rm -f aclocal.m4
rm -f config.log config.cache
(cd yaccsrc && rm -f polyyacc.c polyyacc.h polylex.c)
# rm -f yaccsrc/addDefaultSymbols.cc
find . -name \*~ -exec rm \{\} \;
