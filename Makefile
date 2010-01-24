# Makefile.in generated automatically by automake 1.4-p6 from Makefile.am

# Copyright (C) 1994, 1995-8, 1999, 2001 Free Software Foundation, Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.


SHELL = /bin/sh

srcdir = .
top_srcdir = .

prefix = /usr/local
exec_prefix = ${prefix}

bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec
datadir = ${prefix}/share
sysconfdir = ${prefix}/etc
sharedstatedir = ${prefix}/com
localstatedir = ${prefix}/var
libdir = ${exec_prefix}/lib
infodir = ${prefix}/share/info
mandir = ${prefix}/share/man
includedir = ${prefix}/include
oldincludedir = /usr/include

DESTDIR =

pkgdatadir = $(datadir)/surf
pkglibdir = $(libdir)/surf
pkgincludedir = $(includedir)/surf

top_builddir = .

ACLOCAL = /home/sven/trunk/src/missing aclocal-1.4
AUTOCONF = autoconf
AUTOMAKE = /home/sven/trunk/src/missing automake-1.4
AUTOHEADER = autoheader

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL} $(AM_INSTALL_PROGRAM_FLAGS)
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL}
transform = s,x,x,

NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
host_alias = 
host_triplet = i686-pc-linux-gnu
CC = gcc
CUPSCONFIG = /usr/bin/cups-config
CXX = g++
GTK_CFLAGS = -I/usr/include -I/usr/include/gtk-1.2 -I/usr/include/glib-1.2 -I/usr/lib/glib/include
GTK_CONFIG = /usr/bin/gtk-config
GTK_LIBS = -L/usr/lib -lgtk -lgdk -rdynamic -lgmodule -lglib -ldl -lXi -lXext -lX11 -lm
HAVE_LIB = @HAVE_LIB@
LEX = flex
LIB = @LIB@
LTLIB = @LTLIB@
MAKEINFO = /home/sven/trunk/src/missing makeinfo
PACKAGE = surf
RANLIB = ranlib
VERSION = 1.0.6
YACC = yacc
canonical_host_type = @canonical_host_type@

AUTOMAKE_OPTIONS = foreign 1.4

DITHER_OBJ = dither/dither_brute.o dither/dither_clustered.o dither/dither_dispersed.o dither/dither_floyd_steinberg.o dither/dither_jarvis_judis_ninke.o dither/dither_stucki.o dither/dither_dot_diffusion.o dither/dither_smooth_dot_diffusion.o dither/copy_rgb_to_float.o dither/copy_rgb_to_float_curve.o dither/dither_pixel_radius_adjust.o

DEBUG_OBJ = debug/debug.o
MISC_OBJ = misc/welcomeMessage.o misc/Misc.o misc/mystrdup.o

DRAW_OBJ = draw/NewClip.o draw/NewClipSphere.o draw/NewClipSphereCentral.o draw/NewClipSphereParallel.o draw/NewClipAlgebraic.o draw/NewClipAlgebraicCube.o draw/NewClipAlgebraicTetra.o draw/NewClipAlgebraicOcta.o draw/NewClipAlgebraicDode.o draw/NewClipAlgebraicIco.o draw/NewClipAlgebraicCyl.o draw/NewClipAlgebraicUser.o draw/NewSimpleClip.o draw/SurfaceCalc.o

MT_OBJ = mt/GuiThread.o mt/Thread.o mt/TSDrawingArea.o mt/cthread.o
GTKGUI_OBJ = gtkgui/start.o gtkgui/MainWindowController.o gtkgui/mycolor.o gtkgui/TextWidget.o gtkgui/showAbout.o gtkgui/ProgressDialog.o gtkgui/ColorWindow.o gtkgui/DrawingArea.o gtkgui/PositionWindow.o gtkgui/ConfigurationWindow.o gtkgui/NumericWindow.o gtkgui/ColorSelectionButton.o gtkgui/IlluminationWindow.o gtkgui/Requester.o gtkgui/DisplayWindow.o gtkgui/WidgetReadWriter.o gtkgui/DitherWindow.o gtkgui/ClipWindow.o gtkgui/Document.o gtkgui/RGBToStandard.o gtkgui/mygtk.o gtkgui/SaveImageDialog.o gtkgui/PrintImageDialog.o
#GTKGUI_OBJ = gtkgui/start.o gtkgui/MainWindowController.o gtkgui/mycolor.o gtkgui/TextWidget.o gtkgui/showAbout.o gtkgui/ProgressDialog.o gtkgui/ColorWindow.o gtkgui/DrawingArea.o gtkgui/PositionWindow.o gtkgui/ConfigurationWindow.o gtkgui/NumericWindow.o gtkgui/ColorSelectionButton.o gtkgui/IlluminationWindow.o gtkgui/Requester.o gtkgui/DisplayWindow.o gtkgui/WidgetReadWriter.o gtkgui/DitherWindow.o gtkgui/ClipWindow.o gtkgui/Document.o gtkgui/RGBToStandard.o gtkgui/mygtk.o gtkgui/SaveImageDialog.o

