%{
	#include <cstdio>
	#include <string>
	#include <string.h>
	#include <stdio.h>
	#include <cstdlib>
	#include <iostream>
	#include <map>
	#include <sstream>
	#include <list>
	#include <vector>
	#include <iterator>
	using namespace std;
	extern int yylex();
	extern char* yytext;
	void yyerror(const char *p) {};
	#include "../src/parserStruct.hpp"
	int cnt = 1;
	vector <char *> myVector;
	ASTNode* root;
	ID_List* id_lst;
	list <toList*> myList;
	list <char*> intList;
	list <char*> floatList;
	char* type;
	map <char*, char*> stringList;
	long long reg_count = 0;
	list <IR*> ir_list;
	IR* push;
	int prim = 0;
	vector <string> threeAC;
	stringstream buffer;
	list <new_threeAC*> threeAC_list;
	list <Tiny*> tiny_list;

	char temp1[10];
	char temp2[10];
	char temp3[10];

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

	//Step4

	char* findType(char* id) {
		list <char*>::iterator it;
		char* temp;
		for (it=intList.begin(); it!=intList.end(); ++it) {
			if (!strcmp(*it, id)) {
				temp = (char*)"INT";
				return temp;
			}
		}
		for (it=floatList.begin(); it!=floatList.end(); ++it) {
			if (!strcmp(*it, id)) {
				temp = (char*)"FLOAT";
				return temp;
			}
		}
		temp = (char*)"STRING";
		return temp;
	}

	void print_sign(ASTNode* node) {
		cout << node -> sign << endl;
	}
	void print_id(ASTNode* node) {
		cout << node -> id << endl;
	}

	void push_ir(char* op, char* reg1, char* reg2, char* reg3) {
		push = new IR();
		push -> addOp(op);
		push -> addReg1(reg1);
		push -> addReg2(reg2);
		push -> addReg3(reg3);
		buffer << ";" << push -> op << " " << push -> reg1 << " " << push -> reg2 << " " << push -> reg3 << endl;
		threeAC.push_back(buffer.str());
		buffer.str("");
	}

	void traverse(ASTNode* node, char* type) {
		if (node == NULL) {
			return;
		}
		traverse(node -> left, type);
		traverse(node -> right, type);
		if (node -> sign != NULL) {
			if (!strcmp(node -> sign, "+")) {
				strcpy(temp1, "ADD");
				strcat(temp1, type);
				strcpy(temp2, "!T");
				strcat(temp2, to_string(reg_count).c_str());
				push_ir(temp1, node -> left -> id, node -> right -> id, (char*)temp2);
				node -> left = NULL;
				node -> right = NULL;
				char* temp3 = new char[10];
				strcpy(temp3, temp2);
				node -> id = temp3;
				node -> sign = NULL;
				node -> type = (char*)"REG";
				reg_count++;
			}
			else if (!strcmp(node -> sign, "-")) {
				strcpy(temp1, "SUB");
				strcat(temp1, type);
				strcpy(temp2, "!T");
				strcat(temp2, to_string(reg_count).c_str());
				push_ir(temp1, node -> left -> id, node -> right -> id, (char*)temp2);
				node -> left = NULL;
				node -> right = NULL;
				char* temp3 = new char[10];
				strcpy(temp3, temp2);
				node -> id = temp3;
				node -> sign = NULL;
				node -> type = (char*)"REG";
				reg_count++;
			}
			else if (!strcmp(node -> sign, "*")) {
				strcpy(temp1, "MUL");
				strcat(temp1, type);
				strcpy(temp2, "!T");
				strcat(temp2, to_string(reg_count).c_str());
				push_ir(temp1, node -> right -> id, node -> left -> id, (char*)temp2);
				node -> left = NULL;
				node -> right = NULL;
				char* temp3 = new char[10];
				strcpy(temp3, temp2);
				node -> id = temp3;
				node -> sign = NULL;
				node -> type = (char*)"REG";
				reg_count++;
			}
			else if (!strcmp(node -> sign, "/")) {
				strcpy(temp1, "DIV");
				strcat(temp1, type);
				strcpy(temp2, "!T");
				strcat(temp2, to_string(reg_count).c_str());
				push_ir(temp1, node -> right -> id, node -> left -> id, (char*)temp2);
				node -> left = NULL;
				node -> right = NULL;
				char* temp3 = new char[10];
				strcpy(temp3, temp2);
				node -> id = temp3;
				node -> sign = NULL;
				node -> type = (char*)"REG";
				reg_count++;
			}
		}
		else if (!strcmp(node -> type, "INTLITERAL")) {
			strcpy(temp2, "!T");
			strcat(temp2, to_string(reg_count).c_str());

			buffer << ";STOREI " << node -> id << " !T" << to_string(reg_count) << endl;
			threeAC.push_back(buffer.str());
			buffer.str("");
			node -> left = NULL;
			node -> right = NULL;
			char* temp3 = new char[10];
			strcpy(temp3, temp2);
			node -> id = temp3;
			node -> sign = NULL;
			node -> type = (char*)"REG";
			reg_count++;
		}
		else if (!strcmp(node -> type, "FLOATLITERAL")) {
			strcpy(temp2, "!T");
			strcat(temp2, to_string(reg_count).c_str());
			buffer << ";STOREF " << node -> id << " !T" << to_string(reg_count) << endl;
			threeAC.push_back(buffer.str());
			buffer.str("");
			node -> left = NULL;
			node -> right = NULL;
			char* temp3 = new char[10];
			strcpy(temp3, temp2);
			node -> id = temp3;
			node -> sign = NULL;
			node -> type = (char*)"REG";
			reg_count++;
		}
	}

	void print_toList() {
		list<toList*>::iterator it;
		for (it=myList.begin(); it!=myList.end(); ++it) {
			if (!strcmp((*it) -> op, "ASSIGN")) {
				if ((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "INT")) {
					traverse((*it) -> node, (char*)"I");
					if (!strcmp((*it) -> node -> type, "INT") || !strcmp((*it) -> node -> type, "FLOAT")) {
						buffer << ";STOREI " << (*it) -> node -> id << " !T" << to_string(reg_count) << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						buffer << ";STOREI " << "!T" << to_string(reg_count) << " " << (*it) -> destination << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						reg_count++;
					}
					else {
						reg_count--;
						buffer << ";STOREI " << "!T" << to_string(reg_count) << " " << (*it) -> destination << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						reg_count++;
					}
				}
				else if ((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "FLOAT")) {
					traverse((*it) -> node, (char*)"F");
					if (!strcmp((*it) -> node -> type, "INT") || !strcmp((*it) -> node -> type, "FLOAT")) {
						buffer << ";STOREF " << (*it) -> node -> id << " !T" << to_string(reg_count) << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						buffer << ";STOREF " << "!T" << to_string(reg_count) << " " << (*it) -> destination << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						reg_count++;
					}
					else {
						reg_count--;
						buffer << ";STOREF " << "!T" << to_string(reg_count) << " " << (*it) -> destination << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						reg_count++;
					}
				}
			}
			else if (!strcmp((*it) -> op, "READ") || !strcmp((*it) -> op, "WRITE")) {
				while ((*it) -> ids != NULL) {
					char* temp;
					temp = findType((*it) -> ids -> id);
					if (!strcmp(temp, "INT")) {
						buffer << ";" << (*it) -> destination << "I " << (*it) -> ids -> id << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						(*it) -> ids = (*it) -> ids -> id_tail;
					}
					else if (!strcmp(temp, "FLOAT")) {
						buffer << ";" << (*it) -> destination << "F " << (*it) -> ids -> id << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						(*it) -> ids = (*it) -> ids -> id_tail;
					}
					else {
						buffer << ";" << (*it) -> destination << "S " << (*it) -> ids -> id << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						(*it) -> ids = (*it) -> ids -> id_tail;
					}
				}
			}
		}
	}

	void print_buffer() {
		vector<string>::iterator it;
		for (it=threeAC.begin(); it!=threeAC.end(); ++it) {
			cout << (*it);
		}
	}

	void print_threeAC() {
		list<new_threeAC*>::iterator it;
		for (it=threeAC_list.begin(); it!=threeAC_list.end(); ++it) {
			cout << (*it) -> op << " " << (*it) -> reg1 << " " << (*it) -> reg2 << " " << (*it) -> reg3 << " " << endl;
		}
	}

	void insert_threeAC() {
		vector<string>::iterator it;
		for (it=threeAC.begin(); it!=threeAC.end(); ++it) {
			istringstream buf((*it));
			istream_iterator<string> beg(buf), end;
			vector<string> tokens(beg, end);
			new_threeAC* newthreeAC = new new_threeAC();
			vector<string>::iterator its;
			for(its=tokens.begin(); its!=tokens.end(); ++its) {
				if ((newthreeAC -> op).empty()) {
					newthreeAC -> addOp((*its));
				}
				else if ((newthreeAC -> reg1).empty()) {
					newthreeAC -> addReg1((*its));
				}
				else if ((newthreeAC -> reg2).empty()) {
					newthreeAC -> addReg2((*its));
				}
				else if ((newthreeAC -> reg3).empty()) {
					newthreeAC -> addReg3((*its));
				}
			}
			threeAC_list.push_back(newthreeAC);
		}
	}

	void print_tinylist() {
		list<Tiny*>::iterator it;
		for (it=tiny_list.begin(); it!=tiny_list.end(); ++it) {
			cout << (*it) -> op << " " << (*it) -> reg1 << " " << (*it) -> reg2 << " " << endl;
		}
	}

	void addTinyList() {
		list<char*>::iterator it;
		for (it=intList.begin(); it!=intList.end(); ++it) {
			Tiny* tiny = new Tiny();
			string s = string("var");
			tiny -> addOp(s);
			tiny -> addReg1((*it));
			tiny_list.push_back(tiny);
		}
		for (it=floatList.begin(); it!=floatList.end(); ++it) {
			Tiny* tiny = new Tiny();
			string s = string("var");
			tiny -> addOp(s);
			tiny -> addReg1((*it));
			tiny_list.push_back(tiny);
		}
		map<char*, char*>::iterator iter;
		for (iter=stringList.begin(); iter!=stringList.end(); ++iter) {
			Tiny* tiny = new Tiny();
			string s = string("str");
			string s2 = string(iter -> first);
			string s3 = string(iter -> second);
			tiny -> addOp(s);
			tiny -> addReg1(s2);
			tiny -> addReg2(s3);
			tiny_list.push_back(tiny);
		}
/*
		for(auto& x : stringList) {
			Tiny* tiny = new Tiny();
			string s = string("str");
			string s2 = string(x.first);
			string s3 = string(x.second);
			tiny -> addOp(s);
			tiny -> addReg1(s2);
			tiny -> addReg2(s3);
			tiny_list.push_back(tiny);
		}
*/
		list<new_threeAC*>::iterator its;
		for (its=threeAC_list.begin(); its!=threeAC_list.end(); ++its) {
			string operation = string((*its) -> op);
			operation.erase(0,1);
			if (operation == "STOREI" || operation == "STOREF") {
				Tiny* tiny = new Tiny();
				string s = string("move");
				string s2 = string((*its) -> reg1);
				string s3 = string((*its) -> reg2);
				string r = string("r");
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				if (s3.find("!T") != string::npos) {
					s3.erase(0,2);
					s3 = r + s3;
				}
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny -> addReg2(s3);
				tiny_list.push_back(tiny);
			}
			else if (operation == "WRITEI") {
				Tiny* tiny = new Tiny();
				string s = string("sys");
				string s2 = string("writei");
				string s3 = string((*its) -> reg1);
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny -> addReg2(s3);
				tiny_list.push_back(tiny);
			}
			else if (operation == "WRITEF") {
				Tiny* tiny = new Tiny();
				string s = string("sys");
				string s2 = string("writer");
				string s3 = string((*its) -> reg1);
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny -> addReg2(s3);
				tiny_list.push_back(tiny);
			}
			else if (operation == "WRITES") {
				Tiny* tiny = new Tiny();
				string s = string("sys");
				string s2 = string("writes");
				string s3 = string((*its) -> reg1);
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny -> addReg2(s3);
				tiny_list.push_back(tiny);
			}
			else if (operation == "READI") {
				Tiny* tiny = new Tiny();
				string s = string("sys");
				string s2 = string("readi");
				string s3 = string((*its) -> reg1);
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny -> addReg2(s3);
				tiny_list.push_back(tiny);
			}
			else if (operation == "READF") {
				Tiny* tiny = new Tiny();
				string s = string("sys");
				string s2 = string("readf");
				string s3 = string((*its) -> reg1);
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny -> addReg2(s3);
				tiny_list.push_back(tiny);
			}
			else if (operation == "ADDI") {
				Tiny* tiny = new Tiny();
				string s = string("move");
				string s2 = string((*its) -> reg1);
				string s3 = string((*its) -> reg2);
				string s4 = string((*its) -> reg3);
				string r = string("r");
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				if (s3.find("!T") != string::npos) {
					s3.erase(0,2);
					s3 = r + s3;
				}
				if (s4.find("!T") != string::npos) {
					s4.erase(0,2);
					s4 = r + s4;
				}
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny -> addReg2(s4);
				tiny_list.push_back(tiny);
				Tiny* tiny2 = new Tiny();
				s = string("addi");
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s3);
				tiny2 -> addReg2(s4);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "SUBI") {
				Tiny* tiny = new Tiny();
				string s = string("move");
				string s2 = string((*its) -> reg1);
				string s3 = string((*its) -> reg2);
				string s4 = string((*its) -> reg3);
				string r = string("r");
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				if (s3.find("!T") != string::npos) {
					s3.erase(0,2);
					s3 = r + s3;
				}
				if (s4.find("!T") != string::npos) {
					s4.erase(0,2);
					s4 = r + s4;
				}
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny -> addReg2(s4);
				tiny_list.push_back(tiny);
				Tiny* tiny2 = new Tiny();
				s = string("subi");
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s3);
				tiny2 -> addReg2(s4);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "MULI") {
				Tiny* tiny = new Tiny();
				string s = string("move");
				string s2 = string((*its) -> reg1);
				string s3 = string((*its) -> reg2);
				string s4 = string((*its) -> reg3);
				string r = string("r");
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				if (s3.find("!T") != string::npos) {
					s3.erase(0,2);
					s3 = r + s3;
				}
				if (s4.find("!T") != string::npos) {
					s4.erase(0,2);
					s4 = r + s4;
				}
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny -> addReg2(s4);
				tiny_list.push_back(tiny);
				Tiny* tiny2 = new Tiny();
				s = string("muli");
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s3);
				tiny2 -> addReg2(s4);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "DIVI") {
				Tiny* tiny = new Tiny();
				string s = string("move");
				string s2 = string((*its) -> reg1);
				string s3 = string((*its) -> reg2);
				string s4 = string((*its) -> reg3);
				string r = string("r");
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				if (s3.find("!T") != string::npos) {
					s3.erase(0,2);
					s3 = r + s3;
				}
				if (s4.find("!T") != string::npos) {
					s4.erase(0,2);
					s4 = r + s4;
				}
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny -> addReg2(s4);
				tiny_list.push_back(tiny);
				Tiny* tiny2 = new Tiny();
				s = string("divi");
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s3);
				tiny2 -> addReg2(s4);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "ADDF") {
				Tiny* tiny = new Tiny();
				string s = string("move");
				string s2 = string((*its) -> reg1);
				string s3 = string((*its) -> reg2);
				string s4 = string((*its) -> reg3);
				string r = string("r");
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				if (s3.find("!T") != string::npos) {
					s3.erase(0,2);
					s3 = r + s3;
				}
				if (s4.find("!T") != string::npos) {
					s4.erase(0,2);
					s4 = r + s4;
				}
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny -> addReg2(s4);
				tiny_list.push_back(tiny);
				Tiny* tiny2 = new Tiny();
				s = string("addr");
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s3);
				tiny2 -> addReg2(s4);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "SUBF") {
				Tiny* tiny = new Tiny();
				string s = string("move");
				string s2 = string((*its) -> reg1);
				string s3 = string((*its) -> reg2);
				string s4 = string((*its) -> reg3);
				string r = string("r");
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				if (s3.find("!T") != string::npos) {
					s3.erase(0,2);
					s3 = r + s3;
				}
				if (s4.find("!T") != string::npos) {
					s4.erase(0,2);
					s4 = r + s4;
				}
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny -> addReg2(s4);
				tiny_list.push_back(tiny);
				Tiny* tiny2 = new Tiny();
				s = string("subr");
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s3);
				tiny2 -> addReg2(s4);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "MULF") {
				Tiny* tiny = new Tiny();
				string s = string("move");
				string s2 = string((*its) -> reg1);
				string s3 = string((*its) -> reg2);
				string s4 = string((*its) -> reg3);
				string r = string("r");
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				if (s3.find("!T") != string::npos) {
					s3.erase(0,2);
					s3 = r + s3;
				}
				if (s4.find("!T") != string::npos) {
					s4.erase(0,2);
					s4 = r + s4;
				}
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny -> addReg2(s4);
				tiny_list.push_back(tiny);
				Tiny* tiny2 = new Tiny();
				s = string("mulr");
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s3);
				tiny2 -> addReg2(s4);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "DIVF") {
				Tiny* tiny = new Tiny();
				string s = string("move");
				string s2 = string((*its) -> reg1);
				string s3 = string((*its) -> reg2);
				string s4 = string((*its) -> reg3);
				string r = string("r");
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				if (s3.find("!T") != string::npos) {
					s3.erase(0,2);
					s3 = r + s3;
				}
				if (s4.find("!T") != string::npos) {
					s4.erase(0,2);
					s4 = r + s4;
				}
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny -> addReg2(s4);
				tiny_list.push_back(tiny);
				Tiny* tiny2 = new Tiny();
				s = string("divr");
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s3);
				tiny2 -> addReg2(s4);
				tiny_list.push_back(tiny2);
			}
		}
	}

