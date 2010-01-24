include $(top_srcdir)/Makefile.global

bin_PROGRAMS = gtk2surf

UIDefinition.h: gtk2gui.xml
	$(XXD) -i gtk2gui.xml | sed -e 's/unsigned char/const char/' > UIDefinition.h

start.cc: UIDefinition.h

gtk2surf_SOURCES = start.cc UIDefinition.h \
		   MainWindow.cc MainWindow.h

gtk2surf_CPPFLAGS = $(GTK2_CFLAGS) $(GTKMM_CFLAGS)

gtk2surf_LDADD = \
    $(top_builddir)/misc/libsurf_misc.a \
    $(GTK2_LIBS) $(GTKMM_LIBS) -lfl

clean-local:
	rm -f UIDefinition.h 
