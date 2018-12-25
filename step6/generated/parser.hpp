/* A Bison parser, made by GNU Bison 3.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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

#ifndef YY_YY_GENERATED_PARSER_HPP_INCLUDED
# define YY_YY_GENERATED_PARSER_HPP_INCLUDED
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
    _PRG = 258,
    _BGN = 259,
    _END = 260,
    _FNC = 261,
    _RD = 262,
    _WR = 263,
    _IF = 264,
    _ELSE = 265,
    _ENDIF = 266,
    _WHILE = 267,
    _ENDWH = 268,
    _RTN = 269,
    _INT = 270,
    _VOID = 271,
    _STRING = 272,
    _FLOAT = 273,
    _TRUE = 274,
    _FALSE = 275,
    _ASSIGN = 276,
    _PLUS = 277,
    _MINUS = 278,
    _MUL = 279,
    _DIV = 280,
    _NQ = 281,
    _GT = 282,
    _LT = 283,
    _OPENP = 284,
    _CLOSEP = 285,
    _SEMICOLON = 286,
    _COMMA = 287,
    _GTE = 288,
    _LTE = 289,
    _EQ = 290,
    IDENTIFIER = 291,
    FLOATLITERAL = 292,
    INTLITERAL = 293,
    STRINGLITERAL = 294,
    COMMENT = 295,
    WHITESPACE = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 1698 "src/parser.yy" /* yacc.c:1919  */

	struct ID_List* id_l;
	char* s;
	struct Param_Decl* p_decl;
	struct Param_Decl_List* p_list;
	struct ASTNode* AST;
	struct toList* mL;

#line 105 "generated/parser.hpp" /* yacc.c:1919  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GENERATED_PARSER_HPP_INCLUDED  */
