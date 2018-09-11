%{
	#include <cstdio>
	#include <string>
	#include <iostream>
	using namespace std;
	extern int yylex();
	extern char* yytext;
	void yyerror(const char *p) {};
%}


%token	_PRG
%token	_BGN
%token	_END
%token	_FNC
%token	_RD
%token	_WR
%token	_IF
%token	_ELSE
%token	_ENDIF
%token	_WHILE
%token	_ENDWH
%token	_RTN
%token	_INT
%token	_VOID
%token	_STRING
%token	_FLOAT
%token	_TRUE
%token	_FALSE
%token	_ASSIGN
%token	_PLUS
%token	_MINUS
%token	_MUL
%token	_DIV
%token	_NQ
%token	_GT
%token	_LT
%token	_OPENP
%token	_CLOSEP
%token	_SEMICOLON
%token	_COMMA
%token	_GTE
%token	_LTE
%token	_EQ
%token	IDENTIFIER
%token	FLOATLITERAL
%token	INTLITERAL
%token	STRINGLITERAL
%token	COMMENT
%token	WHITESPACE

%start program

%%
program:			_PRG id _BGN pgm_body _END ; 
id:					IDENTIFIER ;
pgm_body:			decl func_declarations ;
decl:				string_decl decl | var_decl decl | /* empty */ ;

/* Global String Declaration */
string_decl:		_STRING id _ASSIGN str _SEMICOLON ;
str:				STRINGLITERAL ;

/* Variable Declaration */
var_decl:			var_type id_list _SEMICOLON ;
var_type:			_FLOAT | _INT ;
any_type:			var_type | _VOID ;
id_list:			id id_tail ;
id_tail:			_COMMA id id_tail | /* empty */ ;

/* Function Paramater List */
param_decl_list:	param_decl param_decl_tail | /* empty */ ;
param_decl:			var_type id ;
param_decl_tail:	_COMMA param_decl param_decl_tail | /* empty */ ;

/* Function Declarations */
func_declarations:	func_decl func_declarations | /* empty */ ;
func_decl:			_FNC any_type id _OPENP param_decl_list _CLOSEP _BGN func_body _END ;
func_body:			decl stmt_list ;

/* Statement List */
stmt_list:			stmt stmt_list | /* empty */ ;
stmt:				base_stmt | if_stmt | loop_stmt ;
base_stmt:			assign_stmt | read_stmt | write_stmt | control_stmt ;

/* Basic Statements */
assign_stmt:		assign_expr _SEMICOLON ;
assign_expr:		id _ASSIGN expr ;
read_stmt:			_RD _OPENP id_list _CLOSEP _SEMICOLON ;
write_stmt:			_WR _OPENP id_list _CLOSEP _SEMICOLON ;
return_stmt:		_RTN expr _SEMICOLON ;

/* Expressions */
expr:				expr_prefix factor ;
expr_prefix:		expr_prefix factor addop | /* empty */ ;
factor:				factor_prefix postfix_expr ;
factor_prefix:		factor_prefix postfix_expr mulop | /* empty */ ;
postfix_expr:		primary | call_expr ;
call_expr:			id _OPENP expr_list _CLOSEP ;
expr_list:			expr expr_list_tail | /* empty */ ;
expr_list_tail:		_COMMA expr expr_list_tail | /* empty */ ;
primary:			_OPENP expr _CLOSEP | id | INTLITERAL | FLOATLITERAL ;
addop:				_PLUS | _MINUS ;
mulop:				_MUL | _DIV ;

/* Complex Statements and Condition */ 
if_stmt:			_IF _OPENP cond _CLOSEP decl stmt_list else_part _ENDIF ;
else_part:			_ELSE decl stmt_list | /* empty */ ;
cond:				expr compop expr | _TRUE | _FALSE ;
compop:				_LT | _GT | _EQ | _NQ | _LTE | _GTE ;
while_stmt:			_WHILE _OPENP cond _CLOSEP decl stmt_list _ENDWH ;


/*ECE468 ONLY*/
control_stmt:		return_stmt ;
loop_stmt:			while_stmt ;
%%
