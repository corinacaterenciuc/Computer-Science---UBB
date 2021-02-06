/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANT = 259,
    START = 260,
    FINISH = 261,
    IF = 262,
    ELSE = 263,
    ENDIF = 264,
    FOR = 265,
    FROM = 266,
    TO = 267,
    DO = 268,
    ENDFOR = 269,
    WHILE = 270,
    ENDWHILE = 271,
    GET = 272,
    PRINT = 273,
    INT = 274,
    STRING = 275,
    VECTOR = 276,
    CONST = 277,
    BOOL = 278,
    CHAR = 279,
    REAL = 280,
    SQRT = 281,
    COLON = 282,
    SEMI_COLON = 283,
    COMA = 284,
    DOT = 285,
    LEFT_ROUND_PARENTHESIS = 286,
    RIGHT_ROUND_PARENTHESIS = 287,
    LEFT_SQUARE_PARENTHESIS = 288,
    RIGHT_SQUARE_PARENTHESIS = 289,
    LEFT_BRACKET = 290,
    RIGHT_BRACKET = 291,
    PLUS = 292,
    MINUS = 293,
    MULTIPLY = 294,
    DIVISION = 295,
    LESS_THAN = 296,
    GREATER_THAN = 297,
    LESS_OR_EQUAL_THAN = 298,
    GREATER_OR_EQUAL_THAN = 299,
    DIFFERENT = 300,
    ASSIGNMENT = 301,
    EQUAL = 302,
    POWER = 303,
    OR = 304,
    AND = 305,
    NOT = 306
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define START 260
#define FINISH 261
#define IF 262
#define ELSE 263
#define ENDIF 264
#define FOR 265
#define FROM 266
#define TO 267
#define DO 268
#define ENDFOR 269
#define WHILE 270
#define ENDWHILE 271
#define GET 272
#define PRINT 273
#define INT 274
#define STRING 275
#define VECTOR 276
#define CONST 277
#define BOOL 278
#define CHAR 279
#define REAL 280
#define SQRT 281
#define COLON 282
#define SEMI_COLON 283
#define COMA 284
#define DOT 285
#define LEFT_ROUND_PARENTHESIS 286
#define RIGHT_ROUND_PARENTHESIS 287
#define LEFT_SQUARE_PARENTHESIS 288
#define RIGHT_SQUARE_PARENTHESIS 289
#define LEFT_BRACKET 290
#define RIGHT_BRACKET 291
#define PLUS 292
#define MINUS 293
#define MULTIPLY 294
#define DIVISION 295
#define LESS_THAN 296
#define GREATER_THAN 297
#define LESS_OR_EQUAL_THAN 298
#define GREATER_OR_EQUAL_THAN 299
#define DIFFERENT 300
#define ASSIGNMENT 301
#define EQUAL 302
#define POWER 303
#define OR 304
#define AND 305
#define NOT 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
