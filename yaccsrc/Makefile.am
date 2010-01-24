include $(top_srcdir)/Makefile.global

EXTRA_DIST = polyyacc.h
YACC = @YACC@ -d

polylex.c: polyyacc.c
lexfunc.cc: polyyacc.c

noinst_LIBRARIES = libsurf_parser.a
libsurf_parser_a_SOURCES =	bezierarith.cc bezierarith.h	\
			hornerarith.cc hornerarith.h	\
			monomarith.cc monomarith.h	\
			mymemory.cc mymemory.h		\
			polyarith.cc polyarith.h	\
			polyroot.cc polyroot.h		\
			polyx.cc polyx.h		\
			simple.cc simple.h		\
			polyyacc.y polylex.l polylexyacc.h degree.h \
			lexfunc.cc			\
			SymbolTable.cc SymbolTable.h	\
			Script.cc Script.h 		\
			ExecuteScriptStruct.cc ExecuteScriptStruct.h \
			addDefaultSymbols.cc addDefaultSymbols.h

libsurf_parser_a_LIBADD = \
	$(top_srcdir)/mt/libsurf_mt.a \
	$(top_srcdir)/drawfunc/libsurf_drawfunc.a \
	$(top_srcdir)/draw/libsurf_draw.a