%}

%union{
	struct ID_List* id_l;
	char* s;
	struct Param_Decl* p_decl;
	struct Param_Decl_List* p_list;
	struct ASTNode* AST;
	struct toList* mL;
}

%type <s> id str var_type any_type ;
%type <id_l> id_list id_tail;
%type <p_decl> param_decl;
%type <p_list> param_decl_list param_decl_tail;
%type <AST> expr expr_prefix factor addop mulop factor_prefix postfix_expr primary call_expr expr_list;
%type <mL> assign_expr read_stmt write_stmt return_stmt;

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
%token <s>	_PLUS
%token <s>	_MINUS
%token <s>	_MUL
%token <s>	_DIV
%token	_NQ
%token	_GT
%token	_LT
%token	_OPENP
%token  _CLOSEP
%token	_SEMICOLON
%token	_COMMA
%token	_GTE
%token	_LTE
%token	_EQ
%token	<s> IDENTIFIER
%token	<s> FLOATLITERAL
%token	<s> INTLITERAL
%token	<s> STRINGLITERAL
%token	COMMENT
%token	WHITESPACE

%start program

%%
program:	_PRG id _BGN pgm_body _END 
			{
				buffer << "\n\n;IR code" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				buffer << ";LABEL FUNC_main" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				buffer << ";LINK" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				print_toList();
				buffer << ";RET" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				insert_threeAC();
				//print_buffer();
				print_threeAC();
				addTinyList();
				print_tinylist();
				cout << "sys halt" << endl;
			};