CURVE_OBJ = curve/RBTree.o curve/resultant.o curve/RootFinder2d.o curve/RootFinder3d.o curve/DrawCurve.o curve/BigInteger.o

DRAWFUNC_OBJ = drawfunc/Bezier.o drawfunc/Clip.o drawfunc/DrawfuncData.o drawfunc/DrawFunc.o drawfunc/Hornergroup.o drawfunc/Horner.o drawfunc/MappingMatrix.o drawfunc/MultiVariatePolynom.o drawfunc/Position.o drawfunc/Sturmchain.o drawfunc/UniVariatePolynom.o drawfunc/Vector.o drawfunc/HornergroupXY.o drawfunc/HornergroupXYZ.o drawfunc/RationalHornerXY.o

IMAGE_OBJ = image-formats/eps.o image-formats/ps.o image-formats/sun.o image-formats/tiffprint.o image-formats/xbitmap.o image-formats/xwd.o image-formats/jpeg.o

SRC_OBJ = src/RGBToNetscape.o src/compfn.o src/cube.o src/float_buffer.o src/gui_config.o src/init_parser.o src/main.o src/oct_quan.o src/RgbBuffer.o src/roots.o src/bit_buffer.o src/SurfaceDataStruct.o src/CanvasDataStruct.o src/symtab.o src/WindowGeometry.o src/antialiasing_factor.o src/stop.o src/Options.o

YACCSRC_OBJ = yaccsrc/bezierarith.o yaccsrc/hornerarith.o yaccsrc/monomarith.o yaccsrc/mymemory.o yaccsrc/polyarith.o yaccsrc/polylex.o yaccsrc/polyroot.o yaccsrc/polyyacc.o yaccsrc/simple.o yaccsrc/polyx.o yaccsrc/lexfunc.o yaccsrc/SymbolTable.o yaccsrc/addDefaultSymbols.o yaccsrc/Script.o yaccsrc/ExecuteScriptStruct.o

LOCAL_OBJECTS = $(CURVE_OBJ) $(BALLS_OBJ) $(MISC_OBJ) $(DRAWFUNC_OBJ) $(IMAGE_OBJ) $(SRC_OBJ) $(YACCSRC_OBJ) $(MT_OBJ) $(DRAW_OBJ) $(DEBUG_OBJ) $(DITHER_OBJ)
SUBDIRS = yaccsrc src image-formats drawfunc curve mt draw misc debug dither gtkgui
#SUBDIRS = yaccsrc src image-formats drawfunc curve mt draw misc debug dither

bin_PROGRAMS = surf
surf_SOURCES = 
EXTRA_DIST = background.pic Makefile.global aclocal.m4 surf.1 surf.xpm
man_MANS = surf.1
pkgdata_DATA = surf.xpm
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
mkinstalldirs = $(SHELL) $(top_srcdir)/mkinstalldirs
CONFIG_CLEAN_FILES = 
PROGRAMS =  $(bin_PROGRAMS)


