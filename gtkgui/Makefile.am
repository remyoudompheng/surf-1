include $(top_srcdir)/Makefile.global

CPPFLAGS = @CPPFLAGS@ @GTK_CFLAGS@
noinst_LIBRARIES = libsurf_gtkgui.a

libsurf_gtkgui_a_LIBADD = \
	$(top_srcdir)/yaccsrc/libsurf_parser.a \
	$(top_srcdir)/misc/libsurf_misc.a \
	$(top_srcdir)/mt/libsurf_mt.a

libsurf_gtkgui_a_SOURCES = mycolor.cc mycolor.h			\
	MainWindowController.cc MainWindowController.h		\
	TextWidget.cc TextWidget.h				\
	start.cc						\
	mygtk.cc mygtk.h					\
	showAbout.cc showAbout.h				\
	ProgressDialog.cc ProgressDialog.h			\
	ColorWindow.cc ColorWindow.h				\
	DrawingArea.cc DrawingArea.h				\
	PositionWindow.cc PositionWindow.h			\
	ConfigurationWindow.cc ConfigurationWindow.h		\
	NumericWindow.cc NumericWindow.h			\
	ParameterWindow.h					\
	ColorSelectionButton.cc ColorSelectionButton.h		\
	IlluminationWindow.cc IlluminationWindow.h		\
	Requester.cc Requester.h				\
	DisplayWindow.cc DisplayWindow.h			\
	WidgetReadWriter.cc WidgetReadWriter.h			\
	DitherWindow.cc DitherWindow.h				\
	ClipWindow.cc ClipWindow.h				\
	TableBuilder.h RadioButtonBuilder.h			\
	RGBToStandard.cc RGBToStandard.h			\
	SaveImageDialog.cc SaveImageDialog.h			\
	OptionMenuBuilder.h

if CUPS
libsurf_gtkgui_a_SOURCES += \
	PrintImageDialog.cc PrintImageDialog.h
endif