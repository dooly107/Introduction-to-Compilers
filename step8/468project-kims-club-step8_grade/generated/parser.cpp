/* A Bison parser, made by GNU Bison 3.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/parser.yy" /* yacc.c:339  */

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
	#include <regex>
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
	list <char*> globalintList;
	list <char*> globalfloatList;
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
	long long scope_count = 1;
	list <string> conditions;
	int global_var = 0;

	//Step6 variable
	long long link_num;
	int link_count_enable = 0;
	list <char *> param_intList;
	list <char *> param_floatList;
	char return_reg[10];
	int insert_expr_list = 0;
	int from_call = 0;
	list <ASTNode *> exprList;
	list <char *> comp_exprList;
	char comb_expr[40];
	int from_call_expr = 0;
	string call_expr_id;
	char new_reg1[10];
	char new_reg2[10];
	char new_reg3[10];
	long long return_reg_place = 0;
	bool inMain = false;

	char temp1[10];
	char temp2[10];
	char temp3[10];

	//Step7 variable
	string reg4value[4] = {"", "", "", ""};
	bool reg4dirty[4] = {false};
	int reg200[200] = {-1};
	list <Tiny*> new_tiny_list;


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

	//Step5

	void clear_toList() {
		myList.clear();
	}

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
		for (it=param_intList.begin(); it!=param_intList.end(); ++it) {
			if (!strcmp(*it, id)) {
				temp = (char*)"INT";
				return temp;
			}
		}
		for (it=param_floatList.begin(); it!=param_floatList.end(); ++it) {
			if (!strcmp(*it, id)) {
				temp = (char*)"FLOAT";
				return temp;
			}
		}
		for (it=globalintList.begin(); it!=globalintList.end(); ++it) {
			if (!strcmp(*it, id)) {
				temp = (char*)"INT";
				return temp;
			}
		}
		for (it=globalfloatList.begin(); it!=globalfloatList.end(); ++it) {
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

	char* find_fromList(char* reg) {
		list<char *>::iterator it;
		long long count = 1;
		for (it=intList.begin(); it!=intList.end(); ++it) {
			if (!strcmp((*it), reg)) {
				strcpy(return_reg, "$");
				strcat(return_reg, to_string((count * -1)).c_str());
				return return_reg;
			}
			count++;
		}
		count = 1;
		for (it=floatList.begin(); it!=floatList.end(); ++it) {
			if (!strcmp((*it), reg)) {
				strcpy(return_reg, "$");
				strcat(return_reg, to_string((count * -1)).c_str());
				return return_reg;
			}
			count++;
		}
		count = 1;
		for (it=param_intList.begin(); it!=param_intList.end(); ++it) {
			if (!strcmp((*it), reg)) {
				strcpy(return_reg, "$");
				strcat(return_reg, to_string((count + 1)).c_str());
				return return_reg;
			}
			count++;
		}
		count = 1;
		for (it=param_floatList.begin(); it!=param_floatList.end(); ++it) {
			if (!strcmp((*it), reg)) {
				strcpy(return_reg, "$");
				strcat(return_reg, to_string((count + 1)).c_str());
				return return_reg;
			}
			count++;
		}
		return reg;
	}

	void print_fromList() {
		list<char *>::iterator it;
		int count = 1;
		for (it=intList.begin(); it!=intList.end(); ++it) {
			cout << (*it) << "intList " << count << endl;
		}
		for (it=floatList.begin(); it!=floatList.end(); ++it) {
			cout << (*it) << "floatList " << count << endl;
		}
		for (it=param_intList.begin(); it!=param_intList.end(); ++it) {
			cout << (*it) << "param_intList " << count << endl;
		}
		for (it=param_floatList.begin(); it!=param_floatList.end(); ++it) {
			cout << (*it) << "param_floatList " << count << endl;
		}
	}

	void push_ir(char* op, char* reg1, char* reg2, char* reg3) {
		push = new IR();
		push -> addOp(op);
		if (reg1 != NULL) {
			strcpy(new_reg1, find_fromList(reg1));
			push -> addReg1(new_reg1);
		}
		else {
			push -> addReg1(reg1);
		}
		if (reg2 != NULL) {
			strcpy(new_reg2, find_fromList(reg2));
			push -> addReg2(new_reg2);
		}
		else {
			push -> addReg2(reg2);
		}
		if (reg3 != NULL) {
			strcpy(new_reg3, find_fromList(reg3));
			push -> addReg3(new_reg3);
		}
		else {
			push -> addReg3(reg3);
		}
		buffer << ";" << push -> op << " " << push -> reg1 << " " << push -> reg2 << " " << push -> reg3 << endl;
		threeAC.push_back(buffer.str());
		buffer.str("");
	}

	void traverse(ASTNode* node, char* type, char* scope) {
		if (node == NULL) {
			return;
		}
		traverse(node -> left, type, scope);
		traverse(node -> right, type, scope);
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
			else if (!strcmp(node -> sign, ">")) {
				if (!(!strcmp(node -> right -> type, "INTLITERAL") || !strcmp(node -> right -> type, "FLOATLITERAL"))) {
					char* ty = findType(node -> right -> id);
					char* right_reg = find_fromList(node -> right -> id);
					if (!strcmp(ty, "INT")) {
						buffer << ";STOREI " << right_reg << " !T" << to_string(reg_count) << endl;
					}
					else {
						buffer << ";STOREF " << right_reg << " !T" << to_string(reg_count) << endl;
					}
					threeAC.push_back(buffer.str());
					buffer.str("");
					strcpy(temp1, "LE");
					strcat(temp1, type);
					char* temp_reg = new char[10];
					strcpy(temp_reg, "!T");
					strcat(temp_reg, to_string(reg_count).c_str());
					push_ir(temp1, node -> left -> id, temp_reg, scope);
					buffer.str("");
					reg_count++;
				}
				else {
					strcpy(temp1, "LE");
					strcat(temp1, type);
					push_ir(temp1, node -> left -> id, node -> right -> id, scope);
				}
				node -> left = NULL;
				node -> right = NULL;
				char* temp3 = new char[20];
				strcpy(temp3, temp2);
				node -> id = temp3;
				node -> sign = NULL;
				node -> type = (char*)"CONDITION";
				reg_count++;
			}
			else if (!strcmp(node -> sign, "!=")) {
				if (!(!strcmp(node -> right -> type, "INTLITERAL") || !strcmp(node -> right -> type, "FLOATLITERAL"))) {
					char* ty = findType(node -> right -> id);
					char* right_reg = find_fromList(node -> right -> id);
					if (!strcmp(ty, "INT")) {
						buffer << ";STOREI " << right_reg << " !T" << to_string(reg_count) << endl;
					}
					else {
						buffer << ";STOREF " << right_reg << " !T" << to_string(reg_count) << endl;
					}
					threeAC.push_back(buffer.str());
					buffer.str("");
					strcpy(temp1, "EQ");
					strcat(temp1, type);
					char* temp_reg = new char[10];
					strcpy(temp_reg, "!T");
					strcat(temp_reg, to_string(reg_count).c_str());
					push_ir(temp1, node -> left -> id, temp_reg, scope);
					buffer.str("");
					reg_count++;
				}
				else {
					strcpy(temp1, "EQ");
					strcat(temp1, type);
					push_ir(temp1, node -> left -> id, node -> right -> id, scope);
				}
				node -> left = NULL;
				node -> right = NULL;
				char* temp3 = new char[20];
				strcpy(temp3, temp2);
				node -> id = temp3;
				node -> sign = NULL;
				node -> type = (char*)"CONDITION";
				reg_count++;
			}
			else if (!strcmp(node -> sign, "=")) {
				if (!(!strcmp(node -> right -> type, "INTLITERAL") || !strcmp(node -> right -> type, "FLOATLITERAL"))) {
					char* ty = findType(node -> right -> id);
					char* right_reg = find_fromList(node -> right -> id);
					if (!strcmp(ty, "INT")) {
						buffer << ";STOREI " << right_reg << " !T" << to_string(reg_count) << endl;
					}
					else {
						buffer << ";STOREF " << right_reg << " !T" << to_string(reg_count) << endl;
					}
					threeAC.push_back(buffer.str());
					buffer.str("");
					strcpy(temp1, "NE");
					strcat(temp1, type);
					char* temp_reg = new char[10];
					strcpy(temp_reg, "!T");
					strcat(temp_reg, to_string(reg_count).c_str());
					push_ir(temp1, node -> left -> id, temp_reg, scope);
					buffer.str("");
					reg_count++;
				}
				else {
					strcpy(temp1, "NE");
					strcat(temp1, type);
					push_ir(temp1, node -> left -> id, node -> right -> id, scope);
				}
				node -> left = NULL;
				node -> right = NULL;
				char* temp3 = new char[20];
				strcpy(temp3, temp2);
				node -> id = temp3;
				node -> sign = NULL;
				node -> type = (char*)"CONDITION";
				reg_count++;
			}
			else if (!strcmp(node -> sign, "<")) {
				if (!(!strcmp(node -> right -> type, "INTLITERAL") || !strcmp(node -> right -> type, "FLOATLITERAL"))) {
					char* ty = findType(node -> right -> id);
					char* right_reg = find_fromList(node -> right -> id);
					if (!strcmp(ty, "INT")) {
						buffer << ";STOREI " << right_reg << " !T" << to_string(reg_count) << endl;
					}
					else {
						buffer << ";STOREF " << right_reg << " !T" << to_string(reg_count) << endl;
					}
					threeAC.push_back(buffer.str());
					buffer.str("");
					strcpy(temp1, "GE");
					strcat(temp1, type);
					char* temp_reg = new char[10];
					strcpy(temp_reg, "!T");
					strcat(temp_reg, to_string(reg_count).c_str());
					push_ir(temp1, node -> left -> id, temp_reg, scope);
					buffer.str("");
					reg_count++;
				}
				else {
					strcpy(temp1, "GE");
					strcat(temp1, type);
					push_ir(temp1, node -> left -> id, node -> right -> id, scope);
				}
				node -> left = NULL;
				node -> right = NULL;
				char* temp3 = new char[20];
				strcpy(temp3, temp2);
				node -> id = temp3;
				node -> sign = NULL;
				node -> type = (char*)"CONDITION";
				reg_count++;
			}
			else if (!strcmp(node -> sign, "<=")) {
				if (!(!strcmp(node -> right -> type, "INTLITERAL") || !strcmp(node -> right -> type, "FLOATLITERAL"))) {
					char* ty = findType(node -> right -> id);
					char* right_reg = find_fromList(node -> right -> id);
					if (!strcmp(ty, "INT")) {
						buffer << ";STOREI " << right_reg << " !T" << to_string(reg_count) << endl;
					}
					else {
						buffer << ";STOREF " << right_reg << " !T" << to_string(reg_count) << endl;
					}
					threeAC.push_back(buffer.str());
					buffer.str("");
					strcpy(temp1, "GT");
					strcat(temp1, type);
					char* temp_reg = new char[10];
					strcpy(temp_reg, "!T");
					strcat(temp_reg, to_string(reg_count).c_str());
					push_ir(temp1, node -> left -> id, temp_reg, scope);
					buffer.str("");
					reg_count++;
				}
				else {
					
					strcpy(temp1, "GT");
					strcat(temp1, type);
					push_ir(temp1, node -> left -> id, node -> right -> id, scope);
				}
				node -> left = NULL;
				node -> right = NULL;
				char* temp3 = new char[20];
				strcpy(temp3, temp2);
				node -> id = temp3;
				node -> sign = NULL;
				node -> type = (char*)"CONDITION";
				reg_count++;
			}
			else if (!strcmp(node -> sign, ">=")) {
				if (!(!strcmp(node -> right -> type, "INTLITERAL") || !strcmp(node -> right -> type, "FLOATLITERAL"))) {
					char* ty = findType(node -> right -> id);
					char* right_reg = find_fromList(node -> right -> id);
					if (!strcmp(ty, "INT")) {
						buffer << ";STOREI " << right_reg << " !T" << to_string(reg_count) << endl;
					}
					else {
						buffer << ";STOREF " << right_reg << " !T" << to_string(reg_count) << endl;
					}
					threeAC.push_back(buffer.str());
					buffer.str("");
					strcpy(temp1, "LT");
					strcat(temp1, type);
					char* temp_reg = new char[10];
					strcpy(temp_reg, "!T");
					strcat(temp_reg, to_string(reg_count).c_str());
					push_ir(temp1, node -> left -> id, temp_reg, scope);
					buffer.str("");
					reg_count++;
				}
				else {

					strcpy(temp1, "LT");
					strcat(temp1, type);
					push_ir(temp1, node -> left -> id, node -> right -> id, scope);
				}
				node -> left = NULL;
				node -> right = NULL;
				char* temp3 = new char[20];
				strcpy(temp3, temp2);
				node -> id = temp3;
				node -> sign = NULL;
				node -> type = (char*)"CONDITION";
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
			node -> type = (char*)"INTLITERAL";
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
			node -> type = (char*)"FLOATLITERAL";
			reg_count++;
		}
	}

	void print_toList() {
		list<toList*>::iterator it;
		for (it=myList.begin(); it!=myList.end(); ++it) {
			if (!strcmp((*it) -> op, "IF_COND_START")) {
				if ((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "INT")) {
					char* ifstart = new char[20];
					strcpy(ifstart, "ELSE_");
					strcat(ifstart, to_string(scope_count++).c_str());
					//push to condition list
					conditions.push_back(ifstart);
					traverse((*it) -> node, (char*)"I", ifstart);
				}
				else if ((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "FLOAT")) {
					char* ifstart = new char[20];
					strcpy(ifstart, "ELSE_");
					strcat(ifstart, to_string(scope_count++).c_str());
					//push to condition list
					conditions.push_back(ifstart);
					traverse((*it) -> node, (char*)"F", ifstart);
				}
			}
			else if (!strcmp((*it) -> op, "IF_COND_END")) {
				//FIND END_IF_ELSE_
				size_t found;
				char* return_if_else = new char[20];
				list<string>::reverse_iterator rev_it;
				for (rev_it=conditions.rbegin(); rev_it!=conditions.rend(); ++rev_it) {
					found = (*rev_it).find("END_IF_ELSE_");
					if (found == 0) {
						strcpy(return_if_else, (*rev_it).c_str());
						break;
					}
				}
				buffer << ";LABEL " << return_if_else << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				conditions.remove(return_if_else);
			}
			else if (!strcmp((*it) -> op, "WHILE_COND_START")) {
				/*
				if ((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "INT")) {
					buffer << ";LABEL WHILE_START_" << to_string(scope_count).c_str() << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					//push to condition list
					buffer << "WHILE_START_" << to_string(scope_count++).c_str() << endl;
					conditions.push_back(buffer.str());
					buffer.str("");
					char* whileend = new char[20];
					strcpy(whileend, "WHILE_END_");
					strcat(whileend, to_string(scope_count++).c_str());
					conditions.push_back(whileend);
					traverse((*it) -> node, (char*)"I", whileend);
				}
				else if ((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "FLOAT")) {
					buffer << ";LABEL WHILE_START_" << to_string(scope_count).c_str() << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					//push to condition list
					buffer << "WHILE_START_" << to_string(scope_count++).c_str() << endl;
					conditions.push_back(buffer.str());
					buffer.str("");
					char* whileend = new char[20];
					strcpy(whileend, "WHILE_END_");
					strcat(whileend, to_string(scope_count++).c_str());
					conditions.push_back(whileend);
					traverse((*it) -> node, (char*)"F", whileend);
				}
				*/
				
				if ((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "INT")) {
					buffer << ";LABEL WHILE_LOOP_START_" << to_string(scope_count).c_str() << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					char* whilestart = new char[20];
					strcpy(whilestart, "WHILE_LOOP_START_");
					strcat(whilestart, to_string(scope_count++).c_str());
					//push to condition list
					conditions.push_back(whilestart);
					char* whileend = new char[20];
					strcpy(whileend, "WHILE_LOOP_END_");
					strcat(whileend, to_string(scope_count++).c_str());
					//push to condition list
					conditions.push_back(whileend);
					traverse((*it) -> node, (char*)"I", whileend);
				}
				else if ((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "FLOAT")) {
					buffer << ";LABEL WHILE_LOOP_START_" << to_string(scope_count).c_str() << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					char* whilestart = new char[20];
					strcpy(whilestart, "WHILE_LOOP_START_");
					strcat(whilestart, to_string(scope_count++).c_str());
					//push to condition list
					conditions.push_back(whilestart);
					char* whileend = new char[20];
					strcpy(whileend, "WHILE_LOOP_END_");
					strcat(whileend, to_string(scope_count++).c_str());
					//push to condition list
					conditions.push_back(whileend);
					traverse((*it) -> node, (char*)"F", whileend);
				}
				
			}

			else if (!strcmp((*it) -> op, "WHILE_COND_END")) {
				/*
				//FIND WHILE_START_
				size_t found;
				char* return_while_start = new char[20];
				list<string>::reverse_iterator rev_it;
				for (rev_it=conditions.rbegin(); rev_it!=conditions.rend(); ++rev_it) {
					found = (*rev_it).find("WHILE_START_");
					if (found == 0) {
						strcpy(return_while_start, (*rev_it).c_str());
						break;
					}
				}
				buffer << ";JUMP " << return_while_start << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				conditions.remove(return_while_start);

				//FIND WHILE_START_
				char* return_while_end = new char[20];
				for (rev_it=conditions.rbegin(); rev_it!=conditions.rend(); ++rev_it) {
					found = (*rev_it).find("WHILE_END_");
					if (found == 0) {
						strcpy(return_while_end, (*rev_it).c_str());
						break;
					}
				}
				buffer << ";LABEL " << return_while_end << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				conditions.remove(return_while_end);
				*/
				//FIND WHILE_LOOP_START_
				size_t found1;
				char* return_while_start = new char[20];
				list<string>::reverse_iterator rev_it1;
				for (rev_it1=conditions.rbegin(); rev_it1!=conditions.rend(); ++rev_it1) {
					found1 = (*rev_it1).find("WHILE_LOOP_START_");
					if (found1 == 0) {
						strcpy(return_while_start, (*rev_it1).c_str());
						break;
					}
				}
				buffer << ";JUMP " << return_while_start << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				conditions.remove(return_while_start);

				//FIND WHILE_LOOP_END_
				size_t found2;
				char* return_while_end = new char[20];
				list<string>::reverse_iterator rev_it2;
				for (rev_it2=conditions.rbegin(); rev_it2!=conditions.rend(); ++rev_it2) {
					found2 = (*rev_it2).find("WHILE_LOOP_END");
					if (found2 == 0) {
						strcpy(return_while_end, (*rev_it2).c_str());
						break;
					}
				}
				buffer << ";LABEL " << return_while_end << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				conditions.remove(return_while_end);
			}

			else if (!strcmp((*it) -> op, "ELSE_COND")) {
				buffer << ";JUMP END_IF_ELSE_" << to_string(scope_count).c_str() << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");

				//push to condition list
				buffer << "END_IF_ELSE_" << to_string(scope_count++).c_str() << endl;
				conditions.push_back(buffer.str());
				buffer.str("");

				//FIND ELSE_
				size_t found;
				char* return_else_label = new char[10];
				list<string>::reverse_iterator rev_it;
				for (rev_it=conditions.rbegin(); rev_it!=conditions.rend(); ++rev_it) {
					found = (*rev_it).find("ELSE_");
					if (found == 0) {
						strcpy(return_else_label, (*rev_it).c_str());
						break;
					}
				}
				buffer << ";LABEL " << return_else_label << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				conditions.remove(return_else_label);
			}

			else if (!strcmp((*it) -> op, "ASSIGN")) {
				if ((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "INT")) {
					traverse((*it) -> node, (char*)"I", NULL);
					if ((!strcmp((*it) -> node -> type, "INT") || !strcmp((*it) -> node -> type, "FLOAT")) && from_call_expr == 0) {
						buffer << ";STOREI " << (*it) -> node -> id << " !T" << to_string(reg_count) << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						buffer << ";STOREI " << " !T" << to_string(reg_count) << " !T" << to_string(reg_count + 1) << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						reg_count++;
						buffer << ";STOREI " << "!T" << to_string(reg_count) << " " << (*it) -> destination << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						reg_count++;
					}
					else {
						reg_count--;
						if (from_call_expr == 0) {
							/*
							buffer << ";STOREI " << " !T" << to_string(reg_count) << " !T" << to_string(reg_count + 1) << endl;
							threeAC.push_back(buffer.str());
							buffer.str("");
							*/
							char* dest_id = find_fromList((*it) -> destination);
							buffer << ";STOREI " << "!T" << to_string(reg_count++) << " " << dest_id << endl;
							threeAC.push_back(buffer.str());
							buffer.str("");
							reg_count++;
						}
					}
				}
				else if (((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "FLOAT")) && from_call_expr == 0) {
					traverse((*it) -> node, (char*)"F", NULL);
					if (!strcmp((*it) -> node -> type, "INT") || !strcmp((*it) -> node -> type, "FLOAT")) {
						buffer << ";STOREF " << (*it) -> node -> id << " !T" << to_string(reg_count) << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						buffer << ";STOREF " << " !T" << to_string(reg_count) << " !T" << to_string(reg_count + 1) << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						reg_count++;
						buffer << ";STOREF " << "!T" << to_string(reg_count) << " " << (*it) -> destination << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						reg_count++;
					}
					else {
						reg_count--;
						if (from_call_expr == 0) {
							/*
							buffer << ";STOREF " << " !T" << to_string(reg_count) << " !T" << to_string(reg_count + 1) << endl;
							threeAC.push_back(buffer.str());
							buffer.str("");
							*/
							char* dest_id = find_fromList((*it) -> destination);
							buffer << ";STOREF " << "!T" << to_string(reg_count) << " " << dest_id << endl;
							threeAC.push_back(buffer.str());
							buffer.str("");
							reg_count++;
						}
					}
				}
			}
			else if (!strcmp((*it) -> op, "READ") || !strcmp((*it) -> op, "WRITE")) {
				while ((*it) -> ids != NULL) {
					char* temp;
					temp = findType((*it) -> ids -> id);
					char variable[20];
					strcpy(variable,find_fromList((*it) -> ids -> id));
					if (!strcmp(temp, "INT")) {
						buffer << ";" << (*it) -> destination << "I " << variable << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						(*it) -> ids = (*it) -> ids -> id_tail;
					}
					else if (!strcmp(temp, "FLOAT")) {
						buffer << ";" << (*it) -> destination << "F " << variable << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						(*it) -> ids = (*it) -> ids -> id_tail;
					}
					else {
						buffer << ";" << (*it) -> destination << "S " << variable << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						(*it) -> ids = (*it) -> ids -> id_tail;
					}
				}
			}
			else if (!strcmp((*it) -> op, "RETURN")) {
				if (inMain == false) {
					if ((*it) -> node -> id != NULL) {
						char variable[10];
						strcpy(variable,find_fromList((*it) -> node -> id));
						buffer << ";STORE" << (*it) -> node -> type[0] << " " << variable << " !T" << to_string(reg_count) << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						buffer << ";STORE" << (*it) -> node -> type[0] << " !T" << to_string(reg_count) << " 	$" << to_string(6 + return_reg_place) << endl;
						reg_count++;
						threeAC.push_back(buffer.str());
						buffer.str("");
					}
					else {	
						char* type_return = findType((*it) -> node -> right -> id);
						if (!strcmp(type_return, "INT")) {
							traverse((*it) -> node, (char*)"I", NULL);
						}
						else {
							traverse((*it) -> node, (char*)"F", NULL);
						}
						buffer << ";STORE" << type_return[0] << " !T" << to_string(reg_count - 1) << " $" <<	to_string(6 + return_reg_place) << endl;
						reg_count++;
						threeAC.push_back(buffer.str());
						buffer.str("");
					}
				}
				else if (!call_expr_id.empty()) {
				
				}
				if ((*it) -> node -> sign != NULL) {
					if (!strcmp((*it) -> node -> right -> type, "INT")) {
						traverse((*it) -> node, (char*)"I", NULL);
					}
					else {
						traverse((*it) -> node, (char*)"F", NULL);
					}
				}
				buffer << ";UNLINK" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				buffer << ";RET" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
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
		for (it=globalintList.begin(); it!=globalintList.end(); ++it) {
			Tiny* tiny = new Tiny();
			string s = string("var");
			tiny -> addOp(s);
			tiny -> addReg1(string((*it)));
			tiny_list.push_back(tiny);
		}
		for (it=globalfloatList.begin(); it!=globalfloatList.end(); ++it) {
			Tiny* tiny = new Tiny();
			string s = string("var");
			tiny -> addOp(s);
			tiny -> addReg1(string((*it)));
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
			else if (operation == "PUSHREGS") {
				long long count_push_register = 0;
				for (count_push_register = 0; count_push_register < 4; count_push_register++) {
					Tiny* tiny = new Tiny();
					string s = string("push");
					string s2 = string("r" + to_string(count_push_register));
					tiny -> addOp(s);
					tiny -> addReg1(s2);
					tiny_list.push_back(tiny);
				}
			}
			else if (operation == "POPREGS") {
				long long count_pop_register = 3;
				for (count_pop_register = 3; count_pop_register > -1; count_pop_register--) {
					Tiny* tiny = new Tiny();
					string s = string("pop");
					string s2 = string("r" + to_string(count_pop_register));
					tiny -> addOp(s);
					tiny -> addReg1(s2);
					tiny_list.push_back(tiny);
				}
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
			else if (operation == "UNLINK") {
				Tiny* tiny = new Tiny();
				string s = string("unlnk");
				tiny -> addOp(s);
				tiny_list.push_back(tiny);
			}
			else if (operation == "HALT") {
				Tiny* tiny = new Tiny();
				string s = string("sys halt");
				tiny -> addOp(s);
				tiny_list.push_back(tiny);
			}
			else if (operation == "RET") {
				Tiny* tiny = new Tiny();
				string s = string("ret");
				tiny -> addOp(s);
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
				string s2 = string("readr");
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
			else if (operation == "PUSH") {
				Tiny* tiny = new Tiny();
				string s = string("push");
				string s1 = string((*its) -> reg1);
				string r = string("r");
				if (s1.find("!T") != string::npos) {
					s1.erase(0,2);
					s1 = r + s1;
				}
				tiny -> addOp(s);
				tiny -> addReg1(s1);
				tiny_list.push_back(tiny);
			}
			else if (operation == "POP") {
				Tiny* tiny = new Tiny();
				string s = string("pop");
				string s1 = string((*its) -> reg1);
				string r = string("r");
				if (s1.find("!T") != string::npos) {
					s1.erase(0,2);
					s1 = r + s1;
				}
				tiny -> addOp(s);
				tiny -> addReg1(s1);
				tiny_list.push_back(tiny);
			}
			else if (operation == "JSR") {
				Tiny* tiny = new Tiny();
				string s = string("jsr");
				string s2 = string((*its) -> reg1);
				string r = string("r");
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny_list.push_back(tiny);
			}
			else if (operation == "LABEL") {
				Tiny* tiny = new Tiny();
				string s = string("label");
				string s2 = string((*its) -> reg1);
				string r = string("r");
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				tiny_list.push_back(tiny);
			}
			else if (operation == "JUMP") {
				Tiny* tiny = new Tiny();
				string s = string("jmp");
				string s2 = string((*its) -> reg1);
				string r = string("r");
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny_list.push_back(tiny);
			} 
			else if (operation == "LINK") {
				Tiny* tiny = new Tiny();
				string s = string("link");
				string s2 = string((*its) -> reg1);
				string r = string("r");
				tiny -> addOp(s);
				tiny -> addReg1(s2);
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny_list.push_back(tiny);
			}
			else if (operation == "EQI") {
				Tiny* tiny = new Tiny();
				string s = string("cmpi");
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
				Tiny* tiny2 = new Tiny();
				s = string("jeq");
				s2 = string((*its) -> reg3);
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s2);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "NEI") {
				Tiny* tiny = new Tiny();
				string s = string("cmpi");
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
				Tiny* tiny2 = new Tiny();
				s = string("jne");
				s2 = string((*its) -> reg3);
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s2);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "LEI") {
				Tiny* tiny = new Tiny();
				string s = string("cmpi");
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
				Tiny* tiny2 = new Tiny();
				s = string("jle");
				s2 = string((*its) -> reg3);
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s2);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "GEI") {
				Tiny* tiny = new Tiny();
				string s = string("cmpi");
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
				Tiny* tiny2 = new Tiny();
				s = string("jge");
				s2 = string((*its) -> reg3);
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s2);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "GTI") {
				Tiny* tiny = new Tiny();
				string s = string("cmpi");
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
				Tiny* tiny2 = new Tiny();
				s = string("jgt");
				s2 = string((*its) -> reg3);
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s2);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "LTI") {
				Tiny* tiny = new Tiny();
				string s = string("cmpi");
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
				Tiny* tiny2 = new Tiny();
				s = string("jlt");
				s2 = string((*its) -> reg3);
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s2);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "EQF") {
				Tiny* tiny = new Tiny();
				string s = string("cmpr");
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
				Tiny* tiny2 = new Tiny();
				s = string("jeq");
				s2 = string((*its) -> reg3);
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s2);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "NEF") {
				Tiny* tiny = new Tiny();
				string s = string("cmpr");
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
				Tiny* tiny2 = new Tiny();
				s = string("jne");
				s2 = string((*its) -> reg3);
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s2);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "LEF") {
				Tiny* tiny = new Tiny();
				string s = string("cmpr");
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
				Tiny* tiny2 = new Tiny();
				s = string("jle");
				s2 = string((*its) -> reg3);
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s2);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "GEF") {
				Tiny* tiny = new Tiny();
				string s = string("cmpr");
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
				Tiny* tiny2 = new Tiny();
				s = string("jge");
				s2 = string((*its) -> reg3);
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s2);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "GTF") {
				Tiny* tiny = new Tiny();
				string s = string("cmpr");
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
				Tiny* tiny2 = new Tiny();
				s = string("jgt");
				s2 = string((*its) -> reg3);
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s2);
				tiny_list.push_back(tiny2);
			}
			else if (operation == "LTF") {
				Tiny* tiny = new Tiny();
				string s = string("cmpr");
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
				Tiny* tiny2 = new Tiny();
				s = string("jlt");
				s2 = string((*its) -> reg3);
				if (s2.find("!T") != string::npos) {
					s2.erase(0,2);
					s2 = r + s2;
				}
				tiny2 -> addOp(s);
				tiny2 -> addReg1(s2);
				tiny_list.push_back(tiny2);
			}
		}
	}

	void print_conditions() {
		list<string>::iterator it;
		for (it=conditions.begin(); it!=conditions.end(); ++it) {
			cout << (*it) << endl;
		}
	}

	void clear_varlist() {
		intList.clear();
		floatList.clear();
		param_intList.clear();
		param_floatList.clear();
		exprList.clear();
		comp_exprList.clear();
	}

	//Step 6

	void combine_expr(ASTNode* exprNode) {
		if (exprNode == NULL) {
			return;
		}
		combine_expr(exprNode -> left);
		if (comb_expr[0] == '\0') {
			if (exprNode -> id) {
				strcpy(comb_expr, exprNode -> id);
			}
			else if (exprNode -> sign) {
				strcpy(comb_expr, exprNode -> sign);
			}
		}
		else {
			if (exprNode -> id) {
				strcat(comb_expr, exprNode -> id);
			}
			else if (exprNode -> sign) {
				strcat(comb_expr, exprNode -> sign);
			}
		}
		combine_expr(exprNode -> right);
	}

	void print_exprList() {
		list<char*>::iterator it;
		for (it=comp_exprList.begin(); it!=comp_exprList.end(); ++it) {
			cout << (*it) << endl;
		}
	}

	//WORK ON HARDCOPY
	void push_comp_exprList() {
		list<ASTNode *>::iterator it;
		for (it=exprList.begin(); it!=exprList.end(); ++it) {
			combine_expr((*it));
			char* cpyexpr = new char[40];
			strcpy(cpyexpr, comb_expr);
			comp_exprList.push_back(cpyexpr);
			memset(comb_expr, 0, sizeof(comb_expr));
		}
	}

	//Step7
	int find_empty() {
		int i;
		for (i = 0; i < 4; i++) {
			if (reg4value[i] == "") {
				break;
			}
		}
		return i;
	}

	int find200(string temp_reg) {
		string number = temp_reg;
		number.erase(0,1);
		int result = atoi(number.c_str());
		return result;
	}

	void print_newtinylist() {
		list<Tiny*>::iterator it;
		for (it=new_tiny_list.begin(); it!=new_tiny_list.end(); ++it) {
			cout << (*it) -> op << " " << (*it) -> reg1 << " " << (*it) -> reg2 << " " << endl;
		}
	}

	string remove4regValDir(string reg) {
		if (reg.at(0) != 'r') {
			return reg;
		}
		else {
			string number = reg;
			number.erase(0,1);
			long long result = atoi(number.c_str());
			long long getprevreg = reg200[result];
			reg4value[getprevreg] = "";
			reg4dirty[getprevreg] = false;
			string var = string("r") + to_string(getprevreg);
			return var;
		}
	}

	string mathValDir(string reg) {
		if (reg.at(0) != 'r') {
			return reg;
		}
		else {
			string number = reg;
			number.erase(0,1);
			long long result = atoi(number.c_str());
			long long getprevreg = reg200[result];
			string var = string("r") + to_string(getprevreg);
			return var;
		}
	}

	
	void newTinyList() {
		list<Tiny *>::iterator it;
		int advance = 0;
		int pushpopreg = 0;
		bool pushpop = false;
		long long index_reg4;
		for (it=tiny_list.begin(); it!=tiny_list.end(); ++it) {
			if ((*it) -> op == "str" || 
				(*it) -> op == "var" || 
				(*it) -> op == "jsr" || 
				(*it) -> op == "sys halt" || 
				(*it) -> op == "sys" || 
				(*it) -> op == "link" || 
				(*it) -> op == "jne" || 
				(*it) -> op == "jeq" || 
				(*it) -> op == "jge" || 
				(*it) -> op == "jle" || 
				(*it) -> op == "jgt" || 
				(*it) -> op == "jlt" || 
				(*it) -> op == "jmp" ||
				(*it) -> op == "label" ||
				(*it) -> op == "unlnk" || 
				(*it) -> op == "ret")
			{
				Tiny* tiny = new Tiny();
				tiny -> addOp((*it) -> op);
				tiny -> addReg1((*it) -> reg1);
				tiny -> addReg2((*it) -> reg2);
				new_tiny_list.push_back(tiny);
				advance++;
			}
			
			else if (((*it) -> op == "push" && (*it) -> reg1 == "") ||
					((*it) -> op == "pop" && (*it) -> reg1 == ""))
			{
				pushpop = true;
				Tiny* tiny = new Tiny();
				tiny -> addOp((*it) -> op);
				tiny -> addReg1((*it) -> reg1);
				tiny -> addReg2((*it) -> reg2);
				new_tiny_list.push_back(tiny);
				advance++;
			}
			else if (pushpop) {
				pushpopreg++;
				Tiny* tiny = new Tiny();
				tiny -> addOp((*it) -> op);
				tiny -> addReg1((*it) -> reg1);
				tiny -> addReg2((*it) -> reg2);
				new_tiny_list.push_back(tiny);
				advance++;
				if (pushpopreg == 4) {
					pushpop = false;
					pushpopreg = 0;
				}
			}
			else if ((*it) -> op == "cmpi" || (*it) -> op == "cmpr") {
				string reg1 = remove4regValDir((*it) -> reg1);
				string reg2 = remove4regValDir((*it) -> reg2);
				Tiny* tiny = new Tiny();
				tiny -> addOp((*it) -> op);
				tiny -> addReg1(reg1);
				tiny -> addReg2(reg2);
				new_tiny_list.push_back(tiny);
				advance++;
			}
			else if ((*it) -> op == "addi" ||
					 (*it) -> op == "addr" ||
					 (*it) -> op == "subi" ||
					 (*it) -> op == "subr" ||
					 (*it) -> op == "muli" ||
					 (*it) -> op == "mulr" ||
					 (*it) -> op == "divi" ||
					 (*it) -> op == "divr")
				{
					string reg1 = remove4regValDir((*it) -> reg1);
					string reg2 = mathValDir((*it) -> reg2);
					Tiny* tiny = new Tiny();
					tiny -> addOp((*it) -> op);
					tiny -> addReg1(reg1);
					tiny -> addReg2(reg2);
					new_tiny_list.push_back(tiny);
					advance++;
				}
			else if ((*it) -> op == "push" && (*it) -> reg1 != "")
			{
				string reg1 = remove4regValDir((*it) -> reg1);
				Tiny* tiny = new Tiny();
				tiny -> addOp((*it) -> op);
				tiny -> addReg1(reg1);
				new_tiny_list.push_back(tiny);
				advance++;
			}
			else if ((*it) -> op == "pop" && (*it) -> reg1 != "")
			{
				Tiny* tiny = new Tiny();
				tiny -> addOp((*it) -> op);
				index_reg4 = find_empty();
				reg4value[index_reg4] = (*it) -> reg1;
				reg4dirty[index_reg4] = true;
				long long x = find200((*it) -> reg1);
				reg200[x] = index_reg4;
				string r = string("r") + to_string(index_reg4);
				tiny -> addReg1(r);
				new_tiny_list.push_back(tiny);
				advance++;
			}
			else if ((*it) -> op == "move") {
				Tiny* tiny = new Tiny();
				tiny -> addOp((*it) -> op);
				if ((((*it) -> reg1).at(0) != 'r') && (((*it) -> reg2).at(0) == 'r')) {
					tiny -> addReg1((*it) -> reg1);
					index_reg4 = find_empty();
					reg4value[index_reg4] = (*it) -> reg1;
					reg4dirty[index_reg4] = true;
					long long x = find200((*it) -> reg2);
					reg200[x] = index_reg4;
					string r = string("r") + to_string(index_reg4);
					tiny -> addReg2(r);
				}
				else if ((((*it) -> reg1).at(0) == 'r') && (((*it) -> reg2).at(0) != 'r')) {
					string reg1 = remove4regValDir((*it) -> reg1);
					tiny -> addReg1(reg1);
					tiny -> addReg2((*it) -> reg2);
				}
				else {
					if (isdigit(((*it) -> reg1).at(1))) {
						string reg1 = remove4regValDir((*it) -> reg1);
						tiny -> addReg1(reg1);
						if (!isdigit(((*it) -> reg2).at(1))) {
							tiny -> addReg2((*it) -> reg2);
						}
						else {
							index_reg4 = find_empty();
							reg4value[index_reg4] = reg1;
							reg4dirty[index_reg4] = true;
							long long x = find200((*it) -> reg2);
							reg200[x] = index_reg4;
							string r = string("r") + to_string(index_reg4);
							tiny -> addReg2(r);
						}
					}
					else if (isdigit(((*it) -> reg2).at(1))) {
						tiny -> addReg1((*it) -> reg1);
						index_reg4 = find_empty();
						reg4value[index_reg4] = (*it) -> reg1;
						reg4dirty[index_reg4] = true;
						long long x = find200((*it) -> reg2);
						reg200[x] = index_reg4;
						string r = string("r") + to_string(index_reg4);
						tiny -> addReg2(r);
					}
					else {

					}
				}
				new_tiny_list.push_back(tiny);
				advance++;
			}
			
		}
	}
	