DEFS = -DPACKAGE_NAME=\"\" -DPACKAGE_TARNAME=\"\" -DPACKAGE_VERSION=\"\" -DPACKAGE_STRING=\"\" -DPACKAGE_BUGREPORT=\"\" -DPACKAGE=\"surf\" -DVERSION=\"1.0.6\" -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -D__EXTENSIONS__=1 -D_ALL_SOURCE=1 -D_GNU_SOURCE=1 -D_POSIX_PTHREAD_SEMANTICS=1 -D_TANDEM_SOURCE=1 -D__EXTENSIONS__=1 -D_ALL_SOURCE=1 -D_GNU_SOURCE=1 -D_POSIX_PTHREAD_SEMANTICS=1 -D_TANDEM_SOURCE=1 -DSTDC_HEADERS=1 -DYYTEXT_POINTER=1 -DHAVE_EXPLICIT_TEMPLATE_INSTANTIATION=1 -DHAVE_LIBPTHREAD=1 -D_REENTRANT=1 -DHAVE_LIBCUPS=1 -DHAVE_LIBM=1 -DHAVE_LIBZ=1 -DHAVE_LIBJPEG=1 -DHAVE_LIBTIFF=1 -DHAVE_LIBGMP=1 -I. -I$(srcdir) 
CPPFLAGS =  -DDATADIR=\"${datarootdir}\"
LDFLAGS = 
LIBS = -lgmp -ltiff -ljpeg -lz -lm -lcups -lgssapi_krb5 -lkrb5 -lk5crypto -lcom_err -lkeyutils -lresolv -ldl -lssl -lcrypto -lz -lpthread -lm -lcrypt -lpthread 
X_CFLAGS = 
X_LIBS = 
X_EXTRA_LIBS = 
X_PRE_LIBS =  -lSM -lICE
surf_OBJECTS = 
surf_LDADD = $(LDADD)
surf_DEPENDENCIES = 
surf_LDFLAGS = 
man1dir = $(mandir)/man1
MANS = $(man_MANS)

NROFF = nroff
DATA =  $(pkgdata_DATA)

DIST_COMMON =  README AUTHORS COPYING ChangeLog INSTALL Makefile.am \
Makefile.in NEWS TODO acinclude.m4 aclocal.m4 config.guess config.sub \
configure configure.in install-sh missing mkinstalldirs


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = tar
GZIP_ENV = --best
DIST_SUBDIRS =  yaccsrc src image-formats drawfunc curve mt draw misc \
debug dither gtkgui yaccsrc src image-formats drawfunc curve mt draw \
misc debug dither
SOURCES = $(surf_SOURCES)
OBJECTS = $(surf_OBJECTS)

all: all-redirect
.SUFFIXES:
.SUFFIXES: .S .c .o .s
$(srcdir)/Makefile.in: Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	cd $(top_srcdir) && $(AUTOMAKE) --foreign --include-deps Makefile

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) \
	  && CONFIG_FILES=$@ CONFIG_HEADERS= $(SHELL) ./config.status

$(ACLOCAL_M4):  configure.in  acinclude.m4
	cd $(srcdir) && $(ACLOCAL)

