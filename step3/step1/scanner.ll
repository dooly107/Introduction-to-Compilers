%{
#include <string>
#include <cstdio>
#include "parser.hpp"
extern void yyerror(const char *p);
extern FILE *yyin;
extern int yyparse(void);
#define register
%}

%option noyywrap c++

_PRG		PROGRAM
_BGN		BEGIN
_END		END
_FNC		FUNCTION
_RD		READ
_WR		WRITE
_IF		IF
_ELSE		ELSE
_ENDIF		ENDIF
_WHILE		WHILE
_ENDWH		ENDWHILE
_RTN		RETURN
_INT		INT
_VOID		VOID
_STRING		STRING
_FLOAT		FLOAT
_TRUE		TRUE
_FALSE		FALSE
_ASSIGN		\:=
_PLUS		\+
_MINUS		\-
_MUL		\*
_DIV		\/
_NQ		\!=
_LT		\<
_GT		\>
_EQ		\=
_OPENP		\(
_CLOSEP		\)
_SEMICOLON	\;
_COMMA		\,
_LTE		\<=
_GTE		\>=
IDENTIFIER	[A-Za-z][A-Za-z0-9]*
FLOATLITERAL	[0-9]*\.[0-9]+
INTLITERAL	[0-9]+
STRINGLITERAL	(\".+\")
COMMENT		(\-\-.*)
WHITESPACE	\t|\r|\n|" "

%%
_PRG 			{ return _PRG; }
_BGN			{ return _BGN; }
_END			{ return _END; }
_FNC			{ return _FNC; }
_RD				{ return _RD; }
_WR				{ return _WR; }
_IF				{ return _IF; }
_ELSE			{ return _ELSE; }
_ENDIF			{ return _ENDIF; }
_WHILE			{ return _WHILE; }
_ENDWH			{ return _ENDWH; }
_RTN			{ return _RTN; }
_INT			{ return _INT; }
_VOID			{ return _VOID; }
_STRING			{ return _STRING; }
_FLOAT			{ return _FLOAT; }
_TRUE			{ return _TRUE; }
_FALSE			{ return _FALSE; }
_ASSIGN			{ return _ASSIGN; }
_PLUS			{ return _PLUS; }
_MINUS			{ return _MINUS; }
_MUL			{ return _MUL; }
_DIV			{ return _DIV; }
_NQ				{ return _NQ; }
_GT				{ return _GT; }
_LT				{ return _LT; }
_EQ				{ return _EQ; }
_OPENP			{ return _OPENP; }
_CLOSEP			{ return _CLOSEP; }
_SEMICOLON		{ return _SEMICOLON; }
_COMMA			{ return _COMMA; }
_GTE			{ return _GTE; }
_LTE			{ return _LTE; }
{IDENTIFIER}	{ return IDENTIFIER; }
{FLOATLITERAL} 	{ return FLOATLITERAL; }
{INTLITERAL}	{ return INTLITERAL; }
{STRINGLITERAL}	{ return STRINGLITERAL; }
{COMMENT}       {}
{WHITESPACE}	{}

%%