#line 2078 "generated/parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
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
#line 2013 "src/parser.yy" /* yacc.c:355  */

	struct ID_List* id_l;
	char* s;
	struct Param_Decl* p_decl;
	struct Param_Decl_List* p_list;
	struct ASTNode* AST;
	struct toList* mL;

#line 2169 "generated/parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GENERATED_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 2186 "generated/parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   127

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  2073,  2073,  2072,  2102,  2104,  2103,  2107,  2107,  2108,
    2120,  2127,  2131,  2130,  2162,  2162,  2163,  2163,  2164,  2165,
    2165,  2168,  2168,  2169,  2182,  2182,  2185,  2185,  2187,  2197,
    2186,  2210,  2213,  2213,  2214,  2214,  2214,  2215,  2215,  2215,
    2215,  2218,  2219,  2292,  2300,  2308,  2320,  2337,  2351,  2355,
    2369,  2383,  2387,  2392,  2398,  2409,  2408,  2415,  2417,  2416,
    2419,  2420,  2425,  2432,  2439,  2449,  2455,  2461,  2467,  2476,
    2475,  2506,  2505,  2514,  2521,  2534,  2549,  2565,  2565,  2565,
    2565,  2565,  2565,  2567,  2566,  2598,  2599
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_PRG", "_BGN", "_END", "_FNC", "_RD",
  "_WR", "_IF", "_ELSE", "_ENDIF", "_WHILE", "_ENDWH", "_RTN", "_INT",
  "_VOID", "_STRING", "_FLOAT", "_TRUE", "_FALSE", "_ASSIGN", "_PLUS",
  "_MINUS", "_MUL", "_DIV", "_NQ", "_GT", "_LT", "_OPENP", "_CLOSEP",
  "_SEMICOLON", "_COMMA", "_GTE", "_LTE", "_EQ", "IDENTIFIER",
  "FLOATLITERAL", "INTLITERAL", "STRINGLITERAL", "COMMENT", "WHITESPACE",
  "$accept", "program", "$@1", "id", "pgm_body", "$@2", "decl",
  "string_decl", "str", "var_decl", "$@3", "var_type", "any_type",
  "id_list", "id_tail", "param_decl_list", "param_decl", "param_decl_tail",
  "func_declarations", "func_decl", "$@4", "$@5", "func_body", "stmt_list",
  "stmt", "base_stmt", "assign_stmt", "assign_expr", "read_stmt",
  "write_stmt", "return_stmt", "expr", "expr_prefix", "factor",
  "factor_prefix", "postfix_expr", "call_expr", "expr_list", "$@6",
  "expr_list_tail", "$@7", "primary", "addop", "mulop", "if_stmt", "$@8",
  "else_part", "$@9", "cond", "compop", "while_stmt", "$@10",
  "control_stmt", "loop_stmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -61

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-61)))