config.status: $(srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	$(SHELL) ./config.status --recheck
$(srcdir)/configure: $(srcdir)/configure.in $(ACLOCAL_M4) $(CONFIGURE_DEPENDENCIES)
	cd $(srcdir) && $(AUTOCONF)

mostlyclean-binPROGRAMS:

clean-binPROGRAMS:
	-test -z "$(bin_PROGRAMS)" || rm -f $(bin_PROGRAMS)

distclean-binPROGRAMS:

maintainer-clean-binPROGRAMS:

install-binPROGRAMS: $(bin_PROGRAMS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(bindir)
	@list='$(bin_PROGRAMS)'; for p in $$list; do \
	  if test -f $$p; then \
	    echo "  $(INSTALL_PROGRAM) $$p $(DESTDIR)$(bindir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`"; \
	     $(INSTALL_PROGRAM) $$p $(DESTDIR)$(bindir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`; \
	  else :; fi; \
	done

uninstall-binPROGRAMS:
	@$(NORMAL_UNINSTALL)
	list='$(bin_PROGRAMS)'; for p in $$list; do \
	  rm -f $(DESTDIR)$(bindir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`; \
	done

.c.o:
	$(COMPILE) -c $<

.s.o:
	$(COMPILE) -c $<

.S.o:
	$(COMPILE) -c $<

mostlyclean-compile:
	-rm -f *.o core *.core

clean-compile:

distclean-compile:
	-rm -f *.tab.c

maintainer-clean-compile:

install-man1:
	$(mkinstalldirs) $(DESTDIR)$(man1dir)
	@list='$(man1_MANS)'; \
	l2='$(man_MANS)'; for i in $$l2; do \
	  case "$$i" in \
	    *.1*) list="$$list $$i" ;; \
	  esac; \
	done; \
	for i in $$list; do \
	  if test -f $(srcdir)/$$i; then file=$(srcdir)/$$i; \
	  else file=$$i; fi; \
	  ext=`echo $$i | sed -e 's/^.*\\.//'`; \
	  inst=`echo $$i | sed -e 's/\\.[0-9a-z]*$$//'`; \
	  inst=`echo $$inst | sed '$(transform)'`.$$ext; \
	  echo " $(INSTALL_DATA) $$file $(DESTDIR)$(man1dir)/$$inst"; \
	  $(INSTALL_DATA) $$file $(DESTDIR)$(man1dir)/$$inst; \
	done

uninstall-man1:
	@list='$(man1_MANS)'; \
	l2='$(man_MANS)'; for i in $$l2; do \
	  case "$$i" in \
	    *.1*) list="$$list $$i" ;; \
	  esac; \
	done; \
	for i in $$list; do \
	  ext=`echo $$i | sed -e 's/^.*\\.//'`; \
	  inst=`echo $$i | sed -e 's/\\.[0-9a-z]*$$//'`; \
	  inst=`echo $$inst | sed '$(transform)'`.$$ext; \
	  echo " rm -f $(DESTDIR)$(man1dir)/$$inst"; \
	  rm -f $(DESTDIR)$(man1dir)/$$inst; \
	done
install-man: $(MANS)
	@$(NORMAL_INSTALL)
	$(MAKE) $(AM_MAKEFLAGS) install-man1
uninstall-man:
	@$(NORMAL_UNINSTALL)
	$(MAKE) $(AM_MAKEFLAGS) uninstall-man1

install-pkgdataDATA: $(pkgdata_DATA)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(pkgdatadir)
	@list='$(pkgdata_DATA)'; for p in $$list; do \
	  if test -f $(srcdir)/$$p; then \
	    echo " $(INSTALL_DATA) $(srcdir)/$$p $(DESTDIR)$(pkgdatadir)/$$p"; \
	    $(INSTALL_DATA) $(srcdir)/$$p $(DESTDIR)$(pkgdatadir)/$$p; \
	  else if test -f $$p; then \
	    echo " $(INSTALL_DATA) $$p $(DESTDIR)$(pkgdatadir)/$$p"; \
	    $(INSTALL_DATA) $$p $(DESTDIR)$(pkgdatadir)/$$p; \
	  fi; fi; \
	done

uninstall-pkgdataDATA:
	@$(NORMAL_UNINSTALL)
	list='$(pkgdata_DATA)'; for p in $$list; do \
	  rm -f $(DESTDIR)$(pkgdatadir)/$$p; \
	done

# This directory's subdirectories are mostly independent; you can cd
# into them and run `make' without going through this Makefile.
# To change the values of `make' variables: instead of editing Makefiles,
# (1) if the variable is set in `config.status', edit `config.status'
#     (which will cause the Makefiles to be regenerated when you run `make');
# (2) otherwise, pass the desired values on the `make' command line.



all-recursive install-data-recursive install-exec-recursive \
installdirs-recursive install-recursive uninstall-recursive  \
check-recursive installcheck-recursive info-recursive dvi-recursive:
	@set fnord $$MAKEFLAGS; amf=$$2; \
	dot_seen=no; \
	target=`echo $@ | sed s/-recursive//`; \
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  echo "Making $$target in $$subdir"; \
	  if test "$$subdir" = "."; then \
	    dot_seen=yes; \
	    local_target="$$target-am"; \
	  else \
	    local_target="$$target"; \
	  fi; \
	  (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) $$local_target) \
	   || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	done; \
	if test "$$dot_seen" = "no"; then \
	  $(MAKE) $(AM_MAKEFLAGS) "$$target-am" || exit 1; \
	fi; test -z "$$fail"

mostlyclean-recursive clean-recursive distclean-recursive \
maintainer-clean-recursive:
	@set fnord $$MAKEFLAGS; amf=$$2; \
	dot_seen=no; \
	rev=''; list='$(SUBDIRS)'; for subdir in $$list; do \
	  rev="$$subdir $$rev"; \
	  test "$$subdir" != "." || dot_seen=yes; \
	done; \
	test "$$dot_seen" = "no" && rev=". $$rev"; \
	target=`echo $@ | sed s/-recursive//`; \
	for subdir in $$rev; do \
	  echo "Making $$target in $$subdir"; \
	  if test "$$subdir" = "."; then \
	    local_target="$$target-am"; \
	  else \
	    local_target="$$target"; \
	  fi; \
	  (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) $$local_target) \
	   || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	done && test -z "$$fail"
