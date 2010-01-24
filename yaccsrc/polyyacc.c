/* A Bison parser, made by GNU Bison 2.0.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRING = 258,
     INTEGER = 259,
     DOUBLE = 260,
     MONOM = 261,
     NAME = 262,
     NAME_POLYXYZ = 263,
     NAME_MONOM = 264,
     NAME_DOUBLE = 265,
     NAME_INTEGER = 266,
     NAME_STRING = 267,
     NAME_COMMAND = 268,
     NAME_LABEL = 269,
     TYPE_POLYXYZ = 270,
     TYPE_MONOM = 271,
     TYPE_DOUBLE = 272,
     TYPE_INTEGER = 273,
     TYPE_STRING = 274,
     IF = 275,
     GOTO = 276,
     EQUAL = 277,
     NOTEQUAL = 278,
     BIGGER = 279,
     BIGGERTHAN = 280,
     SMALLER = 281,
     SMALLERTHAN = 282,
     AND = 283,
     OR = 284,
     ITOSTR = 285,
     ITOSTRN = 286,
     ITOASC = 287,
     ITOASCN = 288,
     SQRT = 289,
     SINUS = 290,
     COSINUS = 291,
     TANGENS = 292,
     COTANGENS = 293,
     POWER = 294,
     ARCUS_SINUS = 295,
     ARCUS_COSINUS = 296,
     ARCUS_TANGENS = 297,
     ARCUS_COTANGENS = 298,
     DEGREE = 299,
     LENGTH = 300,
     HESSE = 301,
     HESSIAN_SURFACE = 302,
     HESSIAN_CURVE = 303,
     DIFF = 304,
     ROTATE = 305,
     X_AXIS = 306,
     Y_AXIS = 307,
     Z_AXIS = 308,
     SYSTEM = 309,
     INCLUDE = 310,
     UMINUS = 311
   };
#endif
#define STRING 258
#define INTEGER 259
#define DOUBLE 260
#define MONOM 261
#define NAME 262
#define NAME_POLYXYZ 263
#define NAME_MONOM 264
#define NAME_DOUBLE 265
#define NAME_INTEGER 266
#define NAME_STRING 267
#define NAME_COMMAND 268
#define NAME_LABEL 269
#define TYPE_POLYXYZ 270
#define TYPE_MONOM 271
#define TYPE_DOUBLE 272
#define TYPE_INTEGER 273
#define TYPE_STRING 274
#define IF 275
#define GOTO 276
#define EQUAL 277
#define NOTEQUAL 278
#define BIGGER 279
#define BIGGERTHAN 280
#define SMALLER 281
#define SMALLERTHAN 282
#define AND 283
#define OR 284
#define ITOSTR 285
#define ITOSTRN 286
#define ITOASC 287
#define ITOASCN 288
#define SQRT 289
#define SINUS 290
#define COSINUS 291
#define TANGENS 292
#define COTANGENS 293
#define POWER 294
#define ARCUS_SINUS 295
#define ARCUS_COSINUS 296
#define ARCUS_TANGENS 297
#define ARCUS_COTANGENS 298
#define DEGREE 299
#define LENGTH 300
#define HESSE 301
#define HESSIAN_SURFACE 302
#define HESSIAN_CURVE 303
#define DIFF 304
#define ROTATE 305
#define X_AXIS 306
#define Y_AXIS 307
#define Z_AXIS 308
#define SYSTEM 309
#define INCLUDE 310
#define UMINUS 311




/* Copy the first part of user declarations.  */
#line 33 "polyyacc.y"

/* ------------------------------------------------------------------------- */
/* polyyacc.y: polynomial parser                                             */
/* Author:   Stephan Endrass                                                 */
/* Address:  endrass@mi.uni-erlangen.de                                      */
/* Date:     14.8.94                                                         */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define  POLYYACC_L

/* #include "simple.h"*/
#include "mymemory.h"
#include "monomarith.h"
#include "polyarith.h"
#include "polylexyacc.h"
#include "cthread.h"

extern  int     surface_run_commands;
/* static  char    ascii[26]="abcdefghijklmnopqrstuvwxyz";*/