#define YYTABLE_NINF -58

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      12,   -61,     5,   -17,   -61,   -61,    17,    -8,   -61,   -17,
     -61,    36,   -61,    -8,    -8,   -17,    24,   -61,    48,   -61,
     -61,    27,   -61,    18,    28,   -61,    48,   -17,   -61,    29,
     -61,    30,   -61,   -61,   -17,   -61,    27,   -61,   -61,   -61,
     -61,    33,     2,   -17,    34,    31,   -61,    52,     2,   -61,
     -61,    31,    -8,   -61,     4,    53,    40,    41,    42,    43,
     -61,    44,   -61,     4,   -61,   -61,    45,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -17,   -17,    15,    15,    46,
     -61,   -61,   -61,   -61,    49,    50,   -61,   -61,    -3,    51,
      55,   -61,    25,     0,   -61,    47,    56,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,    57,    26,   -61,   -61,   -61,   -61,   -61,    -8,
      -8,    58,    59,   -61,   -61,   -61,     4,     4,   -61,   -61,
      60,    63,    69,    61,   -61,   -61,    80,   -61,   -61,   -61,
      -8,   -61,   -61,     4,    61,   -61,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     4,     0,     9,    15,     0,
      14,     0,     5,     9,     9,     0,     0,     3,    27,     7,
       8,    20,    12,     0,     0,     6,    27,     0,    18,     0,
      11,     0,    17,    16,     0,    26,    20,    13,    10,    28,
      19,     0,    22,     0,     0,    25,    23,     0,     0,    21,
      29,    25,     9,    24,    33,     0,     0,     0,     0,     0,
      48,     0,    31,    33,    34,    37,     0,    38,    39,    85,
      35,    86,    40,    36,    30,     0,     0,    48,    48,     0,
      51,    48,    32,    41,     0,     0,    75,    76,     0,     0,
       0,    45,    46,     0,    42,     0,     0,    80,    78,    77,
      82,    81,    79,    48,    69,    83,    65,    66,    47,    48,
      64,    63,    62,    49,    53,    52,    43,    44,    74,     9,
       9,     0,    48,    67,    68,    50,    33,    33,    61,    55,
       0,    73,     0,    60,    54,    71,     0,    84,    48,    56,
       9,    70,    58,    33,    60,    72,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   -61,   -61,    -1,   -61,   -61,   -13,   -61,   -61,   -61,
     -61,   -20,   -61,   -23,    62,   -61,    54,    64,    68,   -61,
     -61,   -61,   -61,   -60,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -54,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -49,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,    19,   -61,
     -61,   -61,   -61,   -61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    61,    11,    18,    12,    13,    31,    14,
      29,    15,    34,    22,    28,    44,    45,    49,    25,    26,
      41,    52,    55,    62,    63,    64,    65,    66,    67,    68,
      69,    88,    80,    92,    93,   113,   114,   130,   133,   139,
     144,   115,   108,   125,    70,   119,   136,   140,    89,   103,
      71,   120,    72,    73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    20,     6,    82,    33,     4,    79,     8,    16,     9,
      10,    56,    57,    58,    21,     1,    59,     8,    60,     5,
      10,     7,    43,    97,    98,    99,    36,    94,    43,   109,
     100,   101,   102,    39,    86,    87,     5,   110,   111,    54,
       5,    17,    46,     8,    32,    23,    10,   106,   107,   118,
     123,   124,    84,    85,    24,   121,    50,    30,    74,    27,
      37,    38,    42,    48,    47,    81,   131,   132,   129,    75,
      76,    77,    78,   135,    21,    21,    83,    91,   116,    95,
      96,   104,   137,   145,   142,   105,   122,   117,   128,   -57,
     134,   141,   112,   138,    35,   146,     0,    90,    40,     0,
       0,     0,    51,     0,     0,     0,   126,   127,     0,     0,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143
};

