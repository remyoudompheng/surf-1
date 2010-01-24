include $(top_srcdir)/Makefile.global

bin_PROGRAMS = surf
surf_SOURCES = compfn.cc \
        cube.cc \
        float_buffer.cc \
        gui_config.cc \
        init_parser.cc \
        main.cc \
        oct_quan.cc \
        roots.cc \
        color.h \
        compfn.h \
        cube.h \
        def.h \
        gui_config.h \
        gui_enum.h \
        init_parser.h \
        oct_quan.h \
        roots.h \
        stop.cc stop.h \
	float_buffer.h\
	bit_buffer.cc bit_buffer.h			\
	SurfaceDataStruct.cc SurfaceDataStruct.h	\
	CanvasDataStruct.cc CanvasDataStruct.h		\
	symtab.cc symtab.h				\
	RgbBuffer.cc RgbBuffer.h			\
	WindowGeometry.cc WindowGeometry.h		\
	antialiasing_factor.cc antialiasing_factor.h	\
	RGBToNetscape.cc RGBToNetscape.h		\
	mytypes.h \
	Options.h Options.cc

surf_LDADD =

if GUI
surf_LDADD += $(top_builddir)/gtkgui/libsurf_gtkgui.a
surf_LDADD += -lXmu -lXext -lXt @X_PRE_LIBS@ @X_LIBS@ -lX11 @X_EXTRA_LIBS@ @GTK_LIBS@
endif

if CUPS
surf_LDADD += -lcups
endif

surf_LDADD += \
     $(top_builddir)/yaccsrc/libsurf_parser.a \
     $(top_builddir)/curve/libsurf_curve.a \
     $(top_builddir)/draw/libsurf_draw.a \
     $(top_builddir)/drawfunc/libsurf_drawfunc.a \
     $(top_builddir)/debug/libsurf_debug.a \
     $(top_builddir)/dither/libsurf_dither.a \
     $(top_builddir)/image-formats/libsurf_image.a \
     $(top_builddir)/misc/libsurf_misc.a \
     $(top_builddir)/mt/libsurf_mt.a

surf_LDADD += -lfl