int    itotexascii( int i,char *s,int l )
{
	if( i < 0 || l < 2 || s==(char*)NULL ) {
		return  0;
	} else {
		/*  find length of 26-adic number i  */
		
		int     foo    = i;
		int     length = ( foo==0 ? 1 : 0 );
		
		while( foo > 0 ) {
			foo /= 26;
			length++;
		}

		/*  test if s is long enough  */

		if( length >= l ) {
			return  0;
		}

		/*  terminate with \0  */

		s[length]='\0';

		while( length > 0 ) {
			length--;
/* 			s[length]= ascii[i%26]; */
			s[length]= 'a'+(i%26);
			i = i/26;
		}

		return  1;
	}
}




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 98 "polyyacc.y"
typedef union YYSTYPE {
    char    *str;                       /* possible string value             */
    int     ival;                       /* possible integer value            */
    double  dval;                       /* posiible double value             */
    monxyz  mon;                        /* possible monomial value           */
    polyxyz p;                          /* possible polynomial value         */

    symtab  *sym;                       /* possible symbol referred to       */
} YYSTYPE;
/* Line 190 of yacc.c.  */
#line 263 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 213 of yacc.c.  */
#line 275 "y.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1422

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  11
/* YYNRULES -- Number of rules. */
#define YYNRULES  184
/* YYNRULES -- Number of states. */
#define YYNSTATES  405

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    60,     2,     2,
      66,    67,    58,    56,    68,    57,     2,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    63,
       2,    65,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     9,    13,    16,    19,    22,    24,
      26,    29,    31,    34,    37,    42,    47,    52,    57,    61,
      65,    69,    73,    76,    81,    86,    91,    95,    99,   103,
     106,   111,   116,   120,   124,   127,   132,   136,   139,   144,
     148,   155,   158,   162,   164,   169,   174,   181,   188,   192,
     196,   200,   204,   208,   212,   216,   220,   224,   228,   232,
     236,   240,   244,   248,   252,   256,   260,   264,   268,   272,
     276,   280,   284,   288,   292,   296,   300,   304,   308,   312,
     316,   320,   324,   328,   331,   334,   341,   350,   359,   364,
     369,   377,   385,   393,   395,   399,   403,   407,   411,   415,
     419,   423,   427,   430,   433,   435,   437,   441,   445,   450,
     455,   462,   467,   472,   477,   482,   487,   492,   497,   502,
     507,   512,   517,   522,   527,   532,   537,   542,   546,   550,
     554,   558,   562,   566,   570,   574,   578,   582,   586,   590,
     594,   598,   602,   606,   609,   612,   614,   616,   620,   625,
     630,   634,   638,   642,   646,   650,   654,   658,   662,   666,
     670,   674,   678,   682,   686,   690,   694,   698,   702,   706,
     710,   714,   718,   722,   726,   730,   734,   738,   742,   746,
     750,   754,   757,   760,   762
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      70,     0,    -1,    71,    -1,    71,    74,    63,    -1,    71,
      72,    64,    -1,    71,    73,    -1,    74,    63,    -1,    72,
      64,    -1,    73,    -1,    14,    -1,    55,    75,    -1,    13,
      -1,    54,    75,    -1,    15,     7,    -1,    15,     7,    65,
      76,    -1,    15,     7,    65,    77,    -1,    15,     7,    65,
      78,    -1,    15,     7,    65,    79,    -1,     8,    65,    76,
      -1,     8,    65,    77,    -1,     8,    65,    78,    -1,     8,
      65,    79,    -1,    16,     7,    -1,    16,     7,    65,    77,
      -1,    16,     7,    65,    78,    -1,    16,     7,    65,    79,
      -1,     9,    65,    77,    -1,     9,    65,    78,    -1,     9,
      65,    79,    -1,    17,     7,    -1,    17,     7,    65,    78,
      -1,    17,     7,    65,    79,    -1,    10,    65,    78,    -1,
      10,    65,    79,    -1,    18,     7,    -1,    18,     7,    65,
      79,    -1,    11,    65,    79,    -1,    19,     7,    -1,    19,
       7,    65,     3,    -1,    12,    65,    75,    -1,    20,    66,
      79,    67,    21,    14,    -1,    21,    14,    -1,    75,    56,
      75,    -1,     3,    -1,    30,    66,    79,    67,    -1,    32,
      66,    79,    67,    -1,    31,    66,    79,    68,    79,    67,
      -1,    33,    66,    79,    68,    79,    67,    -1,    66,    76,
      67,    -1,    76,    56,    76,    -1,    76,    56,    77,    -1,
      76,    56,    78,    -1,    76,    56,    79,    -1,    77,    56,
      76,    -1,    78,    56,    76,    -1,    79,    56,    76,    -1,
      77,    56,    77,    -1,    77,    56,    78,    -1,    77,    56,
      79,    -1,    78,    56,    77,    -1,    79,    56,    77,    -1,
      76,    57,    76,    -1,    76,    57,    77,    -1,    76,    57,
      78,    -1,    76,    57,    79,    -1,    77,    57,    76,    -1,
      78,    57,    76,    -1,    79,    57,    76,    -1,    77,    57,
      77,    -1,    77,    57,    78,    -1,    77,    57,    79,    -1,
      78,    57,    77,    -1,    79,    57,    77,    -1,    76,    58,
      76,    -1,    76,    58,    77,    -1,    76,    58,    78,    -1,
      76,    58,    79,    -1,    77,    58,    76,    -1,    78,    58,
      76,    -1,    79,    58,    76,    -1,    76,    59,    78,    -1,
      76,    59,    79,    -1,    76,    61,    79,    -1,    57,    76,
      -1,    56,    76,    -1,    49,    66,    76,    68,    77,    67,
      -1,    49,    66,    76,    68,    77,    68,    79,    67,    -1,
      49,    66,    76,    68,    79,    68,    79,    67,    -1,    48,
      66,    76,    67,    -1,    47,    66,    76,    67,    -1,    50,
      76,    68,    78,    68,    51,    67,    -1,    50,    76,    68,
      78,    68,    52,    67,    -1,    50,    76,    68,    78,    68,
      53,    67,    -1,     8,    -1,    77,    58,    77,    -1,    77,
      58,    79,    -1,    77,    58,    78,    -1,    79,    58,    77,
      -1,    78,    58,    77,    -1,    77,    59,    79,    -1,    77,
      59,    78,    -1,    77,    61,    79,    -1,    57,    77,    -1,
      56,    77,    -1,     6,    -1,     9,    -1,    66,    77,    67,
      -1,    66,    78,    67,    -1,    34,    66,    78,    67,    -1,
      34,    66,    79,    67,    -1,    39,    66,    78,    68,    78,
      67,    -1,    35,    66,    78,    67,    -1,    35,    66,    79,
      67,    -1,    36,    66,    78,    67,    -1,    36,    66,    79,
      67,    -1,    37,    66,    78,    67,    -1,    37,    66,    79,
      67,    -1,    38,    66,    78,    67,    -1,    38,    66,    79,
      67,    -1,    40,    66,    78,    67,    -1,    40,    66,    79,
      67,    -1,    41,    66,    78,    67,    -1,    41,    66,    79,
      67,    -1,    42,    66,    78,    67,    -1,    42,    66,    79,
      67,    -1,    43,    66,    78,    67,    -1,    43,    66,    79,
      67,    -1,    78,    56,    78,    -1,    78,    56,    79,    -1,
      79,    56,    78,    -1,    78,    57,    78,    -1,    78,    57,
      79,    -1,    79,    57,    78,    -1,    78,    58,    78,    -1,
      78,    58,    79,    -1,    79,    58,    78,    -1,    78,    59,
      78,    -1,    78,    59,    79,    -1,    79,    59,    78,    -1,
      79,    59,    79,    -1,    78,    61,    78,    -1,    78,    61,
      79,    -1,    79,    61,    78,    -1,    57,    78,    -1,    56,
      78,    -1,     5,    -1,    10,    -1,    66,    79,    67,    -1,
      44,    66,    76,    67,    -1,    45,    66,    76,    67,    -1,
      79,    28,    79,    -1,    79,    29,    79,    -1,    79,    22,
      79,    -1,    79,    23,    79,    -1,    79,    24,    79,    -1,
      79,    25,    79,    -1,    79,    26,    79,    -1,    79,    27,
      79,    -1,    78,    22,    78,    -1,    78,    23,    78,    -1,
      78,    24,    78,    -1,    78,    25,    78,    -1,    78,    26,
      78,    -1,    78,    27,    78,    -1,    79,    22,    78,    -1,
      79,    23,    78,    -1,    79,    24,    78,    -1,    79,    25,
      78,    -1,    79,    26,    78,    -1,    79,    27,    78,    -1,
      78,    22,    79,    -1,    78,    23,    79,    -1,    78,    24,
      79,    -1,    78,    25,    79,    -1,    78,    26,    79,    -1,
      78,    27,    79,    -1,    79,    56,    79,    -1,    79,    57,
      79,    -1,    79,    58,    79,    -1,    79,    60,    79,    -1,
      79,    61,    79,    -1,    57,    79,    -1,    56,    79,    -1,
       4,    -1,    11,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   140,   140,   143,   144,   145,   146,   147,   148,   151,
     190,   195,   202,   209,   214,   219,   224,   229,   234,   255,
     276,   297,   319,   324,   329,   334,   339,   354,   369,   385,
     390,   395,   400,   415,   431,   436,   441,   457,   461,   466,
     486,   496,   505,   523,   527,   538,   549,   576,   605,   609,
     615,   623,   631,   640,   648,   656,   665,   675,   684,   695,
     705,   716,   732,   741,   750,   760,   769,   778,   788,   799,
     809,   820,   830,   841,   857,   862,   867,   873,   878,   883,
     889,   902,   916,   929,   943,   955,   960,   965,   970,   975,
     980,   985,   990,   995,  1016,  1018,  1020,  1022,  1024,  1026,
    1028,  1030,  1032,  1034,  1036,  1038,  1056,  1060,  1062,  1064,
    1066,  1074,  1076,  1078,  1080,  1082,  1084,  1086,  1088,  1090,
    1092,  1094,  1096,  1098,  1100,  1102,  1104,  1106,  1108,  1110,
    1112,  1114,  1116,  1118,  1120,  1122,  1124,  1126,  1128,  1130,
    1132,  1134,  1136,  1138,  1140,  1142,  1144,  1163,  1165,  1167,
    1169,  1171,  1173,  1175,  1177,  1179,  1181,  1183,  1185,  1187,
    1189,  1191,  1193,  1195,  1197,  1199,  1201,  1203,  1205,  1207,
    1209,  1211,  1213,  1215,  1217,  1219,  1221,  1223,  1225,  1227,
    1229,  1231,  1233,  1235,  1237
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "INTEGER", "DOUBLE", "MONOM",
  "NAME", "NAME_POLYXYZ", "NAME_MONOM", "NAME_DOUBLE", "NAME_INTEGER",
  "NAME_STRING", "NAME_COMMAND", "NAME_LABEL", "TYPE_POLYXYZ",
  "TYPE_MONOM", "TYPE_DOUBLE", "TYPE_INTEGER", "TYPE_STRING", "IF", "GOTO",
  "EQUAL", "NOTEQUAL", "BIGGER", "BIGGERTHAN", "SMALLER", "SMALLERTHAN",
  "AND", "OR", "ITOSTR", "ITOSTRN", "ITOASC", "ITOASCN", "SQRT", "SINUS",
  "COSINUS", "TANGENS", "COTANGENS", "POWER", "ARCUS_SINUS",
  "ARCUS_COSINUS", "ARCUS_TANGENS", "ARCUS_COTANGENS", "DEGREE", "LENGTH",
  "HESSE", "HESSIAN_SURFACE", "HESSIAN_CURVE", "DIFF", "ROTATE", "X_AXIS",
  "Y_AXIS", "Z_AXIS", "SYSTEM", "INCLUDE", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'^'", "UMINUS", "';'", "':'", "'='", "'('", "')'", "','",
  "$accept", "picture", "statement_list", "label", "include", "statement",
  "s_expression", "p_expression", "m_expression", "d_expression",
  "i_expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    43,    45,    42,    47,
      37,    94,   311,    59,    58,    61,    40,    41,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    69,    70,    71,    71,    71,    71,    71,    71,    72,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    75,    75,    75,    75,    75,    75,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     3,     3,     2,     2,     2,     1,     1,
       2,     1,     2,     2,     4,     4,     4,     4,     3,     3,
       3,     3,     2,     4,     4,     4,     3,     3,     3,     2,
       4,     4,     3,     3,     2,     4,     3,     2,     4,     3,
       6,     2,     3,     1,     4,     4,     6,     6,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     6,     8,     8,     4,     4,
       7,     7,     7,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     3,     3,     4,     4,
       6,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     1,     1,     3,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     0,     0,    11,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       8,     0,     0,     0,     0,     0,     0,    13,    22,    29,
      34,    37,     0,    41,    43,     0,     0,     0,     0,    12,
      10,     1,     0,     5,     0,     7,     6,   183,   145,   104,
      93,   105,   146,   184,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    19,    20,    21,     0,     0,     0,
      26,    27,    28,     0,     0,     0,    32,    33,     0,    36,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,   103,   144,   182,    83,   102,   143,
     181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,   144,   182,   102,   143,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,   182,   143,   181,
       0,     0,     0,     0,    14,    15,    16,    17,    23,    24,
      25,    30,    31,    35,    38,     0,     0,     0,     0,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,   106,   107,
     147,    49,    50,    51,    52,    61,    62,    63,    64,    73,
      74,    75,    76,    80,    81,    82,    53,    56,    57,    58,
      65,    68,    69,    70,    77,    94,    96,    95,   100,    99,
     101,   158,   170,   159,   171,   160,   172,   161,   173,   162,
     174,   163,   175,    54,    59,   127,   128,    66,    71,   130,
     131,    78,    98,   133,   134,   136,   137,   140,   141,   164,
     152,   165,   153,   166,   154,   167,   155,   168,   156,   169,
     157,   150,   151,    55,    60,   129,   176,    67,    72,   132,
     177,    79,    97,   135,   178,   138,   139,   179,   142,   180,
      94,    96,    95,   127,   128,   130,   131,    98,   133,   134,
     129,   176,   132,   177,    97,   135,   178,   133,   134,   135,
     178,     0,    44,     0,    45,     0,   108,   109,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,   120,   121,
     122,   123,   124,   125,   126,   148,   149,    89,    88,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,    46,
      47,   110,    85,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    86,    87
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    39,    73,   120,    88,
     122
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -62
static const short int yypact[] =
{
      10,   -61,   -56,   -54,   -50,   -49,   -62,   -62,     5,    40,
      46,    51,    52,     2,    66,    76,    76,    81,    10,    33,
     -62,    41,   438,   492,   534,   534,    76,    45,   103,   107,
     109,   117,   534,   -62,   -62,   118,   127,   136,   140,    55,
      55,   -62,   119,   -62,   110,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   141,   142,   150,   162,   163,   179,
     180,   181,   186,   204,   222,   223,   228,   230,   254,   438,
     438,   438,   438,   317,   394,  1316,  1260,   492,   492,   492,
     -53,  1322,  1300,   534,   534,   534,  1328,  1308,  1328,  1308,
      55,   438,   492,   534,   534,   196,   198,   534,   534,   534,
     534,    76,   -62,   -62,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   438,   438,   438,   438,   438,    44,
     394,  1316,  1260,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   108,   592,  1086,   666,   438,   438,   438,   534,   534,
     438,   438,   438,   534,   534,   534,   534,   534,   534,   534,
     534,   438,   438,   438,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   438,   438,   438,   534,   534,   534,
     -62,   -62,   -62,   -62,   -62,   -62,    -7,  1093,   678,   492,
     534,   534,   492,   534,   534,   492,   -62,   -62,   -62,   -62,
    1100,   690,   534,   534,   317,   394,  1316,  1260,   -53,  1322,
    1300,  1328,  1308,  1308,   -62,   313,   736,   494,   748,   558,
     -62,  1107,   760,  1114,   806,  1160,   818,  1167,   830,  1174,
     876,   605,  1308,  1181,   888,  1188,   900,  1234,   946,  1241,
     958,  1334,  1341,  1348,  1355,   192,   534,   -62,   -62,   -62,
     -62,   271,   377,   154,   364,   271,   377,   154,   364,   274,
     287,   290,    13,   290,    13,   439,   271,   377,   154,   364,
     271,   377,   154,   364,   274,   287,   290,    13,   290,    13,
     439,   450,   243,   450,   243,   450,   243,   450,   243,   450,
     243,   450,   243,   271,   377,   432,   -15,   271,   377,   432,
     -15,   274,   287,   288,    38,   288,   289,   -62,   -62,   450,
     243,   450,   243,   450,   243,   450,   243,   450,   243,   450,
     243,   129,   129,   271,   377,   432,    35,   271,   377,   432,
      35,   274,   287,   288,   289,   288,   289,   289,   -62,   -62,
     287,   373,   299,   454,   282,   454,   282,   287,   288,    38,
     454,   282,   454,   282,   287,   288,   289,   288,   289,   288,
     289,   347,   -62,   534,   -62,   534,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   534,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   492,
     619,   -62,   970,  1016,  1248,   133,  1322,   579,   -19,   -62,
     -62,   -62,   -62,   534,   534,   296,   297,   298,  1028,  1040,
     -62,   -62,   -62,   -62,   -62
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
     -62,   -62,   -62,   350,   351,   352,    -9,   267,   275,   126,
     -22
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short int yytable[] =
{
      76,    82,    87,    89,    22,   179,   143,    40,   144,    23,
      96,    24,    27,   162,   163,    25,    26,    90,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,   395,   396,   397,   156,   157,   158,   159,   160,
     161,   162,   163,   166,   167,   168,   169,    28,   126,   130,
     134,   179,   143,    29,   144,   172,   175,   178,    30,    31,
     238,   187,   189,   191,    15,    16,   162,   163,    32,   197,
     200,   202,   203,   168,   169,   206,   207,   208,   209,    34,
      33,    41,   212,   214,   216,   218,   220,   222,   224,   226,
     228,   230,   210,   166,   167,   168,   169,    45,   168,   169,
     135,   136,   137,   138,    46,   139,    35,    36,    37,    38,
      91,   101,   236,   244,   248,   252,   254,   255,   259,   263,
     267,   269,   270,   272,   274,   276,   278,   280,   282,   286,
     290,   294,   296,   298,   300,   302,   304,   306,   308,   310,
     311,   312,   316,   320,   324,   326,   327,   329,    75,    81,
      86,   156,   157,   158,   159,   160,   161,   332,   334,   336,
     339,   341,   343,   346,   135,   136,   137,   138,    92,   139,
     348,   350,    93,   103,    94,   237,   145,   146,   147,   148,
     149,   150,    95,   102,    97,   183,   184,   193,   167,   168,
     169,   179,   143,    98,   144,   121,   125,   129,   133,   204,
     392,   393,    99,   171,   174,   177,   100,   104,   105,   186,
     188,   190,   153,   154,   222,   155,   106,   196,   199,   201,
     156,   157,   158,   159,   160,   161,   162,   163,   107,   108,
     211,   213,   215,   217,   219,   221,   223,   225,   227,   229,
     121,   121,   121,   121,   121,   109,   110,   111,   135,   136,
     137,   138,   112,   139,   183,   184,   193,   167,   168,   169,
     379,   243,   247,   251,   253,   205,   258,   262,   266,   268,
     113,   271,   273,   275,   277,   279,   281,   285,   289,   293,
     295,   297,   299,   301,   303,   305,   307,   309,   114,   115,
     315,   319,   323,   325,   116,   328,   117,    74,    80,   183,
     184,   193,   167,   168,   169,   331,   333,   335,   338,   340,
     342,   345,   145,   146,   147,   148,   149,   150,   347,   349,
     118,   156,   157,   158,   159,   160,   161,   162,   163,   137,
     138,   382,   139,   383,   351,   139,   119,   123,   127,   131,
     193,   167,   168,   169,   222,   124,   128,   132,   144,   155,
     169,   155,   170,   173,   176,   183,   184,   387,   194,   168,
     169,   381,   380,   400,   401,   402,   195,   198,    42,    43,
      44,   398,   399,   135,   136,   137,   138,     0,   139,     0,
       0,   231,   232,   233,   234,   235,   156,   157,   158,   159,
     160,   161,   162,   163,     0,   145,   146,   147,   148,   149,
     150,     0,   241,   245,   249,     0,     0,   256,   260,   264,
     242,   246,   250,     0,     0,   257,   261,   265,   283,   287,
     291,     0,   166,   167,   168,   169,   284,   288,   292,   180,
     181,   313,   317,   321,   155,   142,   143,     0,   144,   314,
     318,   322,    47,    48,    49,     0,    50,    51,    52,    53,
     140,   141,   142,   143,   330,   144,     0,   337,     0,     0,
     344,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,    66,    67,    68,    69,     0,
     153,   154,   384,   155,    70,    71,    47,    48,    49,   168,
       0,    51,    52,    53,    72,   386,   180,   181,   192,   154,
       0,   155,   192,   154,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,     0,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    47,    48,
       0,     0,     0,     0,    52,    53,     0,     0,    77,    78,
     183,   184,   193,   167,   168,   169,     0,     0,    79,     0,
       0,     0,   353,     0,     0,     0,     0,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     156,   157,   158,   159,   160,   161,   162,   163,     0,     0,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      85,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,   183,   184,   193,   167,   168,   169,
       0,     0,     0,     0,     0,     0,   355,   145,   146,   147,
     148,   149,   150,     0,     0,   183,   184,   185,   167,   168,
     169,   145,   146,   147,   148,   149,   150,   394,   140,   141,
     142,   143,     0,   144,   385,     0,     0,     0,     0,   238,
       0,   180,   181,   192,   154,     0,   155,     0,     0,     0,
       0,     0,     0,   366,     0,   180,   181,   192,   154,     0,
     155,     0,     0,     0,     0,     0,     0,   388,   156,   157,
     158,   159,   160,   161,   162,   163,     0,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,     0,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
       0,     0,   164,   165,   166,   167,   168,   169,     0,     0,
       0,     0,     0,   240,   183,   184,   185,   167,   168,   169,
       0,     0,     0,     0,     0,   240,   183,   184,   193,   167,
     168,   169,     0,     0,     0,     0,     0,   240,   156,   157,
     158,   159,   160,   161,   162,   163,     0,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,     0,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
       0,     0,   183,   184,   193,   167,   168,   169,     0,     0,
       0,     0,     0,   352,   183,   184,   193,   167,   168,   169,
       0,     0,     0,     0,     0,   354,   183,   184,   193,   167,
     168,   169,     0,     0,     0,     0,     0,   357,   156,   157,
     158,   159,   160,   161,   162,   163,     0,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,     0,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
       0,     0,   183,   184,   193,   167,   168,   169,     0,     0,
       0,     0,     0,   359,   183,   184,   193,   167,   168,   169,
       0,     0,     0,     0,     0,   361,   183,   184,   193,   167,
     168,   169,     0,     0,     0,     0,     0,   363,   156,   157,
     158,   159,   160,   161,   162,   163,     0,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,     0,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
       0,     0,   183,   184,   193,   167,   168,   169,     0,     0,
       0,     0,     0,   365,   183,   184,   193,   167,   168,   169,
       0,     0,     0,     0,     0,   368,   183,   184,   193,   167,
     168,   169,     0,     0,     0,     0,     0,   370,   156,   157,
     158,   159,   160,   161,   162,   163,     0,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,     0,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
       0,     0,   183,   184,   193,   167,   168,   169,     0,     0,
       0,     0,     0,   372,   183,   184,   193,   167,   168,   169,
       0,     0,     0,     0,     0,   374,   183,   184,   193,   167,
     168,   169,     0,     0,     0,     0,     0,   389,   156,   157,
     158,   159,   160,   161,   162,   163,     0,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,     0,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
       0,     0,   183,   184,   193,   167,   168,   169,     0,     0,
       0,     0,     0,   390,   183,   184,   193,   167,   168,   169,
       0,     0,     0,     0,     0,   403,   183,   184,   193,   167,
     168,   169,     0,     0,     0,     0,     0,   404,   145,   146,
     147,   148,   149,   150,     0,   145,   146,   147,   148,   149,
     150,     0,   145,   146,   147,   148,   149,   150,     0,   145,
     146,   147,   148,   149,   150,     0,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,   155,     0,   180,
     181,   182,   154,   239,   155,     0,   180,   181,   192,   154,
     239,   155,     0,   180,   181,   192,   154,   239,   155,     0,
     180,   181,   192,   154,   356,   155,     0,     0,     0,     0,
       0,   358,   145,   146,   147,   148,   149,   150,     0,   145,
     146,   147,   148,   149,   150,     0,   145,   146,   147,   148,
     149,   150,     0,   145,   146,   147,   148,   149,   150,     0,
     145,   146,   147,   148,   149,   150,   180,   181,   192,   154,
       0,   155,     0,   180,   181,   192,   154,   360,   155,     0,
     180,   181,   192,   154,   362,   155,     0,   180,   181,   192,
     154,   364,   155,     0,   180,   181,   192,   154,   367,   155,
       0,     0,     0,     0,     0,   369,   145,   146,   147,   148,
     149,   150,     0,   145,   146,   147,   148,   149,   150,     0,
     145,   146,   147,   148,   149,   150,     0,     0,     0,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     180,   181,   192,   154,     0,   155,     0,   180,   181,   192,
     154,   371,   155,     0,   180,   181,   192,   154,   373,   155,
       0,     0,     0,     0,     0,   391,   164,   165,   166,   167,
     168,   169,   156,   157,   158,   159,   160,   161,   162,   163,
     156,   157,   158,   159,   160,   161,   162,   163,   145,   146,
     147,   148,   149,   150,   145,   146,   147,   148,   149,   150,
     145,   146,   147,   148,   149,   150,   183,   184,   185,   167,
     168,   169,     0,     0,   183,   184,   193,   167,   168,   169,
       0,     0,   151,   152,   153,   154,     0,   155,   180,   181,
     182,   154,     0,   155,   180,   181,   192,   154,     0,   155,
     135,   136,   137,   138,     0,   139,     0,   135,   136,   137,
     138,   375,   139,     0,   135,   136,   137,   138,   376,   139,
       0,   135,   136,   137,   138,   377,   139,     0,     0,     0,
       0,     0,   378
};

static const short int yycheck[] =
{
      22,    23,    24,    25,    65,    58,    59,    16,    61,    65,
      32,    65,     7,    28,    29,    65,    65,    26,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    51,    52,    53,    22,    23,    24,    25,    26,
      27,    28,    29,    58,    59,    60,    61,     7,    70,    71,
      72,    58,    59,     7,    61,    77,    78,    79,     7,     7,
      67,    83,    84,    85,    54,    55,    28,    29,    66,    91,
      92,    93,    94,    60,    61,    97,    98,    99,   100,     3,
      14,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   101,    58,    59,    60,    61,    64,    60,    61,
      56,    57,    58,    59,    63,    61,    30,    31,    32,    33,
      65,    56,    68,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    22,    23,
      24,    22,    23,    24,    25,    26,    27,   179,   180,   181,
     182,   183,   184,   185,    56,    57,    58,    59,    65,    61,
     192,   193,    65,    63,    65,    67,    22,    23,    24,    25,
      26,    27,    65,    64,    66,    56,    57,    58,    59,    60,
      61,    58,    59,    66,    61,    69,    70,    71,    72,     3,
      67,    68,    66,    77,    78,    79,    66,    66,    66,    83,
      84,    85,    58,    59,   236,    61,    66,    91,    92,    93,
      22,    23,    24,    25,    26,    27,    28,    29,    66,    66,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    66,    66,    66,    56,    57,
      58,    59,    66,    61,    56,    57,    58,    59,    60,    61,
      68,   135,   136,   137,   138,    67,   140,   141,   142,   143,
      66,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    66,    66,
     164,   165,   166,   167,    66,   169,    66,    22,    23,    56,
      57,    58,    59,    60,    61,   179,   180,   181,   182,   183,
     184,   185,    22,    23,    24,    25,    26,    27,   192,   193,
      66,    22,    23,    24,    25,    26,    27,    28,    29,    58,
      59,   353,    61,   355,    21,    61,    69,    70,    71,    72,
      58,    59,    60,    61,   366,    70,    71,    72,    61,    61,
      61,    61,    77,    78,    79,    56,    57,   379,    91,    60,
      61,    14,   236,    67,    67,    67,    91,    92,    18,    18,
      18,   393,   394,    56,    57,    58,    59,    -1,    61,    -1,
      -1,   114,   115,   116,   117,   118,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    22,    23,    24,    25,    26,
      27,    -1,   135,   136,   137,    -1,    -1,   140,   141,   142,
     135,   136,   137,    -1,    -1,   140,   141,   142,   151,   152,
     153,    -1,    58,    59,    60,    61,   151,   152,   153,    56,
      57,   164,   165,   166,    61,    58,    59,    -1,    61,   164,
     165,   166,     4,     5,     6,    -1,     8,     9,    10,    11,
      56,    57,    58,    59,   179,    61,    -1,   182,    -1,    -1,
     185,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    50,    -1,
      58,    59,   366,    61,    56,    57,     4,     5,     6,    60,
      -1,     9,    10,    11,    66,   379,    56,    57,    58,    59,
      -1,    61,    58,    59,    -1,    61,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     4,     5,
      -1,    -1,    -1,    -1,    10,    11,    -1,    -1,    56,    57,
      56,    57,    58,    59,    60,    61,    -1,    -1,    66,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    22,    23,    24,
      25,    26,    27,    -1,    -1,    56,    57,    58,    59,    60,
      61,    22,    23,    24,    25,    26,    27,    68,    56,    57,
      58,    59,    -1,    61,   379,    -1,    -1,    -1,    -1,    67,
      -1,    56,    57,    58,    59,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    56,    57,    58,    59,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    67,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    67,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    67,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    67,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    67,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    67,    22,    23,
      24,    25,    26,    27,    -1,    22,    23,    24,    25,    26,
      27,    -1,    22,    23,    24,    25,    26,    27,    -1,    22,
      23,    24,    25,    26,    27,    -1,    22,    23,    24,    25,
      26,    27,    56,    57,    58,    59,    -1,    61,    -1,    56,
      57,    58,    59,    67,    61,    -1,    56,    57,    58,    59,
      67,    61,    -1,    56,    57,    58,    59,    67,    61,    -1,
      56,    57,    58,    59,    67,    61,    -1,    -1,    -1,    -1,
      -1,    67,    22,    23,    24,    25,    26,    27,    -1,    22,
      23,    24,    25,    26,    27,    -1,    22,    23,    24,    25,
      26,    27,    -1,    22,    23,    24,    25,    26,    27,    -1,
      22,    23,    24,    25,    26,    27,    56,    57,    58,    59,
      -1,    61,    -1,    56,    57,    58,    59,    67,    61,    -1,
      56,    57,    58,    59,    67,    61,    -1,    56,    57,    58,
      59,    67,    61,    -1,    56,    57,    58,    59,    67,    61,
      -1,    -1,    -1,    -1,    -1,    67,    22,    23,    24,    25,
      26,    27,    -1,    22,    23,    24,    25,    26,    27,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      56,    57,    58,    59,    -1,    61,    -1,    56,    57,    58,
      59,    67,    61,    -1,    56,    57,    58,    59,    67,    61,
      -1,    -1,    -1,    -1,    -1,    67,    56,    57,    58,    59,
      60,    61,    22,    23,    24,    25,    26,    27,    28,    29,
      22,    23,    24,    25,    26,    27,    28,    29,    22,    23,
      24,    25,    26,    27,    22,    23,    24,    25,    26,    27,
      22,    23,    24,    25,    26,    27,    56,    57,    58,    59,
      60,    61,    -1,    -1,    56,    57,    58,    59,    60,    61,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    56,    57,
      58,    59,    -1,    61,    56,    57,    58,    59,    -1,    61,
      56,    57,    58,    59,    -1,    61,    -1,    56,    57,    58,
      59,    67,    61,    -1,    56,    57,    58,    59,    67,    61,
      -1,    56,    57,    58,    59,    67,    61,    -1,    -1,    -1,
      -1,    -1,    67
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    54,    55,    70,    71,    72,
      73,    74,    65,    65,    65,    65,    65,     7,     7,     7,
       7,     7,    66,    14,     3,    30,    31,    32,    33,    75,
      75,     0,    72,    73,    74,    64,    63,     4,     5,     6,
       8,     9,    10,    11,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    47,    48,    49,    50,
      56,    57,    66,    76,    77,    78,    79,    56,    57,    66,
      77,    78,    79,    56,    57,    66,    78,    79,    78,    79,
      75,    65,    65,    65,    65,    65,    79,    66,    66,    66,
      66,    56,    64,    63,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    76,
      77,    78,    79,    76,    77,    78,    79,    76,    77,    78,
      79,    76,    77,    78,    79,    56,    57,    58,    59,    61,
      56,    57,    58,    59,    61,    22,    23,    24,    25,    26,
      27,    56,    57,    58,    59,    61,    22,    23,    24,    25,
      26,    27,    28,    29,    56,    57,    58,    59,    60,    61,
      77,    78,    79,    77,    78,    79,    77,    78,    79,    58,
      56,    57,    58,    56,    57,    58,    78,    79,    78,    79,
      78,    79,    58,    58,    76,    77,    78,    79,    77,    78,
      79,    78,    79,    79,     3,    67,    79,    79,    79,    79,
      75,    78,    79,    78,    79,    78,    79,    78,    79,    78,
      79,    78,    79,    78,    79,    78,    79,    78,    79,    78,
      79,    76,    76,    76,    76,    76,    68,    67,    67,    67,
      67,    76,    77,    78,    79,    76,    77,    78,    79,    76,
      77,    78,    79,    78,    79,    79,    76,    77,    78,    79,
      76,    77,    78,    79,    76,    77,    78,    79,    78,    79,
      79,    78,    79,    78,    79,    78,    79,    78,    79,    78,
      79,    78,    79,    76,    77,    78,    79,    76,    77,    78,
      79,    76,    77,    78,    79,    78,    79,    78,    79,    78,
      79,    78,    79,    78,    79,    78,    79,    78,    79,    78,
      79,    79,    79,    76,    77,    78,    79,    76,    77,    78,
      79,    76,    77,    78,    79,    78,    79,    79,    78,    79,
      77,    78,    79,    78,    79,    78,    79,    77,    78,    79,
      78,    79,    78,    79,    77,    78,    79,    78,    79,    78,
      79,    21,    67,    68,    67,    68,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    68,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      78,    14,    79,    79,    78,    77,    78,    79,    68,    67,
      67,    67,    67,    68,    68,    51,    52,    53,    79,    79,
      67,    67,    67,    67,    67
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;


  yyvsp[0] = yylval;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 9:
#line 152 "polyyacc.y"
    {
                            if( (yyvsp[0].sym)->type != SYM_UNSPEC &&
                                (yyvsp[0].sym)->type != SYM_LABEL )
			    {
                                yyerror( "name already in use" );
		     	    }
                            else if( (yyvsp[0].sym)->type == SYM_UNSPEC )
                            {

                                yyerror( "label not scanned" );

                                /* -------------------------- */
                                /* determine label adress ... */
                                /* -------------------------- */

                                /*  now done when scnning labels
                                int     i = 0;
                                extern char *main_formula_data;

                                $1->type = SYM_LABEL;
                                
                                while( main_formula_data[$1->label-1+i] 
                                       != ':' )
                                {
                                    if( main_formula_data[$1->label-1+i] 
                                        == '\n' )
                                    {
                                        $1->lineno++;
				    }
                                    i++;
			        }

                                $1->label = $1->label+i;
                                */
			    }
		        }
    break;

  case 10:
#line 191 "polyyacc.y"
    {
                            printf( "%s\n",(yyvsp[0].str) );
			}
    break;

  case 11:
#line 196 "polyyacc.y"
    {
                            if( surface_run_commands && !thread_should_stop())
                            {
                                ((f_v_v_p)(yyvsp[0].sym)->ptr)( );
                            }
                        }
    break;

  case 12:
#line 203 "polyyacc.y"
    {
				if( surface_run_commands && !thread_should_stop()) {
					thread_set_doing ("executing system command", -1.0);
					system ((yyvsp[0].str));
				}
			}
    break;

  case 13:
#line 210 "polyyacc.y"
    {
                            (yyvsp[0].sym)->type = SYM_POLYXYZ;
                            (yyvsp[0].sym)->p    = NULLPOLYXYZ;
                        }
    break;

  case 14:
#line 215 "polyyacc.y"
    {
                            (yyvsp[-2].sym)->type = SYM_POLYXYZ;
                            (yyvsp[-2].sym)->p    = (yyvsp[0].p);
                        }
    break;

  case 15:
#line 220 "polyyacc.y"
    {
                            (yyvsp[-2].sym)->type = SYM_POLYXYZ;
                            (yyvsp[-2].sym)->p    = monxyz2polyxyz( &(yyvsp[0].mon) );
                        }
    break;

  case 16:
#line 225 "polyyacc.y"
    {
                            (yyvsp[-2].sym)->type = SYM_POLYXYZ;
                            (yyvsp[-2].sym)->p    = double2polyxyz( (yyvsp[0].dval) );
                        }
    break;

  case 17:
#line 230 "polyyacc.y"
    {
                            (yyvsp[-2].sym)->type = SYM_POLYXYZ;
                            (yyvsp[-2].sym)->p    = int2polyxyz( (yyvsp[0].ival) );
                        }
    break;

  case 18:
#line 235 "polyyacc.y"
    {
                            if( (yyvsp[-2].sym)->surface )
                            {
                                if( (yyvsp[-2].sym)->constant )
                                {
                                    yyerror( "cannot assign to a constant" );
                                }
                                else
                                {
                                    delete_coeff_polyxyz_control(
                                            (polyxyz*)(yyvsp[-2].sym)->ptr );
                                    *((polyxyz*)(yyvsp[-2].sym)->ptr) = (yyvsp[0].p);
                                }
                            }
                            else
                            {
                                delete_coeff_polyxyz_control( &(yyvsp[-2].sym)->p );
                                (yyvsp[-2].sym)->p = (yyvsp[0].p);
                            }
                        }
    break;

  case 19:
#line 256 "polyyacc.y"
    {
                            if( (yyvsp[-2].sym)->surface )
                            {
                                if( (yyvsp[-2].sym)->constant )
                                {
                                    yyerror( "cannot assign to a constant" );
                                }
                                else
                                {
                                    delete_coeff_polyxyz_control(
                                            (polyxyz*)(yyvsp[-2].sym)->ptr );
                                    *((polyxyz*)(yyvsp[-2].sym)->ptr) = monxyz2polyxyz( &(yyvsp[0].mon) );
                                }
                            }
                            else
                            {
                                delete_coeff_polyxyz_control( &(yyvsp[-2].sym)->p );
                                (yyvsp[-2].sym)->p = monxyz2polyxyz( &(yyvsp[0].mon) );
                            }
                        }
    break;

  case 20:
#line 277 "polyyacc.y"
    {
                            if( (yyvsp[-2].sym)->surface )
                            {
                                if( (yyvsp[-2].sym)->constant )
                                {
                                    yyerror( "cannot assign to a constant" );
                                }
                                else
                                {
                                    delete_coeff_polyxyz_control(
                                            (polyxyz*)(yyvsp[-2].sym)->ptr );
                                    *((polyxyz*)(yyvsp[-2].sym)->ptr) = double2polyxyz( (yyvsp[0].dval) );
                                }
                            }
                            else
                            {
                                delete_coeff_polyxyz_control( &(yyvsp[-2].sym)->p );
                                (yyvsp[-2].sym)->p = double2polyxyz( (yyvsp[0].dval) );
                            }
                        }
    break;

  case 21:
#line 298 "polyyacc.y"
    {
                            if( (yyvsp[-2].sym)->surface )
                            {
                                if( (yyvsp[-2].sym)->constant )
                                {
                                    yyerror( "cannot assign to a constant" );
                                }
                                else
                                {
                                    delete_coeff_polyxyz_control(
                                            (polyxyz*)(yyvsp[-2].sym)->ptr );
                                    *((polyxyz*)(yyvsp[-2].sym)->ptr) = int2polyxyz( (yyvsp[0].ival) );
                                }
                            }
                            else
                            {
                                delete_coeff_polyxyz_control( &(yyvsp[-2].sym)->p );
                                (yyvsp[-2].sym)->p = int2polyxyz( (yyvsp[0].ival) );
                            }
                        }
    break;

  case 22:
#line 320 "polyyacc.y"
    {
                            (yyvsp[0].sym)->type = SYM_MONOM;
                            (yyvsp[0].sym)->mon  = NULLMONXYZ;
                        }
    break;

  case 23:
#line 325 "polyyacc.y"
    {
                            (yyvsp[-2].sym)->type = SYM_MONOM;
                            (yyvsp[-2].sym)->mon  = (yyvsp[0].mon);
                        }
    break;

  case 24:
#line 330 "polyyacc.y"
    {
                            (yyvsp[-2].sym)->type = SYM_MONOM;
                            (yyvsp[-2].sym)->mon  = double2monxyz( (yyvsp[0].dval) );
                        }
    break;

  case 25:
#line 335 "polyyacc.y"
    {
                            (yyvsp[-2].sym)->type = SYM_MONOM;
                            (yyvsp[-2].sym)->mon  = int2monxyz( (yyvsp[0].ival) );
                        }
    break;

  case 26:
#line 340 "polyyacc.y"
    {
                            if( (yyvsp[-2].sym)->surface )
                            {
                                if( (yyvsp[-2].sym)->constant )
                                {
                                    yyerror( "cannot assign to a constant" );
                                }
                                *((monxyz*)(yyvsp[-2].sym)->ptr) = (yyvsp[0].mon);
                            }
                            else
                            {
                                (yyvsp[-2].sym)->mon  = (yyvsp[0].mon);
                            }
                        }
    break;

  case 27:
#line 355 "polyyacc.y"
    {
                            if( (yyvsp[-2].sym)->surface )
                            {
                                if( (yyvsp[-2].sym)->constant )
                                {
                                    yyerror( "cannot assign to a constant" );
                                }
                                *((monxyz*)(yyvsp[-2].sym)->ptr) = double2monxyz( (yyvsp[0].dval) );
                            }
                            else
                            {
                                (yyvsp[-2].sym)->mon  = double2monxyz( (yyvsp[0].dval) );
                            }
                        }
    break;

  case 28:
#line 370 "polyyacc.y"
    {
                            if( (yyvsp[-2].sym)->surface )
                            {
                                if( (yyvsp[-2].sym)->constant )
                                {
                                    yyerror( "cannot assign to a constant" );
                                }
                                *((monxyz*)(yyvsp[-2].sym)->ptr) = int2monxyz( (yyvsp[0].ival) );
                            }
                            else
                            {
                            (yyvsp[-2].sym)->mon  = int2monxyz( (yyvsp[0].ival) );
                            }
                        }
    break;

  case 29:
#line 386 "polyyacc.y"
    {
                            (yyvsp[0].sym)->type = SYM_DOUBLE;
                            (yyvsp[0].sym)->dval = 0.0;
                        }
    break;

  case 30:
#line 391 "polyyacc.y"
    {
                            (yyvsp[-2].sym)->type = SYM_DOUBLE;
                            (yyvsp[-2].sym)->dval = (yyvsp[0].dval);
                        }
    break;

  case 31:
#line 396 "polyyacc.y"
    {
                            (yyvsp[-2].sym)->type = SYM_DOUBLE;
                            (yyvsp[-2].sym)->dval = (double)(yyvsp[0].ival);
                        }
    break;

  case 32:
#line 401 "polyyacc.y"
    {
                            if( (yyvsp[-2].sym)->surface )
                            {
                                if( (yyvsp[-2].sym)->constant )
                                {
                                    yyerror( "cannot assign to a constant" );
                                }
                                *((double*)(yyvsp[-2].sym)->ptr) = (yyvsp[0].dval);
                            }
                            else
                            {
                                (yyvsp[-2].sym)->dval = (yyvsp[0].dval);
                            }
                        }
    break;

  case 33:
#line 416 "polyyacc.y"
    {
                            if( (yyvsp[-2].sym)->surface )
                            {
                                if( (yyvsp[-2].sym)->constant )
                                {
                                    yyerror( "cannot assign to a constant" );
                                }
                                *((double*)(yyvsp[-2].sym)->ptr) = (double)(yyvsp[0].ival);
                            }
                            else
                            {
                                (yyvsp[-2].sym)->dval = (double)(yyvsp[0].ival);
                            }
                        }
    break;

  case 34:
#line 432 "polyyacc.y"
    {
                            (yyvsp[0].sym)->type = SYM_INTEGER;
                            (yyvsp[0].sym)->ival = 0;
                        }
    break;

  case 35:
#line 437 "polyyacc.y"
    {
                            (yyvsp[-2].sym)->type = SYM_INTEGER;
                            (yyvsp[-2].sym)->ival = (yyvsp[0].ival);
                        }
    break;

  case 36:
#line 442 "polyyacc.y"
    {
                            if( (yyvsp[-2].sym)->surface )
                            {
                                if( (yyvsp[-2].sym)->constant )
                                {
                                    yyerror( "cannot assign to a constant" );
                                }
                                *((int*)(yyvsp[-2].sym)->ptr) = (yyvsp[0].ival);
                            }
                            else
                            {
                                (yyvsp[-2].sym)->ival = (yyvsp[0].ival);
                            }
                        }
    break;

  case 37:
#line 458 "polyyacc.y"
    {
                            (yyvsp[0].sym)->type = SYM_STRING;
                        }
    break;

  case 38:
#line 462 "polyyacc.y"
    {
                            (yyvsp[-2].sym)->type = SYM_STRING;
                            (yyvsp[-2].sym)->str  = (yyvsp[0].str);
                        }
    break;

  case 39:
#line 467 "polyyacc.y"
    {
                            if( (yyvsp[-2].sym)->surface )
                            {
                                if( (yyvsp[-2].sym)->constant )
                                {
                                    yyerror( "cannot assign to a constant" );
                                }
                                else
                                {
                                    delete_char ( *((char**)(yyvsp[-2].sym)->ptr) );
                                    *((char**)(yyvsp[-2].sym)->ptr) = (yyvsp[0].str);
                                }
                            }
                            else
                            {
                                delete_char ( (yyvsp[-2].sym)->str );
                                (yyvsp[-2].sym)->str = (yyvsp[0].str);
                            }
                        }
    break;

  case 40:
#line 487 "polyyacc.y"
    {
                            if( (yyvsp[-3].ival) == TRUE )
                            {
				goto_label  = (yyvsp[0].sym)->label;
                                goto_line   = (yyvsp[0].sym)->lineno;
                                goto_flag   = TRUE;
                                YYACCEPT;
			    }
                        }
    break;

  case 41:
#line 497 "polyyacc.y"
    {
				goto_label  = (yyvsp[0].sym)->label;
                                goto_line   = (yyvsp[0].sym)->lineno;
                                goto_flag   = TRUE;
                                YYACCEPT;
                        }
    break;

  case 42:
#line 506 "polyyacc.y"
    {
                            size_t  len1,len2,len;

                            len1 = strlen( (yyvsp[-2].str) );
                            len2 = strlen( (yyvsp[0].str) );
                            len  = len1 + len2;
                            
                            (yyval.str) = new_char( len + 1 );

                            strncpy( (yyval.str),(yyvsp[-2].str),len1 );
                            strncpy( &((yyval.str)[len1]),(yyvsp[0].str),len2 );
                            (yyval.str)[len]='\0';

                            delete_char ( (yyvsp[-2].str) );
                            delete_char ( (yyvsp[0].str) );
			    (yyvsp[-2].str)=(yyvsp[0].str)=0;
			}
    break;

  case 43:
#line 524 "polyyacc.y"
    {
                            (yyval.str) = (yyvsp[0].str);
			}
    break;

  case 44:
#line 528 "polyyacc.y"
    {
                            static  char    buf[50];
                            size_t  length;

                            sprintf( buf,"%d",(yyvsp[-1].ival) );
                            length = strlen( buf );
                            (yyval.str) = new_char( length + 1 );
                            strncpy( (yyval.str),buf,length );
                            (yyval.str)[length] = '\0';
			}
    break;

  case 45:
#line 539 "polyyacc.y"
    {
                            static  char    buf[50];
                            size_t  length;

                            itotexascii( (yyvsp[-1].ival),buf,49 );
                            length = strlen( buf );
                            (yyval.str) = new_char( length + 1 );
                            strncpy( (yyval.str),buf,length );
                            (yyval.str)[length] = '\0';
			}
    break;

  case 46:
#line 550 "polyyacc.y"
    {
                            static  char    buf[50];
                            size_t  length;

                            sprintf( buf,"%d",(yyvsp[-1].ival) );
                            length = strlen( buf );

                            if( (yyvsp[-3].ival) > 50 || (yyvsp[-3].ival) < length )
                            {
                               yyerror( "ridoculous value in itostrn" );
			    }
                            else
                            {
                                int    i,zeroes;
                                zeroes = (yyvsp[-3].ival) - length;

                                (yyval.str) = new_char( (yyvsp[-3].ival) + 1 );

                                for( i=0; i < (yyvsp[-3].ival); i++ )
                                {
                                    (yyval.str)[i] = '0';
			        }
                                strncpy( &((yyval.str)[zeroes]),buf,length );
                                (yyval.str)[(yyvsp[-3].ival)] = '\0';
                            }
                        }
    break;

  case 47:
#line 577 "polyyacc.y"
    {
                            static  char    buf[50];
                            size_t  length;

                            itotexascii( (yyvsp[-1].ival),buf,49 );
                            length = strlen( buf );

                            if( (yyvsp[-3].ival) > 50 || (yyvsp[-3].ival) < length )
                            {
                               yyerror( "ridoculous value in itoascn" );
			    }
                            else
                            {
                                int    i,zeroes;
                                zeroes = (yyvsp[-3].ival) - length;

                                (yyval.str) = new_char( (yyvsp[-3].ival) + 1 );

                                for( i=0; i < (yyvsp[-3].ival); i++ )
                                {
                                    (yyval.str)[i] = 'a';
			        }
                                strncpy( &((yyval.str)[zeroes]),buf,length );
                                (yyval.str)[(yyvsp[-3].ival)] = '\0';
                            }
                        }
    break;

  case 48:
#line 606 "polyyacc.y"
    {
                            (yyval.p) = (yyvsp[-1].p);
                        }
    break;

  case 49:
#line 610 "polyyacc.y"
    {
                            polyxyz_add_self( &(yyvsp[-2].p),&(yyvsp[0].p) );
                            delete_coeff_polyxyz( &(yyvsp[0].p) );
                            (yyval.p) = (yyvsp[-2].p);
                        }
    break;

  case 50:
#line 616 "polyyacc.y"
    {
                            polyxyz p = monxyz2polyxyz( &(yyvsp[0].mon) );

                            polyxyz_add_self( &(yyvsp[-2].p),&p );
                            delete_coeff_polyxyz( &p );
                            (yyval.p) = (yyvsp[-2].p);
                        }
    break;

  case 51:
#line 624 "polyyacc.y"
    {
                            polyxyz p = double2polyxyz( (yyvsp[0].dval) );

                            polyxyz_add_self( &(yyvsp[-2].p),&p );
                            delete_coeff_polyxyz( &p );
                            (yyval.p) = (yyvsp[-2].p);
                        }
    break;

  case 52:
#line 632 "polyyacc.y"
    {
                            polyxyz p = int2polyxyz( (yyvsp[0].ival) );

                            polyxyz_add_self( &(yyvsp[-2].p),&p );
                            delete_coeff_polyxyz( &p );
                            (yyval.p) = (yyvsp[-2].p);
                        }
    break;

  case 53:
#line 641 "polyyacc.y"
    {
                            polyxyz p = monxyz2polyxyz( &(yyvsp[-2].mon) );

                            polyxyz_add_self( &(yyvsp[0].p),&p );
                            delete_coeff_polyxyz( &p );
                            (yyval.p) = (yyvsp[0].p);
                        }
    break;

  case 54:
#line 649 "polyyacc.y"
    {
                            polyxyz p = double2polyxyz( (yyvsp[-2].dval) );

                            polyxyz_add_self( &(yyvsp[0].p),&p );
                            delete_coeff_polyxyz( &p );
                            (yyval.p) = (yyvsp[0].p);
                        }
    break;

  case 55:
#line 657 "polyyacc.y"
    {
                            polyxyz p = int2polyxyz( (yyvsp[-2].ival) );

                            polyxyz_add_self( &(yyvsp[0].p),&p );
                            delete_coeff_polyxyz( &p );
                            (yyval.p) = (yyvsp[0].p);
                        }
    break;

  case 56:
#line 666 "polyyacc.y"
    {
                            polyxyz p = monxyz2polyxyz( &(yyvsp[-2].mon) );
                            polyxyz q = monxyz2polyxyz( &(yyvsp[0].mon) );

                            polyxyz_add_self( &p,&q );
                            delete_coeff_polyxyz( &q );
                            (yyval.p) = p;
                        }
    break;

  case 57:
#line 676 "polyyacc.y"
    {
                            polyxyz p = monxyz2polyxyz( &(yyvsp[-2].mon) );
                            polyxyz q = double2polyxyz( (yyvsp[0].dval) );

                            polyxyz_add_self( &p,&q );
                            delete_coeff_polyxyz( &q );
                            (yyval.p) = p;
                        }
    break;

  case 58:
#line 685 "polyyacc.y"
    {
                            polyxyz p = monxyz2polyxyz( &(yyvsp[-2].mon) );
                            polyxyz q = int2polyxyz( (yyvsp[0].ival) );

                            (yyval.p) = polyxyz_add( &p,&q );

                            delete_coeff_polyxyz( &p );
                            delete_coeff_polyxyz( &q );
                        }
    break;

  case 59:
#line 696 "polyyacc.y"
    {
                            polyxyz p = double2polyxyz( (yyvsp[-2].dval) );
                            polyxyz q = monxyz2polyxyz( &(yyvsp[0].mon) );

                            (yyval.p) = polyxyz_add( &p,&q );

                            delete_coeff_polyxyz( &p );
                            delete_coeff_polyxyz( &q );
                        }
    break;

  case 60:
#line 706 "polyyacc.y"
    {
                            polyxyz p = int2polyxyz( (yyvsp[-2].ival) );
                            polyxyz q = monxyz2polyxyz( &(yyvsp[0].mon) );

                            (yyval.p) = polyxyz_add( &p,&q );

                            delete_coeff_polyxyz( &p );
                            delete_coeff_polyxyz( &q );
                        }
    break;

  case 61:
#line 717 "polyyacc.y"
    {
                            (yyval.p) = polyxyz_sub( &(yyvsp[-2].p),&(yyvsp[0].p) );

                            if( control )
                            {
                                printf( "calculating p_expression - p_expression\n" );
                                polyxyz_print( &(yyvsp[-2].p) );
                                printf( " - " );
                                polyxyz_print( &(yyvsp[0].p) );
                                printf( "\n" );
                            }

                            delete_coeff_polyxyz( &(yyvsp[-2].p) );
                            delete_coeff_polyxyz( &(yyvsp[0].p) );
                        }
    break;

  case 62:
#line 733 "polyyacc.y"
    {
                            polyxyz p = monxyz2polyxyz( &(yyvsp[0].mon) );

                            (yyval.p) = polyxyz_sub( &(yyvsp[-2].p),&p );

                            delete_coeff_polyxyz( &(yyvsp[-2].p) );
                            delete_coeff_polyxyz( &p );
                        }
    break;

  case 63:
#line 742 "polyyacc.y"
    {
                            polyxyz p = double2polyxyz( (yyvsp[0].dval) );

                            (yyval.p) = polyxyz_sub( &(yyvsp[-2].p),&p );

                            delete_coeff_polyxyz( &(yyvsp[-2].p) );
                            delete_coeff_polyxyz( &p );
                        }
    break;

  case 64:
#line 751 "polyyacc.y"
    {
                            polyxyz p = int2polyxyz( (yyvsp[0].ival) );

                            (yyval.p) = polyxyz_sub( &(yyvsp[-2].p),&p );

                            delete_coeff_polyxyz( &(yyvsp[-2].p) );
                            delete_coeff_polyxyz( &p );
                        }
    break;

  case 65:
#line 761 "polyyacc.y"
    {
                            polyxyz p = monxyz2polyxyz( &(yyvsp[-2].mon) );

                            (yyval.p) = polyxyz_sub( &p,&(yyvsp[0].p) );

                            delete_coeff_polyxyz( &p );
                            delete_coeff_polyxyz( &(yyvsp[0].p) );
                        }
    break;

  case 66:
#line 770 "polyyacc.y"
    {
                            polyxyz p = double2polyxyz( (yyvsp[-2].dval) );

                            (yyval.p) = polyxyz_sub( &p,&(yyvsp[0].p) );

                            delete_coeff_polyxyz( &p );
                            delete_coeff_polyxyz( &(yyvsp[0].p) );
                        }
    break;

  case 67:
#line 779 "polyyacc.y"
    {
                            polyxyz p = int2polyxyz( (yyvsp[-2].ival) );

                            (yyval.p) = polyxyz_sub( &p,&(yyvsp[0].p) );

                            delete_coeff_polyxyz( &p );
                            delete_coeff_polyxyz( &(yyvsp[0].p) );
                        }
    break;

  case 68:
#line 789 "polyyacc.y"
    {
                            polyxyz p = monxyz2polyxyz( &(yyvsp[-2].mon) );
                            polyxyz q = monxyz2polyxyz( &(yyvsp[0].mon) );

                            (yyval.p) = polyxyz_sub( &p,&q );

                            delete_coeff_polyxyz( &p );
                            delete_coeff_polyxyz( &q );
                        }
    break;

  case 69:
#line 800 "polyyacc.y"
    {
                            polyxyz p = monxyz2polyxyz( &(yyvsp[-2].mon) );
                            polyxyz q = double2polyxyz( (yyvsp[0].dval) );

                            (yyval.p) = polyxyz_sub( &p,&q );

                            delete_coeff_polyxyz( &p );
                            delete_coeff_polyxyz( &q );
                        }
    break;

  case 70:
#line 810 "polyyacc.y"
    {
                            polyxyz p = monxyz2polyxyz( &(yyvsp[-2].mon) );
                            polyxyz q = int2polyxyz( (yyvsp[0].ival) );

                            (yyval.p) = polyxyz_sub( &p,&q );

                            delete_coeff_polyxyz( &p );
                            delete_coeff_polyxyz( &q );
                        }
    break;

  case 71:
#line 821 "polyyacc.y"
    {
                            polyxyz p = double2polyxyz( (yyvsp[-2].dval) );
                            polyxyz q = monxyz2polyxyz( &(yyvsp[0].mon) );

                            (yyval.p) = polyxyz_sub( &p,&q );

                            delete_coeff_polyxyz( &p );
                            delete_coeff_polyxyz( &q );
                        }
    break;

  case 72:
#line 831 "polyyacc.y"
    {
                            polyxyz p = int2polyxyz( (yyvsp[-2].ival) );
                            polyxyz q = monxyz2polyxyz( &(yyvsp[0].mon) );

                            (yyval.p) = polyxyz_sub( &p,&q );

                            delete_coeff_polyxyz( &p );
                            delete_coeff_polyxyz( &q );
                        }
    break;

  case 73:
#line 842 "polyyacc.y"
    {
                            (yyval.p) = polyxyz_mult( &(yyvsp[-2].p),&(yyvsp[0].p) );

                            if( control )
                            {
                                printf( "calculating p_expression * p_expression\n" );
                                polyxyz_print( &(yyvsp[-2].p) );
                                printf( " * " );
                                polyxyz_print( &(yyvsp[0].p) );
                                printf( "\n" );
                            }

                            delete_coeff_polyxyz( &(yyvsp[-2].p) );
                            delete_coeff_polyxyz( &(yyvsp[0].p) );
                        }
    break;

  case 74:
#line 858 "polyyacc.y"
    {
                            polyxyz_mult_monxyz_self( &(yyvsp[-2].p),&(yyvsp[0].mon) );
                            (yyval.p) = (yyvsp[-2].p);
                        }
    break;

  case 75:
#line 863 "polyyacc.y"
    {
                            polyxyz_mult_double_self( &(yyvsp[-2].p),(yyvsp[0].dval) );
                            (yyval.p) = (yyvsp[-2].p);
                        }
    break;

  case 76:
#line 868 "polyyacc.y"
    {
                            polyxyz_mult_double_self( &(yyvsp[-2].p),(double)(yyvsp[0].ival) );
                            (yyval.p) = (yyvsp[-2].p);
                        }
    break;

  case 77:
#line 874 "polyyacc.y"
    {
                            polyxyz_mult_monxyz_self( &(yyvsp[0].p),&(yyvsp[-2].mon) );
                            (yyval.p) = (yyvsp[0].p);
                        }
    break;

  case 78:
#line 879 "polyyacc.y"
    {
                            polyxyz_mult_double_self( &(yyvsp[0].p),(yyvsp[-2].dval) );
                            (yyval.p) = (yyvsp[0].p);
                        }
    break;

  case 79:
#line 884 "polyyacc.y"
    {
                            polyxyz_mult_double_self( &(yyvsp[0].p),(double)(yyvsp[-2].ival) );
                            (yyval.p) = (yyvsp[0].p);
                        }
    break;

  case 80:
#line 890 "polyyacc.y"
    {
                            polyxyz_div_double_self( &(yyvsp[-2].p),(yyvsp[0].dval) );

                            if( control )
                            {
                                printf( "calculating p_expression / d_expression\n" );
                                polyxyz_print( &(yyvsp[-2].p) );
                                printf( " / %f\n",(yyvsp[0].dval) );
                            }

                            (yyval.p) = (yyvsp[-2].p);
                        }
    break;

  case 81:
#line 903 "polyyacc.y"
    {
                            polyxyz_div_double_self( &(yyvsp[-2].p),(double)(yyvsp[0].ival) );

                            if( control )
                            {
                                printf( "calculating p_expression / i_expression\n" );
                                polyxyz_print( &(yyvsp[-2].p) );
                                printf( " / %d\n",(yyvsp[0].ival) );
                            }

                            (yyval.p) = (yyvsp[-2].p);
                        }
    break;

  case 82:
#line 917 "polyyacc.y"
    {
                            (yyval.p) = polyxyz_power( &(yyvsp[-2].p),(yyvsp[0].ival) );

                            if( control )
                            {
                                printf( "calculating p_expression ^ INTEGER\n" );
                                polyxyz_print( &(yyvsp[-2].p) );
                                printf( " ^ %d\n",(yyvsp[0].ival) );
                            }

                            delete_coeff_polyxyz( &(yyvsp[-2].p) );
                        }
    break;

  case 83:
#line 930 "polyyacc.y"
    {
                            polyxyz_neg_self( &(yyvsp[0].p) );

                            if( control )
                            {
                                printf( "calculating - p_expression\n" );
                                printf( " - " );
                                polyxyz_print( &(yyvsp[0].p) );
                                printf( "\n" );
                            }
   
                            (yyval.p) = (yyvsp[0].p);
                        }
    break;

  case 84:
#line 944 "polyyacc.y"
    {
                            (yyval.p) = (yyvsp[0].p);

                            if( control )
                            {
                                printf( "calculating + p_expression\n" );
                                printf( " + " );
                                polyxyz_print( &(yyvsp[0].p) );
                                printf( "\n" );
                            }
                        }
    break;

  case 85:
#line 956 "polyyacc.y"
    {
                            polyxyz_dmonxyz_self( &(yyvsp[-3].p),&(yyvsp[-1].mon),0 );
                            (yyval.p) = (yyvsp[-3].p);
                        }
    break;

  case 86:
#line 961 "polyyacc.y"
    {
                            polyxyz_dmonxyz_self( &(yyvsp[-5].p),&(yyvsp[-3].mon),(yyvsp[-1].ival) );
                            (yyval.p) = (yyvsp[-5].p);
                        }
    break;

  case 87:
#line 966 "polyyacc.y"
    {
                            polyxyz_dw_n_self( &(yyvsp[-5].p),(yyvsp[-1].ival) );
                            (yyval.p) = (yyvsp[-5].p);
                        }
    break;

  case 88:
#line 971 "polyyacc.y"
    {
                            polyxyz_hessian_curve_self( &(yyvsp[-1].p) );
                            (yyval.p) = (yyvsp[-1].p);
                        }
    break;

  case 89:
#line 976 "polyyacc.y"
    {
                            polyxyz_hessian_surface_self( &(yyvsp[-1].p) );
                            (yyval.p) = (yyvsp[-1].p);
                        }
    break;

  case 90:
#line 981 "polyyacc.y"
    {
                            polyxyz_rotate_x_self( &(yyvsp[-5].p),(yyvsp[-3].dval) );
                            (yyval.p) = (yyvsp[-5].p);
			}
    break;

  case 91:
#line 986 "polyyacc.y"
    {
                            polyxyz_rotate_y_self( &(yyvsp[-5].p),(yyvsp[-3].dval) );
                            (yyval.p) = (yyvsp[-5].p);
			}
    break;

  case 92:
#line 991 "polyyacc.y"
    {
                            polyxyz_rotate_z_self( &(yyvsp[-5].p),(yyvsp[-3].dval) );
                            (yyval.p) = (yyvsp[-5].p);
			}
    break;

  case 93:
#line 996 "polyyacc.y"
    {
                            if( (yyvsp[0].sym)->surface )
                            {
                                (yyval.p) = polyxyz_copy( (polyxyz*)(yyvsp[0].sym)->ptr );
                            }
                            else
                            {
                                (yyval.p) = polyxyz_copy( &(yyvsp[0].sym)->p );
                            }

                            if( control )
                            {
                                printf( "calculating NAME\n" );
                                printf( "POLYXYZ: " );
                                polyxyz_print( &(yyvsp[0].sym)->p );
                                printf( "\n" );
                            }
                        }
    break;

  case 94:
#line 1017 "polyyacc.y"
    { (yyval.mon) = monxyz_mult( (yyvsp[-2].mon),&(yyvsp[0].mon) ); }
    break;

  case 95:
#line 1019 "polyyacc.y"
    { (yyval.mon) = monxyz_mult_double( (yyvsp[-2].mon),(double)(yyvsp[0].ival) ); }
    break;

  case 96:
#line 1021 "polyyacc.y"
    { (yyval.mon) = monxyz_mult_double( (yyvsp[-2].mon),(yyvsp[0].dval) ); }
    break;

  case 97:
#line 1023 "polyyacc.y"
    { (yyval.mon) = monxyz_mult_double( (yyvsp[0].mon),(double)(yyvsp[-2].ival) ); }
    break;

  case 98:
#line 1025 "polyyacc.y"
    { (yyval.mon) = monxyz_mult_double( (yyvsp[0].mon),(yyvsp[-2].dval) ); }
    break;

  case 99:
#line 1027 "polyyacc.y"
    { (yyval.mon) = monxyz_div_double( (yyvsp[-2].mon),(double)(yyvsp[0].ival) ); }
    break;

  case 100:
#line 1029 "polyyacc.y"
    { (yyval.mon) = monxyz_div_double( (yyvsp[-2].mon),(yyvsp[0].dval) ); }
    break;

  case 101:
#line 1031 "polyyacc.y"
    { (yyval.mon) = monxyz_power( (yyvsp[-2].mon),(yyvsp[0].ival) ); }
    break;

  case 102:
#line 1033 "polyyacc.y"
    { (yyval.mon) = monxyz_neg( (yyvsp[0].mon) ); }
    break;

  case 103:
#line 1035 "polyyacc.y"
    { (yyval.mon) = (yyvsp[0].mon); }
    break;

  case 104:
#line 1037 "polyyacc.y"
    { (yyval.mon) = (yyvsp[0].mon); }
    break;

  case 105:
#line 1039 "polyyacc.y"
    {
                            if( (yyvsp[0].sym)->surface )
                            {
                                (yyval.mon) = *((monxyz*)(yyvsp[0].sym)->ptr);
                            }
                            else
                            {
                                (yyval.mon) = (yyvsp[0].sym)->mon;
                            }

                            if( control )
                            {
                                printf( "calculating NAME\n" );
                                printf( "MONXYZ: " );
                                monxyz_print( &(yyvsp[0].sym)->mon );
                            }
                        }
    break;

  case 106:
#line 1057 "polyyacc.y"
    { (yyval.mon) = (yyvsp[-1].mon); }
    break;

  case 107:
#line 1061 "polyyacc.y"
    { (yyval.dval) = (yyvsp[-1].dval); }
    break;

  case 108:
#line 1063 "polyyacc.y"
    { (yyval.dval) = sqrt( (yyvsp[-1].dval) ); }
    break;

  case 109:
#line 1065 "polyyacc.y"
    { (yyval.dval) = sqrt( (double)(yyvsp[-1].ival) ); }
    break;

  case 110:
#line 1067 "polyyacc.y"
    { (yyval.dval) =
#ifdef SUN
                             sunpow( (yyvsp[-3].dval),(yyvsp[-1].dval) );
#else
                             pow( (yyvsp[-3].dval),(yyvsp[-1].dval) );
#endif /* SUN */ 
			}
    break;

  case 111:
#line 1075 "polyyacc.y"
    { (yyval.dval) = sin( (yyvsp[-1].dval) ); }
    break;

  case 112:
#line 1077 "polyyacc.y"
    { (yyval.dval) = sin( (double)(yyvsp[-1].ival) ); }
    break;

  case 113:
#line 1079 "polyyacc.y"
    { (yyval.dval) = cos( (yyvsp[-1].dval) ); }
    break;

  case 114:
#line 1081 "polyyacc.y"
    { (yyval.dval) = cos( (double)(yyvsp[-1].ival) ); }
    break;

  case 115:
#line 1083 "polyyacc.y"
    { (yyval.dval) = tan( (yyvsp[-1].dval) ); }
    break;

  case 116:
#line 1085 "polyyacc.y"
    { (yyval.dval) = tan( (double)(yyvsp[-1].ival) ); }
    break;

  case 117:
#line 1087 "polyyacc.y"
    { (yyval.dval) = cos( (yyvsp[-1].dval) )/sin( (yyvsp[-1].dval) ); }
    break;

  case 118:
#line 1089 "polyyacc.y"
    { (yyval.dval) = cos( (double)(yyvsp[-1].ival) )/sin( (double)(yyvsp[-1].ival) ); }
    break;

  case 119:
#line 1091 "polyyacc.y"
    { (yyval.dval) = sin( (yyvsp[-1].dval) ); }
    break;

  case 120:
#line 1093 "polyyacc.y"
    { (yyval.dval) = asin( (double)(yyvsp[-1].ival) ); }
    break;

  case 121:
#line 1095 "polyyacc.y"
    { (yyval.dval) = acos( (yyvsp[-1].dval) ); }
    break;

  case 122:
#line 1097 "polyyacc.y"
    { (yyval.dval) = acos( (double)(yyvsp[-1].ival) ); }
    break;

  case 123:
#line 1099 "polyyacc.y"
    { (yyval.dval) = atan( (yyvsp[-1].dval) ); }
    break;

  case 124:
#line 1101 "polyyacc.y"
    { (yyval.dval) = atan( (double)(yyvsp[-1].ival) ); }
    break;

  case 125:
#line 1103 "polyyacc.y"
    { (yyval.dval) = M_PI_2 - atan( (yyvsp[-1].dval) ); }
    break;

  case 126:
#line 1105 "polyyacc.y"
    { (yyval.dval) = M_PI_2 - atan( (double)(yyvsp[-1].ival) ); }
    break;

  case 127:
#line 1107 "polyyacc.y"
    { (yyval.dval) = (yyvsp[-2].dval) + (yyvsp[0].dval); }
    break;

  case 128:
#line 1109 "polyyacc.y"
    { (yyval.dval) = (yyvsp[-2].dval) + (double)(yyvsp[0].ival); }
    break;

  case 129:
#line 1111 "polyyacc.y"
    { (yyval.dval) = (double)(yyvsp[-2].ival) + (yyvsp[0].dval); }
    break;

  case 130:
#line 1113 "polyyacc.y"
    { (yyval.dval) = (yyvsp[-2].dval) - (yyvsp[0].dval); }
    break;

  case 131:
#line 1115 "polyyacc.y"
    { (yyval.dval) = (yyvsp[-2].dval) - (double)(yyvsp[0].ival); }
    break;

  case 132:
#line 1117 "polyyacc.y"
    { (yyval.dval) = (double)(yyvsp[-2].ival) - (yyvsp[0].dval); }
    break;

  case 133:
#line 1119 "polyyacc.y"
    { (yyval.dval) = (yyvsp[-2].dval) * (yyvsp[0].dval); }
    break;

  case 134:
#line 1121 "polyyacc.y"
    { (yyval.dval) = (yyvsp[-2].dval) * (double)(yyvsp[0].ival); }
    break;

  case 135:
#line 1123 "polyyacc.y"
    { (yyval.dval) = (double)(yyvsp[-2].ival) * (yyvsp[0].dval); }
    break;

  case 136:
#line 1125 "polyyacc.y"
    { (yyval.dval) = (yyvsp[-2].dval) / (yyvsp[0].dval); }
    break;

  case 137:
#line 1127 "polyyacc.y"
    { (yyval.dval) = (yyvsp[-2].dval) / (double)(yyvsp[0].ival); }
    break;

  case 138:
#line 1129 "polyyacc.y"
    { (yyval.dval) = (double)(yyvsp[-2].ival) / (yyvsp[0].dval); }
    break;

  case 139:
#line 1131 "polyyacc.y"
    { (yyval.dval) = (double)(yyvsp[-2].ival) / (double)(yyvsp[0].ival); }
    break;

  case 140:
#line 1133 "polyyacc.y"
    { (yyval.dval) = pow( (yyvsp[-2].dval),(yyvsp[0].dval) ); }
    break;

  case 141:
#line 1135 "polyyacc.y"
    { (yyval.dval) = pow( (yyvsp[-2].dval),(double)(yyvsp[0].ival) ); }
    break;

  case 142:
#line 1137 "polyyacc.y"
    { (yyval.dval) = pow( (double)(yyvsp[-2].ival),(yyvsp[0].dval) ); }
    break;

  case 143:
#line 1139 "polyyacc.y"
    { (yyval.dval) = -(yyvsp[0].dval); }
    break;

  case 144:
#line 1141 "polyyacc.y"
    { (yyval.dval) = (yyvsp[0].dval); }
    break;

  case 145:
#line 1143 "polyyacc.y"
    { (yyval.dval) = (yyvsp[0].dval); }
    break;

  case 146:
#line 1145 "polyyacc.y"
    {
                            if( (yyvsp[0].sym)->surface )
                            {
                                (yyval.dval) = *((double*)(yyvsp[0].sym)->ptr);
                            }
                            else
                            {
                                (yyval.dval) = (yyvsp[0].sym)->dval;
                            }

                            if( control )
                            {
                                printf( "calculating NAME\n" );
                                printf( "DOUBLE: %f\n",(yyvsp[0].sym)->dval );
                            }
                        }
    break;

  case 147:
#line 1164 "polyyacc.y"
    { (yyval.ival) = (yyvsp[-1].ival); }
    break;

  case 148:
#line 1166 "polyyacc.y"
    { (yyval.ival) = (yyvsp[-1].p).deg; }
    break;

  case 149:
#line 1168 "polyyacc.y"
    { (yyval.ival) = (yyvsp[-1].p).n; }
    break;

  case 150:
#line 1170 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].ival) && (yyvsp[0].ival) ); }
    break;

  case 151:
#line 1172 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].ival) || (yyvsp[0].ival) ); }
    break;

  case 152:
#line 1174 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].ival) == (yyvsp[0].ival) ); }
    break;

  case 153:
#line 1176 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].ival) != (yyvsp[0].ival) ); }
    break;

  case 154:
#line 1178 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].ival) > (yyvsp[0].ival) ); }
    break;

  case 155:
#line 1180 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].ival) >= (yyvsp[0].ival) ); }
    break;

  case 156:
#line 1182 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].ival) < (yyvsp[0].ival) ); }
    break;

  case 157:
#line 1184 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].ival) <= (yyvsp[0].ival) ); }
    break;

  case 158:
#line 1186 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].dval) == (yyvsp[0].dval) ); }
    break;

  case 159:
#line 1188 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].dval) != (yyvsp[0].dval) ); }
    break;

  case 160:
#line 1190 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].dval) > (yyvsp[0].dval) ); }
    break;

  case 161:
#line 1192 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].dval) >= (yyvsp[0].dval) ); }
    break;

  case 162:
#line 1194 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].dval) < (yyvsp[0].dval) ); }
    break;

  case 163:
#line 1196 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].dval) <= (yyvsp[0].dval) ); }
    break;

  case 164:
#line 1198 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].ival) == (yyvsp[0].dval) ); }
    break;

  case 165:
#line 1200 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].ival) != (yyvsp[0].dval) ); }
    break;

  case 166:
#line 1202 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].ival) > (yyvsp[0].dval) ); }
    break;

  case 167:
#line 1204 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].ival) >= (yyvsp[0].dval) ); }
    break;

  case 168:
#line 1206 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].ival) < (yyvsp[0].dval) ); }
    break;

  case 169:
#line 1208 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].ival) <= (yyvsp[0].dval) ); }
    break;

  case 170:
#line 1210 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].dval) == (yyvsp[0].ival) ); }
    break;

  case 171:
#line 1212 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].dval) != (yyvsp[0].ival) ); }
    break;

  case 172:
#line 1214 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].dval) > (yyvsp[0].ival) ); }
    break;

  case 173:
#line 1216 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].dval) >= (yyvsp[0].ival) ); }
    break;

  case 174:
#line 1218 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].dval) < (yyvsp[0].ival) ); }
    break;

  case 175:
#line 1220 "polyyacc.y"
    { (yyval.ival) = ( (yyvsp[-2].dval) <= (yyvsp[0].ival) ); }
    break;

  case 176:
#line 1222 "polyyacc.y"
    { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
    break;

  case 177:
#line 1224 "polyyacc.y"
    { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
    break;

  case 178:
#line 1226 "polyyacc.y"
    { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
    break;

  case 179:
#line 1228 "polyyacc.y"
    { (yyval.ival) = (yyvsp[-2].ival) % (yyvsp[0].ival); }
    break;

  case 180:
#line 1230 "polyyacc.y"
    { (yyval.ival) = (int)pow( (double)(yyvsp[-2].ival),(double)(yyvsp[0].ival) ); }
    break;

  case 181:
#line 1232 "polyyacc.y"
    { (yyval.ival) = -(yyvsp[0].ival); }
    break;

  case 182:
#line 1234 "polyyacc.y"
    { (yyval.ival) = (yyvsp[0].ival); }
    break;

  case 183:
#line 1236 "polyyacc.y"
    { (yyval.ival) = (yyvsp[0].ival); }
    break;

  case 184:
#line 1238 "polyyacc.y"
    {
                            if( (yyvsp[0].sym)->surface )
                            {
                                (yyval.ival) = *((int*)(yyvsp[0].sym)->ptr);
                            }
                            else
                            {
                                (yyval.ival) = (yyvsp[0].sym)->ival;
                            }

                            if( control )
                            {
                                printf( "calculating NAME\n" );
                                printf( "INTEGER: %d\n",(yyvsp[0].sym)->ival );
                            }
                            break;
                        }
    break;


    }

/* Line 1037 of yacc.c.  */
#line 3349 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {

		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 yydestruct ("Error: popping",
                             yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yydestruct ("Error: discarding lookahead",
              yytoken, &yylval);
  yychar = YYEMPTY;
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1257 "polyyacc.y"


/* ------------------------------------------------------------------------- */
/* end of file: polyyacc.y                                                   */
/* ------------------------------------------------------------------------- */