tags-recursive:
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  test "$$subdir" = . || (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) tags); \
	done

tags: TAGS

ID: $(HEADERS) $(SOURCES) $(LISP)
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	here=`pwd` && cd $(srcdir) \
	  && mkid -f$$here/ID $$unique $(LISP)

TAGS: tags-recursive $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) $(LISP)
	tags=; \
	here=`pwd`; \
	list='$(SUBDIRS)'; for subdir in $$list; do \
   if test "$$subdir" = .; then :; else \
	    test -f $$subdir/TAGS && tags="$$tags -i $$here/$$subdir/TAGS"; \
   fi; \
	done; \
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	test -z "$(ETAGS_ARGS)$$unique$(LISP)$$tags" \
	  || (cd $(srcdir) && etags $(ETAGS_ARGS) $$tags  $$unique $(LISP) -o $$here/TAGS)

mostlyclean-tags:

clean-tags:

distclean-tags:
	-rm -f TAGS ID

maintainer-clean-tags:

distdir = $(PACKAGE)-$(VERSION)
top_distdir = $(distdir)

# This target untars the dist file and tries a VPATH configuration.  Then
# it guarantees that the distribution is self-contained by making another
# tarfile.
distcheck: dist
	-rm -rf $(distdir)
	GZIP=$(GZIP_ENV) $(TAR) zxf $(distdir).tar.gz
	mkdir $(distdir)/=build
	mkdir $(distdir)/=inst
	dc_install_base=`cd $(distdir)/=inst && pwd`; \
	cd $(distdir)/=build \
	  && ../configure --srcdir=.. --prefix=$$dc_install_base \
	  && $(MAKE) $(AM_MAKEFLAGS) \
	  && $(MAKE) $(AM_MAKEFLAGS) dvi \
	  && $(MAKE) $(AM_MAKEFLAGS) check \
	  && $(MAKE) $(AM_MAKEFLAGS) install \
	  && $(MAKE) $(AM_MAKEFLAGS) installcheck \
	  && $(MAKE) $(AM_MAKEFLAGS) dist
	-rm -rf $(distdir)
	@banner="$(distdir).tar.gz is ready for distribution"; \
	dashes=`echo "$$banner" | sed s/./=/g`; \
	echo "$$dashes"; \
	echo "$$banner"; \
	echo "$$dashes"
dist: distdir
	-chmod -R a+r $(distdir)
	GZIP=$(GZIP_ENV) $(TAR) chozf $(distdir).tar.gz $(distdir)
	-rm -rf $(distdir)
dist-all: distdir
	-chmod -R a+r $(distdir)
	GZIP=$(GZIP_ENV) $(TAR) chozf $(distdir).tar.gz $(distdir)
	-rm -rf $(distdir)
distdir: $(DISTFILES)
	-rm -rf $(distdir)
	mkdir $(distdir)
	-chmod 777 $(distdir)
	@for file in $(DISTFILES); do \
	  d=$(srcdir); \
	  if test -d $$d/$$file; then \
	    cp -pr $$d/$$file $(distdir)/$$file; \
	  else \
	    test -f $(distdir)/$$file \
	    || ln $$d/$$file $(distdir)/$$file 2> /dev/null \
	    || cp -p $$d/$$file $(distdir)/$$file || :; \
	  fi; \
	done
	for subdir in $(DIST_SUBDIRS); do \
	  if test "$$subdir" = .; then :; else \
	    test -d $(distdir)/$$subdir \
	    || mkdir $(distdir)/$$subdir \
	    || exit 1; \
	    chmod 777 $(distdir)/$$subdir; \
	    (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) top_distdir=../$(distdir) distdir=../$(distdir)/$$subdir distdir) \
	      || exit 1; \
	  fi; \
	done
	$(MAKE) $(AM_MAKEFLAGS) top_distdir="$(top_distdir)" distdir="$(distdir)" dist-hook
info-am:
info: info-recursive
dvi-am:
dvi: dvi-recursive
check-am: all-am
check: check-recursive
installcheck-am:
installcheck: installcheck-recursive
install-exec-am: install-binPROGRAMS
install-exec: install-exec-recursive

