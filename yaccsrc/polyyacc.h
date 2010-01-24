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
/* Line 1318 of yacc.c.  */
#line 159 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