id:		IDENTIFIER ;
pgm_body:	decl func_declarations ;
decl:		string_decl decl | var_decl decl | /* empty */ ;

/* Global String Declaration */
string_decl:	_STRING id _ASSIGN str _SEMICOLON 
		{
			stringList[$2] = $4;
		};
str:		STRINGLITERAL ;

/* Variable Declaration */
var_decl:	var_type id_list
		{
			if (!strcmp($1,"FLOAT")) 
			{
				while ($2 != NULL)
				{
					floatList.push_back($2 -> id);
					$2 = $2 -> id_tail;
				}
			}
			else
			{
				while ($2 != NULL)
				{
					intList.push_back($2 -> id);
					$2 = $2 -> id_tail;
				}
			}
		} 
		_SEMICOLON ;
var_type:	_FLOAT | _INT ;
any_type:	var_type | _VOID ;
id_list:	id id_tail {$$ = new ID_List(); $$->addID($1); $$->nextID($2);};
id_tail:	_COMMA id id_tail {$$ = new ID_List(); $$->addID($2); $$->nextID($3);}| {$$ = NULL;};

/* Function Paramater List */
param_decl_list:	param_decl param_decl_tail {$$ = new Param_Decl_List(); $$->addPD($1); $$->nextPD($2);} | {$$ = NULL;};
param_decl:			var_type id {$$ = new Param_Decl(); $$->addType($1); $$->addID($2);};
param_decl_tail:	_COMMA param_decl param_decl_tail {$$ = new Param_Decl_List(); $$->addPD($2); $$->nextPD($3);} | {$$ = NULL;};