install-data-am: install-man install-pkgdataDATA
install-data: install-data-recursive

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am
install: install-recursive
uninstall-am: uninstall-binPROGRAMS uninstall-man uninstall-pkgdataDATA
uninstall: uninstall-recursive
all-am: Makefile $(PROGRAMS) $(MANS) $(DATA)
all-redirect: all-recursive
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) AM_INSTALL_PROGRAM_FLAGS=-s install
installdirs: installdirs-recursive
installdirs-am:
	$(mkinstalldirs)  $(DESTDIR)$(bindir) $(DESTDIR)$(mandir)/man1 \
		$(DESTDIR)$(pkgdatadir)


mostlyclean-generic:

clean-generic:

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log stamp-h stamp-h[0-9]*

maintainer-clean-generic:
mostlyclean-am:  mostlyclean-binPROGRAMS mostlyclean-compile \
		mostlyclean-tags mostlyclean-generic

mostlyclean: mostlyclean-recursive

clean-am:  clean-binPROGRAMS clean-compile clean-tags clean-generic \
		mostlyclean-am clean-local

clean: clean-recursive

distclean-am:  distclean-binPROGRAMS distclean-compile distclean-tags \
		distclean-generic clean-am

distclean: distclean-recursive
	-rm -f config.status

maintainer-clean-am:  maintainer-clean-binPROGRAMS \
		maintainer-clean-compile maintainer-clean-tags \
		maintainer-clean-generic distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-recursive
	-rm -f config.status

.PHONY: mostlyclean-binPROGRAMS distclean-binPROGRAMS clean-binPROGRAMS \
maintainer-clean-binPROGRAMS uninstall-binPROGRAMS install-binPROGRAMS \
mostlyclean-compile distclean-compile clean-compile \
maintainer-clean-compile install-man1 uninstall-man1 install-man \
uninstall-man uninstall-pkgdataDATA install-pkgdataDATA \
install-data-recursive uninstall-data-recursive install-exec-recursive \
uninstall-exec-recursive installdirs-recursive uninstalldirs-recursive \
all-recursive check-recursive installcheck-recursive info-recursive \
dvi-recursive mostlyclean-recursive distclean-recursive clean-recursive \
maintainer-clean-recursive tags tags-recursive mostlyclean-tags \
distclean-tags clean-tags maintainer-clean-tags distdir info-am info \
dvi-am dvi check check-am installcheck-am installcheck install-exec-am \
install-exec install-data-am install-data install-am install \
uninstall-am uninstall all-redirect all-am all installdirs-am \
installdirs mostlyclean-generic distclean-generic clean-generic \
maintainer-clean-generic clean mostlyclean distclean maintainer-clean


surf: $(LOCAL_OBJECTS) $(GTKGUI_OBJ)
	$(CXX) $(LOCAL_OBJECTS) $(GTKGUI_OBJ) -o surf $(LDFLAGS) -lXmu -lXext -lXt  -lSM -lICE  -lX11  $(LIBS) -lfl -L/usr/lib -lgtk -lgdk -rdynamic -lgmodule -lglib -ldl -lXi -lXext -lX11 -lm -lcups
#surf: $(LOCAL_OBJECTS) $(GTKGUI_OBJ)
#	$(CXX) $(LOCAL_OBJECTS) $(GTKGUI_OBJ) -o surf $(LDFLAGS) -lXmu -lXext -lXt  -lSM -lICE  -lX11  $(LIBS) -lfl -L/usr/lib -lgtk -lgdk -rdynamic -lgmodule -lglib -ldl -lXi -lXext -lX11 -lm
##surf: $(LOCAL_OBJECTS)
##	$(CXX) $(LOCAL_OBJECTS) -o surf $(LDFLAGS) $(LIBS) -lfl 

clean-local::
	rm -f *~

dist-hook::
	absdistdir=`cd $(distdir) && pwd` && \
	(cd $(top_srcdir) && find examples docs | grep -v CVS | cpio -pad $$absdistdir)

#install-data-local:: surf.xpm
#	$(mkinstalldirs) $(pkgdatadir)
#	@(test -s surf.xpm && $(INSTALL) -m 644 surf.xpm $(pkgdatadir)) || echo "WARNING: background picture not installed"
#
#surf.xpm: surf $(srcdir)/background.pic
#	./surf --no-gui $(srcdir)/background.pic

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
