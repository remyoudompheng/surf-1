AUTOMAKE_OPTIONS = foreign 1.4

SUBDIRS = image-formats drawfunc curve mt draw misc debug dither yaccsrc
if GUI
SUBDIRS += gtkgui
endif
if GTK2
SUBDIRS += gtk2gui
endif

SUBDIRS += src

EXTRA_DIST = background.pic Makefile.global aclocal.m4 surf.1 surf.xpm
man_MANS = surf.1
pkgdata_DATA = surf.xpm

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