/* Function Declarations */
func_declarations:	func_decl func_declarations | /* empty */ ;
func_decl:			_FNC any_type id _OPENP param_decl_list _CLOSEP _BGN func_body _END ;
func_body:			decl stmt_list ;

/* Statement List */
stmt_list:			stmt stmt_list | ;
stmt:				base_stmt | if_stmt | loop_stmt ;
base_stmt:			assign_stmt | read_stmt | write_stmt | control_stmt ;

/* Basic Statements */
assign_stmt:		assign_expr _SEMICOLON ;
assign_expr:		id _ASSIGN expr 
			{
				$$ = new toList(); 
				$$ -> addDestination($1);
				$$ -> addDestType(findType($1));
				$$ -> addNode($3);
				$$ -> addOp((char*)"ASSIGN");
				myList.push_back($$);
			};
read_stmt:		_RD _OPENP id_list _CLOSEP _SEMICOLON 
			{
				$$ = new toList();
				$$ -> addDestination((char*)"READ");
				$$ -> addIDList($3);
				$$ -> addOp((char*)"READ");
				myList.push_back($$);
			};
write_stmt:		_WR _OPENP id_list _CLOSEP _SEMICOLON 
			{
				$$ = new toList();
				$$ -> addDestination((char*)"WRITE");
				$$ -> addIDList($3);
				$$ -> addOp((char*)"WRITE");
				myList.push_back($$);
			};
