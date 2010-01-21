bin_PROGRAMS = gtk2surf

UIDefinition.h: gtk2gui.xml
	$(XXD) -i gtk2gui.xml > UIDefinition.h

gtk2surf_SOURCES = start.cc UIDefinition.h
