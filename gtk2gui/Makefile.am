bin_PROGRAMS = gtk2surf

UIDefinition.h: gtk2gui.xml
	$(XXD) -i gtk2gui.xml | sed -e 's/unsigned char/const char/' > UIDefinition.h

gtk2surf_SOURCES = start.cc UIDefinition.h

clean-local:
	rm -f UIDefinition.h 
