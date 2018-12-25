%{
	#include <cstdio>
	#include <string>
	#include <string.h>
	#include <iostream>
	using namespace std;
	extern int yylex();
	extern char* yytext;
	void yyerror(const char *p) {};
	#include "../src/parserStruct.hpp"
	int cnt = 1;
	vector <char *> myVector;

	
	void Print_Block(int cnt) {
		cout << "\nSymbol table BLOCK " << cnt << endl;
	};
	
	void Print_ST(char* id) {
		cout << "\nSymbol table " << id << endl;
	};
	
	void printPD(Param_Decl* pd) {
		cout << "name " << pd -> id << " type " << pd -> type << endl;
	};
	
	void print_VarEntry(VarEntry* VE) {
		while (VE -> id_list != NULL) {
			myVector.push_back(VE -> id_list -> id);
			cout << "name " << VE -> id_list -> id << " type " << VE -> var_type << endl;
			VE -> id_list = VE -> id_list -> id_tail;
		}
	};
	
	void print_StrEntry(StrEntry* SR) {
		cout << "name " << SR -> id << " type STRING value " << SR -> str << endl;
	};

	char* error() {
		for (int i = 0; i < myVector.size(); i++) {
			for (int j = i + 1; j < myVector.size(); j++) {
				if (strcmp(myVector[i], myVector[j]) == 0) {
					return myVector[i];
				}
			}
		}
		return NULL;
	};
%}

%union{
	struct StrEntry* s_entry;
	struct VarEntry* v_entry;
	struct ID_List* id_l;
	char* s;
	struct Param_Decl* p_decl;
	struct Param_Decl_List* p_list;
}

%type <s_entry> string_decl;
%type <v_entry> var_decl;
%type <s> id str var_type any_type;
%type <id_l> id_list id_tail;
%type <p_decl> param_decl;
%type <p_list> param_decl_list param_decl_tail;

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
%token	<s> _INT
%token	<s> _VOID
%token	<s> _STRING
%token	<s> _FLOAT
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
%token	<s> IDENTIFIER
%token	FLOATLITERAL
%token	INTLITERAL
%token	<s> STRINGLITERAL
%token	COMMENT
%token	WHITESPACE

%start program

%%
program:			_PRG {cout << "Symbol table GLOBAL" << endl;} id _BGN pgm_body _END ; 
id:					IDENTIFIER ;
pgm_body:			decl func_declarations ;
decl:				string_decl decl | var_decl decl | /* empty */ ;

/* Global String Declaration */
string_decl:		_STRING id _ASSIGN str _SEMICOLON {$$ = new StrEntry(); $$->addID($2); $$->addValue($4); print_StrEntry($$);};
str:				STRINGLITERAL ;

/* Variable Declaration */
var_decl:			var_type id_list _SEMICOLON {$$ = new VarEntry(); $$->addVartype($1); $$->addIDlist($2); print_VarEntry($$);};
var_type:			_FLOAT | _INT ;
any_type:			var_type | _VOID ;
id_list:			id id_tail {$$ = new ID_List(); $$->addID($1); $$->nextID($2);};
id_tail:			_COMMA id id_tail {$$ = new ID_List(); $$->addID($2); $$->nextID($3);}| {$$ = NULL;};

/* Function Paramater List */
param_decl_list:	param_decl param_decl_tail {$$ = new Param_Decl_List(); $$->addPD($1); $$->nextPD($2);} | {$$ = NULL;};
param_decl:			var_type id {$$ = new Param_Decl(); $$->addType($1); $$->addID($2); printPD($$);};
param_decl_tail:	_COMMA param_decl param_decl_tail {$$ = new Param_Decl_List(); $$->addPD($2); $$->nextPD($3);} | {$$ = NULL;};

/* Function Declarations */
func_declarations:	func_decl func_declarations | /* empty */ ;
func_decl:			_FNC any_type id {Print_ST($3);} _OPENP param_decl_list _CLOSEP _BGN func_body _END ;
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
if_stmt:			_IF {Print_Block(cnt++);} _OPENP cond _CLOSEP decl stmt_list else_part _ENDIF ;
else_part:			_ELSE {Print_Block(cnt++);} decl stmt_list | /* empty */ ;
cond:				expr compop expr | _TRUE | _FALSE ;
compop:				_LT | _GT | _EQ | _NQ | _LTE | _GTE ;
while_stmt:			_WHILE {Print_Block(cnt++);} _OPENP cond _CLOSEP decl stmt_list _ENDWH ;


/*ECE468 ONLY*/
control_stmt:		return_stmt ;
loop_stmt:			while_stmt ;
%%