static const yytype_int16 yycheck[] =
{
      13,    14,     3,    63,    24,     0,    60,    15,     9,    17,
      18,     7,     8,     9,    15,     3,    12,    15,    14,    36,
      18,     4,    42,    26,    27,    28,    27,    81,    48,    29,
      33,    34,    35,    34,    19,    20,    36,    37,    38,    52,
      36,     5,    43,    15,    16,    21,    18,    22,    23,   103,
      24,    25,    75,    76,     6,   109,     4,    39,     5,    32,
      31,    31,    29,    32,    30,    21,   126,   127,   122,    29,
      29,    29,    29,    10,    75,    76,    31,    31,    31,    30,
      30,    30,    13,   143,   138,    30,    29,    31,    30,    30,
      30,    11,    93,    32,    26,   144,    -1,    78,    36,    -1,
      -1,    -1,    48,    -1,    -1,    -1,   119,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,    44,     0,    36,    45,     4,    15,    17,
      18,    46,    48,    49,    51,    53,    45,     5,    47,    48,
      48,    45,    55,    21,     6,    60,    61,    32,    56,    52,
      39,    50,    16,    53,    54,    60,    45,    31,    31,    45,
      56,    62,    29,    53,    57,    58,    45,    30,    32,    59,
       4,    58,    63,    59,    48,    64,     7,     8,     9,    12,
      14,    45,    65,    66,    67,    68,    69,    70,    71,    72,
      86,    92,    94,    95,     5,    29,    29,    29,    29,    73,
      74,    21,    65,    31,    55,    55,    19,    20,    73,    90,
      90,    31,    75,    76,    73,    30,    30,    26,    27,    28,
      33,    34,    35,    91,    30,    30,    22,    23,    84,    29,
      37,    38,    45,    77,    78,    83,    31,    31,    73,    87,
      93,    73,    29,    24,    25,    85,    48,    48,    30,    73,
      79,    65,    65,    80,    30,    10,    88,    13,    32,    81,
      89,    11,    73,    48,    82,    65,    81
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    44,    43,    45,    47,    46,    48,    48,    48,
      49,    50,    52,    51,    53,    53,    54,    54,    55,    56,
      56,    57,    57,    58,    59,    59,    60,    60,    62,    63,
      61,    64,    65,    65,    66,    66,    66,    67,    67,    67,
      67,    68,    69,    70,    71,    72,    73,    74,    74,    75,
      76,    76,    77,    77,    78,    80,    79,    79,    82,    81,
      81,    83,    83,    83,    83,    84,    84,    85,    85,    87,
      86,    89,    88,    88,    90,    90,    90,    91,    91,    91,
      91,    91,    91,    93,    92,    94,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     1,     0,     3,     2,     2,     0,
       5,     1,     0,     4,     1,     1,     1,     1,     2,     3,
       0,     2,     0,     2,     3,     0,     2,     0,     0,     0,
      11,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     5,     5,     3,     2,     3,     0,     2,
       3,     0,     1,     1,     4,     0,     3,     0,     0,     4,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     0,
       9,     0,     4,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     8,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 2073 "src/parser.yy" /* yacc.c:1666  */
    {
				buffer << "\n\n;IR code" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				buffer << ";PUSH" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				buffer << ";PUSHREGS" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				buffer << ";JSR FUNC_main" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				buffer << ";HALT" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				global_var = 1;
			}
#line 3391 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 3:
#line 2091 "src/parser.yy" /* yacc.c:1666  */
    {
				print_toList();
				insert_threeAC();
				//print_buffer();
				//print_threeAC();
				addTinyList();
				//print_tinylist();
				//print_conditions();
				newTinyList();
				print_newtinylist();
			}
#line 3407 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 5:
#line 2104 "src/parser.yy" /* yacc.c:1666  */
    {
				global_var = 0;
			}
#line 3415 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 9:
#line 2108 "src/parser.yy" /* yacc.c:1666  */
    {
				if (link_count_enable == 1) {
					string link_num_string = to_string(link_num);
					buffer << ";LINK " << link_num_string << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
				}
				link_count_enable = 0;
				link_num = 0;
			}
#line 3430 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 10:
#line 2121 "src/parser.yy" /* yacc.c:1666  */
    {
			stringList[(yyvsp[-3].s)] = (yyvsp[-1].s);
			if (link_count_enable == 1) {
				link_num++;
			}
		}
#line 3441 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 12:
#line 2131 "src/parser.yy" /* yacc.c:1666  */
    {
			if (!strcmp((yyvsp[-1].s),"FLOAT")) 
			{
				while ((yyvsp[0].id_l) != NULL)
				{
					floatList.push_back((yyvsp[0].id_l) -> id);
					if (global_var == 1) {
						globalfloatList.push_back((yyvsp[0].id_l) -> id);
					}
					(yyvsp[0].id_l) = (yyvsp[0].id_l) -> id_tail;
					if (link_count_enable == 1) {
						link_num++;
					}
				}
			}
			else
			{
				while ((yyvsp[0].id_l) != NULL)
				{
					intList.push_back((yyvsp[0].id_l) -> id);
					if (global_var == 1) {
						globalintList.push_back((yyvsp[0].id_l) -> id);
					}
					(yyvsp[0].id_l) = (yyvsp[0].id_l) -> id_tail;
					if (link_count_enable == 1) {
						link_num++;
					}
				}
			}
		}
#line 3476 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 18:
#line 2164 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.id_l) = new ID_List(); (yyval.id_l)->addID((yyvsp[-1].s)); (yyval.id_l)->nextID((yyvsp[0].id_l));}
#line 3482 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 19:
#line 2165 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.id_l) = new ID_List(); (yyval.id_l)->addID((yyvsp[-1].s)); (yyval.id_l)->nextID((yyvsp[0].id_l));}
#line 3488 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 20:
#line 2165 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.id_l) = NULL;}
#line 3494 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 21:
#line 2168 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.p_list) = new Param_Decl_List(); (yyval.p_list)->addPD((yyvsp[-1].p_decl)); (yyval.p_list)->nextPD((yyvsp[0].p_list));}
#line 3500 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 22:
#line 2168 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.p_list) = NULL;}
#line 3506 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 23:
#line 2170 "src/parser.yy" /* yacc.c:1666  */
    {
						(yyval.p_decl) = new Param_Decl(); 
						(yyval.p_decl)->addType((yyvsp[-1].s)); 
						(yyval.p_decl)->addID((yyvsp[0].s));
						if (!strcmp((yyval.p_decl) -> type, "INT")) {
							param_intList.push_back((yyvsp[0].s));
						}
						else if (!strcmp((yyval.p_decl) -> type, "FLOAT")) {
							param_floatList.push_back((yyvsp[0].s));
						}
						return_reg_place++;
					}
#line 3523 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 24:
#line 2182 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.p_list) = new Param_Decl_List(); (yyval.p_list)->addPD((yyvsp[-1].p_decl)); (yyval.p_list)->nextPD((yyvsp[0].p_list));}
#line 3529 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 25:
#line 2182 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.p_list) = NULL;}
#line 3535 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 28:
#line 2187 "src/parser.yy" /* yacc.c:1666  */
    {
						clear_varlist();
						return_reg_place = 0;
						if (!strcmp((yyvsp[0].s), "main")) {
							inMain = true;
						}
						buffer << ";LABEL FUNC_" << (yyvsp[0].s) << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
					}
#line 3550 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 29:
#line 2197 "src/parser.yy" /* yacc.c:1666  */
    {
						link_count_enable = 1;					
					}
#line 3558 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 30:
#line 2200 "src/parser.yy" /* yacc.c:1666  */
    {
						print_toList();
						clear_toList();
						buffer << ";UNLINK" << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						buffer << ";RET" << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
					}
#line 3573 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 42:
#line 2220 "src/parser.yy" /* yacc.c:1666  */
    {
				if (!from_call_expr) {
					(yyval.mL) = new toList(); 
					(yyval.mL) -> addDestination((yyvsp[-2].s));
					(yyval.mL) -> addDestType(findType((yyvsp[-2].s)));
					(yyval.mL) -> addNode((yyvsp[0].AST));
					(yyval.mL) -> addOp((char*)"ASSIGN");
					myList.push_back((yyval.mL));
				}
				else {
					(yyval.mL) = new toList(); 
					(yyval.mL) -> addDestination((yyvsp[-2].s));
					(yyval.mL) -> addDestType(findType((yyvsp[-2].s)));
					(yyval.mL) -> addNode((yyvsp[0].AST));
					(yyval.mL) -> addOp((char*)"ASSIGN");
					myList.push_back((yyval.mL));
					print_toList();
					clear_toList();
					buffer << ";PUSH" << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					buffer << ";PUSHREGS" << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					list<char*>::iterator it;
					list<string>::iterator its;
					list<string> mainPush;
					for (it=comp_exprList.begin(); it!=comp_exprList.end();	 ++it) {
						char* match_expr = find_fromList((*it));
						if (inMain && !strcmp(match_expr, (*it))) {
							buffer << ";PUSH " << (*it) << endl;
							//threeAC.push_back(buffer.str());
							mainPush.push_front(buffer.str());
							buffer.str("");
						}
						else if (!strcmp(match_expr, (*it))) {
							buffer << ";PUSH !T" << to_string(reg_count) << endl;
							threeAC.push_back(buffer.str());
							buffer.str("");
						}
						else {
							buffer << ";PUSH " << match_expr << endl;
							threeAC.push_back(buffer.str());
							buffer.str("");
						}
					}
					if (!mainPush.empty()) {
						for (its=mainPush.begin(); its!=mainPush.end();	 ++its) {
							threeAC.push_back((*its));
						}
					}
					buffer << ";JSR FUNC_" << call_expr_id << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					for (it=comp_exprList.begin(); it!=comp_exprList.end(); ++it) {
						buffer << ";POP" << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
					}
					buffer << ";POPREGS" << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					buffer << ";POP !T" << to_string(++reg_count) << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					char* find_id = find_fromList((yyvsp[-2].s));
					buffer << ";STORE" << (yyval.mL) -> destination_type[0] << " !T" << to_string(reg_count++) << " " << find_id << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					from_call_expr = 0;
				}
			}
#line 3650 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 43:
#line 2293 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.mL) = new toList();
				(yyval.mL) -> addDestination((char*)"READ");
				(yyval.mL) -> addIDList((yyvsp[-2].id_l));
				(yyval.mL) -> addOp((char*)"READ");
				myList.push_back((yyval.mL));
			}