return_stmt:	_RTN expr _SEMICOLON 
			{
				$$ = new toList();
				$$ -> addDestination((char*)"RETURN");
				$$ -> addNode($2);
				$$ -> addOp((char*)"RETURN");
				myList.push_back($$);
			};

/* Expressions */
expr:			expr_prefix factor 
			{
				if ($1->sign == NULL && $1->id == NULL && $1->type == NULL && $1->left == NULL && $1->right == NULL) 
				{
					$$ = new ASTNode();
					$$ = $2;
					$$ -> addPrimary(prim);
				}
				else
				{
					$$ = new ASTNode();
					$$ = $1;
					$$ -> right = $2;
					$$ -> addPrimary(prim);
				}
				prim++;
			};
expr_prefix:		expr_prefix factor addop 
			{ 
				if ($1->sign == NULL && $1->id == NULL && $1->type == NULL && $1->left == NULL && $1->right == NULL) 
				{ 
					$3 -> left = $2;
					$$ = $3;
				} 
				else 
				{ 
					$1 -> right = $2;
					$3 -> left = $1;
					$$ = $3;
				}
			}| 
			{ 
				$$ = new ASTNode(); 
				$$ -> addPrimary(prim);
			};
factor:		factor_prefix postfix_expr 
		{
			if ($1->sign == NULL && $1->id == NULL && $1->type == NULL && $1->left == NULL && $1->right == NULL) 
			{
				$$ = new ASTNode();
				$$ = $2;
				$$ -> addPrimary(prim);
			}
			else
			{
				$$ -> left = $2;
			}
						
		};