#line 3662 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 44:
#line 2301 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.mL) = new toList();
				(yyval.mL) -> addDestination((char*)"WRITE");
				(yyval.mL) -> addIDList((yyvsp[-2].id_l));
				(yyval.mL) -> addOp((char*)"WRITE");
				myList.push_back((yyval.mL));
			}
#line 3674 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 45:
#line 2309 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.mL) = new toList();
				(yyval.mL) -> addDestination((char*)"RETURN");
				(yyval.mL) -> addNode((yyvsp[-1].AST));
				(yyval.mL) -> addOp((char*)"RETURN");
				myList.push_back((yyval.mL));
				print_toList();
				clear_toList();
			}
#line 3688 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 46:
#line 2321 "src/parser.yy" /* yacc.c:1666  */
    {
				if ((yyvsp[-1].AST)->sign == NULL && (yyvsp[-1].AST)->id == NULL && (yyvsp[-1].AST)->type == NULL && (yyvsp[-1].AST)->left == NULL && (yyvsp[-1].AST)->right == NULL) 
				{
					(yyval.AST) = new ASTNode();
					(yyval.AST) = (yyvsp[0].AST);
					(yyval.AST) -> addPrimary(prim);
				}
				else
				{
					(yyval.AST) = new ASTNode();
					(yyval.AST) = (yyvsp[-1].AST);
					(yyval.AST) -> right = (yyvsp[0].AST);
					(yyval.AST) -> addPrimary(prim);
				}
				prim++;
			}
#line 3709 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 47:
#line 2338 "src/parser.yy" /* yacc.c:1666  */
    { 
				if ((yyvsp[-2].AST)->sign == NULL && (yyvsp[-2].AST)->id == NULL && (yyvsp[-2].AST)->type == NULL && (yyvsp[-2].AST)->left == NULL && (yyvsp[-2].AST)->right == NULL) 
				{ 
					(yyvsp[0].AST) -> left = (yyvsp[-1].AST);
					(yyval.AST) = (yyvsp[0].AST);
				} 
				else 
				{ 
					(yyvsp[-2].AST) -> right = (yyvsp[-1].AST);
					(yyvsp[0].AST) -> left = (yyvsp[-2].AST);
					(yyval.AST) = (yyvsp[0].AST);
				}
			}
#line 3727 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 48:
#line 2351 "src/parser.yy" /* yacc.c:1666  */
    { 
				(yyval.AST) = new ASTNode(); 
				(yyval.AST) -> addPrimary(prim);
			}
#line 3736 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 49:
#line 2356 "src/parser.yy" /* yacc.c:1666  */
    {
			if ((yyvsp[-1].AST)->sign == NULL && (yyvsp[-1].AST)->id == NULL && (yyvsp[-1].AST)->type == NULL && (yyvsp[-1].AST)->left == NULL && (yyvsp[-1].AST)->right == NULL) 
			{
				(yyval.AST) = new ASTNode();
				(yyval.AST) = (yyvsp[0].AST);
				(yyval.AST) -> addPrimary(prim);
			}
			else
			{
				(yyval.AST) -> left = (yyvsp[0].AST);
			}
						
		}