factor_prefix:		factor_prefix postfix_expr mulop
			{
				if ($1->sign == NULL && $1->id == NULL && $1->type == NULL && $1->left == NULL && $1->right == NULL) 
				{
					$3 -> right = $2;
					$$ = $3;
				}
				else 
				{ 
					$1 -> left = $2;
					$3 -> right = $1;
					$$ = $3;
				}
			} | 
			{
				$$ = new ASTNode();
				$$ -> addPrimary(prim);
			};
postfix_expr:		primary 
			{
				$$ = new ASTNode();
				$$ = $1;
				$$ -> addPrimary(prim);
			} | call_expr 
			{
				$$ = new ASTNode();
				$$ = $1;
				$$ -> addPrimary(prim);
			};
call_expr:		id _OPENP expr_list _CLOSEP 
			{
				$$ = new ASTNode();
				$$ = $3;
				$$ -> addPrimary(prim);
			};
expr_list:		expr expr_list_tail | {$$ = NULL;};
expr_list_tail:	_COMMA expr expr_list_tail | ;
primary:	_OPENP expr _CLOSEP 
			{
				$$ = new ASTNode();
				$$ = $2;
			}
			| id 
			{
				$$ = new ASTNode();
				$$ -> addID($1);
				$$ -> addType(findType($1));
				$$ -> addPrimary(prim);
			} | 
			INTLITERAL 
			{
				$$ = new ASTNode();
				$$ -> addType((char*)"INTLITERAL");
				$$ -> addID($1);
				$$ -> addPrimary(prim);
			} |
			FLOATLITERAL 
			{
				$$ = new ASTNode();
				$$ -> addType((char*)"FLOATLITERAL");
				long double temp = atof($1);
				char* convert = new char[10];
				strcpy(convert, to_string(temp).c_str());
				$$ -> addID(convert);
				$$ -> addPrimary(prim);
			};
addop:			_PLUS 
			{ 
				$$ = new ASTNode(); 
				$$ -> addSign($1);
				$$ -> addPrimary(prim);
			} | 
			_MINUS 
			{ 
				$$ = new ASTNode(); 
				$$ -> addSign($1);
				$$ -> addPrimary(prim);
			};
mulop:			_MUL 
			{ 
				$$ = new ASTNode(); 
				$$ -> addSign($1);
				$$ -> addPrimary(prim);
			}| 
			_DIV 
			{ 
				$$ = new ASTNode(); 
				$$ -> addSign($1);
				$$ -> addPrimary(prim);
			};

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