#line 3754 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 50:
#line 2370 "src/parser.yy" /* yacc.c:1666  */
    {
				if ((yyvsp[-2].AST)->sign == NULL && (yyvsp[-2].AST)->id == NULL && (yyvsp[-2].AST)->type == NULL && (yyvsp[-2].AST)->left == NULL && (yyvsp[-2].AST)->right == NULL) 
				{
					(yyvsp[0].AST) -> right = (yyvsp[-1].AST);
					(yyval.AST) = (yyvsp[0].AST);
				}
				else 
				{ 
					(yyvsp[-2].AST) -> left = (yyvsp[-1].AST);
					(yyvsp[0].AST) -> right = (yyvsp[-2].AST);
					(yyval.AST) = (yyvsp[0].AST);
				}
			}
#line 3772 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 51:
#line 2383 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) -> addPrimary(prim);
			}
#line 3781 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 52:
#line 2388 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) = (yyvsp[0].AST);
				(yyval.AST) -> addPrimary(prim);
			}
#line 3791 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 53:
#line 2393 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) = (yyvsp[0].AST);
				(yyval.AST) -> addPrimary(prim);
			}
#line 3801 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 54:
#line 2399 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) = (yyvsp[-1].AST);
				(yyval.AST) -> addPrimary(prim);
				call_expr_id = (yyvsp[-3].s);
				push_comp_exprList();
				exprList.clear();
				from_call_expr = 1;
			}
#line 3815 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 55:
#line 2409 "src/parser.yy" /* yacc.c:1666  */
    {
				if (!exprList.empty() || !comp_exprList.empty()) {
					exprList.clear();
					comp_exprList.clear();
				}
				exprList.push_back((yyvsp[0].AST));
			}
#line 3827 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 57:
#line 2415 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.AST) = NULL;}
#line 3833 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 58:
#line 2417 "src/parser.yy" /* yacc.c:1666  */
    {
				exprList.push_back((yyvsp[0].AST));
			}
#line 3841 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 61:
#line 2421 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) = (yyvsp[-1].AST);
			}
#line 3850 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 62:
#line 2426 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) -> addID((yyvsp[0].s));
				(yyval.AST) -> addType(findType((yyvsp[0].s)));
				(yyval.AST) -> addPrimary(prim);
			}
#line 3861 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 63:
#line 2433 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) -> addType((char*)"INTLITERAL");
				(yyval.AST) -> addID((yyvsp[0].s));
				(yyval.AST) -> addPrimary(prim);
			}
#line 3872 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 64:
#line 2440 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) -> addType((char*)"FLOATLITERAL");
				long double temp = atof((yyvsp[0].s));
				char* convert = new char[10];
				strcpy(convert, to_string(temp).c_str());
				(yyval.AST) -> addID(convert);
				(yyval.AST) -> addPrimary(prim);
			}
#line 3886 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 65:
#line 2450 "src/parser.yy" /* yacc.c:1666  */
    { 
				(yyval.AST) = new ASTNode(); 
				(yyval.AST) -> addSign((yyvsp[0].s));
				(yyval.AST) -> addPrimary(prim);
			}
#line 3896 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 66:
#line 2456 "src/parser.yy" /* yacc.c:1666  */
    { 
				(yyval.AST) = new ASTNode(); 
				(yyval.AST) -> addSign((yyvsp[0].s));
				(yyval.AST) -> addPrimary(prim);
			}
#line 3906 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 67:
#line 2462 "src/parser.yy" /* yacc.c:1666  */
    { 
				(yyval.AST) = new ASTNode(); 
				(yyval.AST) -> addSign((yyvsp[0].s));
				(yyval.AST) -> addPrimary(prim);
			}
#line 3916 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 68:
#line 2468 "src/parser.yy" /* yacc.c:1666  */
    { 
				(yyval.AST) = new ASTNode(); 
				(yyval.AST) -> addSign((yyvsp[0].s));
				(yyval.AST) -> addPrimary(prim);
			}
#line 3926 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 69:
#line 2476 "src/parser.yy" /* yacc.c:1666  */
    {
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addNode((yyvsp[-1].AST));
						temp -> addOp((char*)"IF_COND_START");
						if (!strcmp((yyvsp[-1].AST) -> type, "INTLITERAL")) {
							temp -> addDestType((char*)"INT");
						}
						else if (!strcmp((yyvsp[-1].AST) -> type, "FLOATLITERAL")) {
							temp -> addDestType((char*)"FLOAT");
						}
						else {
							temp -> addDestType((yyvsp[-1].AST) -> type);
						}
						myList.push_back(temp);
						print_toList();
						clear_toList();
					}
#line 3950 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 70:
#line 2496 "src/parser.yy" /* yacc.c:1666  */
    {
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"IF_COND_END");
						myList.push_back(temp);
						print_toList();
						clear_toList();
					}
#line 3964 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 71:
#line 2506 "src/parser.yy" /* yacc.c:1666  */
    {
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"ELSE_COND");
						myList.push_back(temp);
					}
#line 3976 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 73:
#line 2514 "src/parser.yy" /* yacc.c:1666  */
    {
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"ELSE_COND");
						myList.push_back(temp);
					}
#line 3988 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 74:
#line 2522 "src/parser.yy" /* yacc.c:1666  */
    {
						(yyval.AST) = new ASTNode();
						(yyval.AST) -> left = (yyvsp[-2].AST);
						(yyval.AST) -> right = (yyvsp[0].AST);
						(yyval.AST) -> sign = (yyvsp[-1].s);
						if ((yyvsp[0].AST) -> sign == NULL) {
							(yyval.AST) -> type = (yyvsp[0].AST) -> type;
						}
						else {
							(yyval.AST) -> type = (yyvsp[-2].AST) -> type;
						}
					}
#line 4005 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 75:
#line 2535 "src/parser.yy" /* yacc.c:1666  */
    {
						(yyval.AST) = new ASTNode();
						ASTNode* left = new ASTNode();
						ASTNode* right = new ASTNode();
						ASTNode* sign = new ASTNode();
						left -> id = (char*)"1";
						left -> type = (char*)"INTLITERAL";
						right -> id = (char*)"0";
						right -> type = (char*)"INTLITERAL";
						sign -> sign = (char*)"!=";
						sign -> type = (char*)"INTLITERAL";
						(yyval.AST) = sign;
						(yyval.AST) -> left = left;
						(yyval.AST) -> right = right;
					}
#line 4025 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 76:
#line 2550 "src/parser.yy" /* yacc.c:1666  */
    {
						(yyval.AST) = new ASTNode();
						ASTNode* left = new ASTNode();
						ASTNode* right = new ASTNode();
						ASTNode* sign = new ASTNode();
						left -> id = (char*)"1";
						left -> type = (char*)"INTLITERAL";
						right -> id = (char*)"0";
						right -> type = (char*)"INTLITERAL";
						sign -> sign = (char*)"!=";
						sign -> type = (char*)"INTLITERAL";
						(yyval.AST) = sign;
						(yyval.AST) -> left = left;
						(yyval.AST) -> right = right;
					}
#line 4045 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 83:
#line 2567 "src/parser.yy" /* yacc.c:1666  */
    {
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addNode((yyvsp[-1].AST));
						temp -> addOp((char*)"WHILE_COND_START");
						if (!strcmp((yyvsp[-1].AST) -> type, "INTLITERAL")) {
							temp -> addDestType((char*)"INT");
						}
						else if (!strcmp((yyvsp[-1].AST) -> type, "FLOATLITERAL")) {
							temp -> addDestType((char*)"FLOAT");
						}
						else {
							temp -> addDestType((yyvsp[-1].AST) -> type);
						}
						myList.push_back(temp);
						print_toList();
						clear_toList();
					}
#line 4069 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 84:
#line 2586 "src/parser.yy" /* yacc.c:1666  */
    {
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"WHILE_COND_END");
						myList.push_back(temp);
						print_toList();
						clear_toList();
					}
#line 4083 "generated/parser.cpp" /* yacc.c:1666  */
    break;


#line 4087 "generated/parser.cpp" /* yacc.c:1666  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
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
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 2600 "src/parser.yy" /* yacc.c:1910  */

