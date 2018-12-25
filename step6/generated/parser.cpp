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
	long long scope_count = 1;
	list <string> conditions;

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

	char temp1[10];
	char temp2[10];
	char temp3[10];

	//Step7 variable
	list <string> gen;
	list <string> kill;
	list <list <int> > predecessor;
	list <list <int> > successor;

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
			}

			else if (!strcmp((*it) -> op, "WHILE_COND_END")) {
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
				if ((*it) -> node -> id != NULL) {
					char variable[10];
					strcpy(variable,find_fromList((*it) -> node -> id));
					buffer << ";STORE" << (*it) -> node -> type[0] << " " << variable << " !T" << to_string(reg_count) << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					buffer << ";STORE" << (*it) -> node -> type[0] << " !T" << to_string(reg_count) << " $" << to_string(6 + return_reg_place) << endl;
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
					buffer << ";STORE" << type_return[0] << " !T" << to_string(reg_count - 1) << " $" << to_string(6 + return_reg_place) << endl;
					reg_count++;
					threeAC.push_back(buffer.str());
					buffer.str("");
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
		/*
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
		*/
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
				string s = string("push ");
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
				string s = string("pop ");
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
				string s = string("jsr ");
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
				string s = string("label ");
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
				string s = string("jmp ");
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
				string s = string("link ");
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
				string s = string("cmpi ");
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
				s = string("jeq ");
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
				string s = string("cmpi ");
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
				s = string("jne ");
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
				string s = string("cmpi ");
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
				s = string("jle ");
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
				string s = string("cmpi ");
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
				s = string("jge ");
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
				string s = string("cmpi ");
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
				s = string("jgt ");
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
				string s = string("cmpi ");
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
				s = string("jlt ");
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
				string s = string("cmpr ");
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
				s = string("jeq ");
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
				string s = string("cmpr ");
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
				s = string("jne ");
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
				string s = string("cmpr ");
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
				s = string("jle ");
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
				string s = string("cmpr ");
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
				s = string("jge ");
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
				string s = string("cmpr ");
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
				s = string("jgt ");
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
				string s = string("cmpr ");
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
				s = string("jlt ");
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

	//Step 7
	void generateGPKS() {
		list<new_threeAC *>::iterator it;
		for (it=new_threeAC.begin(); it!=exprList.end(); ++it) {
	}
	

#line 1763 "generated/parser.cpp" /* yacc.c:339  */

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
#line 1698 "src/parser.yy" /* yacc.c:355  */

	struct ID_List* id_l;
	char* s;
	struct Param_Decl* p_decl;
	struct Param_Decl_List* p_list;
	struct ASTNode* AST;
	struct toList* mL;

#line 1854 "generated/parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GENERATED_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 1871 "generated/parser.cpp" /* yacc.c:358  */

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
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

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
       0,  1758,  1758,  1757,  1784,  1785,  1786,  1786,  1787,  1799,
    1806,  1810,  1809,  1835,  1835,  1836,  1836,  1837,  1838,  1838,
    1841,  1841,  1842,  1855,  1855,  1858,  1858,  1860,  1867,  1859,
    1878,  1881,  1881,  1882,  1882,  1882,  1883,  1883,  1883,  1883,
    1886,  1887,  1947,  1955,  1963,  1975,  1992,  2006,  2010,  2024,
    2038,  2042,  2047,  2053,  2064,  2063,  2070,  2072,  2071,  2074,
    2075,  2080,  2087,  2094,  2104,  2110,  2116,  2122,  2131,  2130,
    2153,  2152,  2161,  2168,  2176,  2180,  2185,  2185,  2185,  2185,
    2185,  2185,  2187,  2186,  2210,  2211
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
  "$accept", "program", "$@1", "id", "pgm_body", "decl", "string_decl",
  "str", "var_decl", "$@2", "var_type", "any_type", "id_list", "id_tail",
  "param_decl_list", "param_decl", "param_decl_tail", "func_declarations",
  "func_decl", "$@3", "$@4", "func_body", "stmt_list", "stmt", "base_stmt",
  "assign_stmt", "assign_expr", "read_stmt", "write_stmt", "return_stmt",
  "expr", "expr_prefix", "factor", "factor_prefix", "postfix_expr",
  "call_expr", "expr_list", "$@5", "expr_list_tail", "$@6", "primary",
  "addop", "mulop", "if_stmt", "$@7", "else_part", "$@8", "cond", "compop",
  "while_stmt", "$@9", "control_stmt", "loop_stmt", YY_NULLPTR
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

#define YYPACT_NINF -60

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-60)))

#define YYTABLE_NINF -57

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,   -60,    18,     3,   -60,   -60,    41,    17,   -60,     3,
     -60,    44,    47,    17,    17,     3,    33,   -60,    28,   -60,
      47,   -60,   -60,    25,   -60,    16,   -60,   -60,     3,   -60,
       3,   -60,    27,   -60,    29,   -60,    25,   -60,   -60,    30,
     -60,    22,     3,    31,    32,   -60,    58,    22,   -60,   -60,
      32,    17,   -60,    -3,    60,    34,    39,    42,    43,   -60,
      49,   -60,    -3,   -60,   -60,    45,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,     3,     3,     6,     6,    46,   -60,
     -60,   -60,   -60,    48,    50,   -60,   -60,   -11,    51,    52,
     -60,     8,   -17,   -60,    53,    55,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,    59,    23,   -60,   -60,   -60,   -60,   -60,    17,    17,
      57,    62,   -60,   -60,   -60,    -3,    -3,   -60,   -60,    63,
      65,    66,    64,   -60,   -60,    78,   -60,   -60,   -60,    17,
     -60,   -60,    -3,    64,   -60,   -60
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     4,     0,     8,    14,     0,
      13,     0,    26,     8,     8,     0,     0,     3,     0,     5,
      26,     6,     7,    19,    11,     0,    16,    15,     0,    25,
       0,    17,     0,    10,     0,    27,    19,    12,     9,     0,
      18,    21,     0,     0,    24,    22,     0,     0,    20,    28,
      24,     8,    23,    32,     0,     0,     0,     0,     0,    47,
       0,    30,    32,    33,    36,     0,    37,    38,    84,    34,
      85,    39,    35,    29,     0,     0,    47,    47,     0,    50,
      47,    31,    40,     0,     0,    74,    75,     0,     0,     0,
      44,    45,     0,    41,     0,     0,    79,    77,    76,    81,
      80,    78,    47,    68,    82,    64,    65,    46,    47,    63,
      62,    61,    48,    52,    51,    42,    43,    73,     8,     8,
       0,    47,    66,    67,    49,    32,    32,    60,    54,     0,
      72,     0,    59,    53,    70,     0,    83,    47,    55,     8,
      69,    57,    32,    59,    71,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -60,    -1,   -60,   -13,   -60,   -60,   -60,   -60,
      -5,   -60,   -23,    54,   -60,    56,    61,    74,   -60,   -60,
     -60,   -60,   -59,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -52,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -48,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,    20,   -60,   -60,
     -60,   -60,   -60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    60,    11,    12,    13,    34,    14,    32,
      15,    28,    24,    31,    43,    44,    48,    19,    20,    39,
      51,    54,    61,    62,    63,    64,    65,    66,    67,    68,
      87,    79,    91,    92,   112,   113,   129,   132,   138,   143,
     114,   107,   124,    69,   118,   135,   139,    88,   102,    70,
     119,    71,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    22,     6,    81,    55,    56,    57,    78,    16,    58,
       1,    59,   108,    27,    23,    96,    97,    98,     4,     5,
     109,   110,    99,   100,   101,    85,    86,    35,    93,    36,
     105,   106,     8,     5,     9,    10,    42,     8,    53,     5,
      10,    45,    42,     8,    26,     7,    10,   122,   123,    17,
     117,    83,    84,    18,    25,    33,   120,    30,    37,    41,
      38,    46,    49,    74,    47,    73,   130,   131,    75,   128,
      80,    76,    77,    23,    23,   134,    82,    90,    94,   136,
      95,   103,   104,   144,   115,   141,   116,   127,   121,   140,
      40,   111,   -56,   133,    29,   145,   137,    89,     0,     0,
       0,     0,     0,    50,     0,   125,   126,     0,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142
};

static const yytype_int16 yycheck[] =
{
      13,    14,     3,    62,     7,     8,     9,    59,     9,    12,
       3,    14,    29,    18,    15,    26,    27,    28,     0,    36,
      37,    38,    33,    34,    35,    19,    20,    28,    80,    30,
      22,    23,    15,    36,    17,    18,    41,    15,    51,    36,
      18,    42,    47,    15,    16,     4,    18,    24,    25,     5,
     102,    74,    75,     6,    21,    39,   108,    32,    31,    29,
      31,    30,     4,    29,    32,     5,   125,   126,    29,   121,
      21,    29,    29,    74,    75,    10,    31,    31,    30,    13,
      30,    30,    30,   142,    31,   137,    31,    30,    29,    11,
      36,    92,    30,    30,    20,   143,    32,    77,    -1,    -1,
      -1,    -1,    -1,    47,    -1,   118,   119,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,    44,     0,    36,    45,     4,    15,    17,
      18,    46,    47,    48,    50,    52,    45,     5,     6,    59,
      60,    47,    47,    45,    54,    21,    16,    52,    53,    59,
      32,    55,    51,    39,    49,    45,    45,    31,    31,    61,
      55,    29,    52,    56,    57,    45,    30,    32,    58,     4,
      57,    62,    58,    47,    63,     7,     8,     9,    12,    14,
      45,    64,    65,    66,    67,    68,    69,    70,    71,    85,
      91,    93,    94,     5,    29,    29,    29,    29,    72,    73,
      21,    64,    31,    54,    54,    19,    20,    72,    89,    89,
      31,    74,    75,    72,    30,    30,    26,    27,    28,    33,
      34,    35,    90,    30,    30,    22,    23,    83,    29,    37,
      38,    45,    76,    77,    82,    31,    31,    72,    86,    92,
      72,    29,    24,    25,    84,    47,    47,    30,    72,    78,
      64,    64,    79,    30,    10,    87,    13,    32,    80,    88,
      11,    72,    47,    81,    64,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    44,    43,    45,    46,    47,    47,    47,    48,
      49,    51,    50,    52,    52,    53,    53,    54,    55,    55,
      56,    56,    57,    58,    58,    59,    59,    61,    62,    60,
      63,    64,    64,    65,    65,    65,    66,    66,    66,    66,
      67,    68,    69,    70,    71,    72,    73,    73,    74,    75,
      75,    76,    76,    77,    79,    78,    78,    81,    80,    80,
      82,    82,    82,    82,    83,    83,    84,    84,    86,    85,
      88,    87,    87,    89,    89,    89,    90,    90,    90,    90,
      90,    90,    92,    91,    93,    94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     1,     2,     2,     2,     0,     5,
       1,     0,     4,     1,     1,     1,     1,     2,     3,     0,
       2,     0,     2,     3,     0,     2,     0,     0,     0,    11,
       2,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     5,     5,     3,     2,     3,     0,     2,     3,
       0,     1,     1,     4,     0,     3,     0,     0,     4,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     0,     9,
       0,     4,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     8,     1,     1
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
#line 1758 "src/parser.yy" /* yacc.c:1666  */
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
			}
#line 3074 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 3:
#line 1775 "src/parser.yy" /* yacc.c:1666  */
    {
				print_toList();
				insert_threeAC();
				//print_buffer();
				print_threeAC();
				addTinyList();
				print_tinylist();
				//print_conditions();
			}
#line 3088 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 8:
#line 1787 "src/parser.yy" /* yacc.c:1666  */
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
#line 3103 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 9:
#line 1800 "src/parser.yy" /* yacc.c:1666  */
    {
			stringList[(yyvsp[-3].s)] = (yyvsp[-1].s);
			if (link_count_enable == 1) {
				link_num++;
			}
		}
#line 3114 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 11:
#line 1810 "src/parser.yy" /* yacc.c:1666  */
    {
			if (!strcmp((yyvsp[-1].s),"FLOAT")) 
			{
				while ((yyvsp[0].id_l) != NULL)
				{
					floatList.push_back((yyvsp[0].id_l) -> id);
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
					(yyvsp[0].id_l) = (yyvsp[0].id_l) -> id_tail;
					if (link_count_enable == 1) {
						link_num++;
					}
				}
			}
		}
#line 3143 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 17:
#line 1837 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.id_l) = new ID_List(); (yyval.id_l)->addID((yyvsp[-1].s)); (yyval.id_l)->nextID((yyvsp[0].id_l));}
#line 3149 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 18:
#line 1838 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.id_l) = new ID_List(); (yyval.id_l)->addID((yyvsp[-1].s)); (yyval.id_l)->nextID((yyvsp[0].id_l));}
#line 3155 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 19:
#line 1838 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.id_l) = NULL;}
#line 3161 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 20:
#line 1841 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.p_list) = new Param_Decl_List(); (yyval.p_list)->addPD((yyvsp[-1].p_decl)); (yyval.p_list)->nextPD((yyvsp[0].p_list));}
#line 3167 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 21:
#line 1841 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.p_list) = NULL;}
#line 3173 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 22:
#line 1843 "src/parser.yy" /* yacc.c:1666  */
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
#line 3190 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 23:
#line 1855 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.p_list) = new Param_Decl_List(); (yyval.p_list)->addPD((yyvsp[-1].p_decl)); (yyval.p_list)->nextPD((yyvsp[0].p_list));}
#line 3196 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 24:
#line 1855 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.p_list) = NULL;}
#line 3202 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 27:
#line 1860 "src/parser.yy" /* yacc.c:1666  */
    {
						clear_varlist();
						return_reg_place = 0;
						buffer << ";LABEL FUNC_" << (yyvsp[0].s) << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
					}
#line 3214 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 28:
#line 1867 "src/parser.yy" /* yacc.c:1666  */
    {
						link_count_enable = 1;					
					}
#line 3222 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 29:
#line 1870 "src/parser.yy" /* yacc.c:1666  */
    {
						buffer << ";UNLINK" << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						buffer << ";RET" << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
					}
#line 3235 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 41:
#line 1888 "src/parser.yy" /* yacc.c:1666  */
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
					for (it=comp_exprList.begin(); it!=comp_exprList.end();	 ++it) {
						char* match_expr = find_fromList((*it));
						if (!strcmp(match_expr, (*it))) {
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
#line 3299 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 42:
#line 1948 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.mL) = new toList();
				(yyval.mL) -> addDestination((char*)"READ");
				(yyval.mL) -> addIDList((yyvsp[-2].id_l));
				(yyval.mL) -> addOp((char*)"READ");
				myList.push_back((yyval.mL));
			}
#line 3311 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 43:
#line 1956 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.mL) = new toList();
				(yyval.mL) -> addDestination((char*)"WRITE");
				(yyval.mL) -> addIDList((yyvsp[-2].id_l));
				(yyval.mL) -> addOp((char*)"WRITE");
				myList.push_back((yyval.mL));
			}
#line 3323 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 44:
#line 1964 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.mL) = new toList();
				(yyval.mL) -> addDestination((char*)"RETURN");
				(yyval.mL) -> addNode((yyvsp[-1].AST));
				(yyval.mL) -> addOp((char*)"RETURN");
				myList.push_back((yyval.mL));
				print_toList();
				clear_toList();
			}
#line 3337 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 45:
#line 1976 "src/parser.yy" /* yacc.c:1666  */
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
#line 3358 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 46:
#line 1993 "src/parser.yy" /* yacc.c:1666  */
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
#line 3376 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 47:
#line 2006 "src/parser.yy" /* yacc.c:1666  */
    { 
				(yyval.AST) = new ASTNode(); 
				(yyval.AST) -> addPrimary(prim);
			}
#line 3385 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 48:
#line 2011 "src/parser.yy" /* yacc.c:1666  */
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
#line 3403 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 49:
#line 2025 "src/parser.yy" /* yacc.c:1666  */
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
#line 3421 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 50:
#line 2038 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) -> addPrimary(prim);
			}
#line 3430 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 51:
#line 2043 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) = (yyvsp[0].AST);
				(yyval.AST) -> addPrimary(prim);
			}
#line 3440 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 52:
#line 2048 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) = (yyvsp[0].AST);
				(yyval.AST) -> addPrimary(prim);
			}
#line 3450 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 53:
#line 2054 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) = (yyvsp[-1].AST);
				(yyval.AST) -> addPrimary(prim);
				call_expr_id = (yyvsp[-3].s);
				push_comp_exprList();
				exprList.clear();
				from_call_expr = 1;
			}
#line 3464 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 54:
#line 2064 "src/parser.yy" /* yacc.c:1666  */
    {
				if (!exprList.empty() || !comp_exprList.empty()) {
					exprList.clear();
					comp_exprList.clear();
				}
				exprList.push_back((yyvsp[0].AST));
			}
#line 3476 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 56:
#line 2070 "src/parser.yy" /* yacc.c:1666  */
    {(yyval.AST) = NULL;}
#line 3482 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 57:
#line 2072 "src/parser.yy" /* yacc.c:1666  */
    {
				exprList.push_back((yyvsp[0].AST));
			}
#line 3490 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 60:
#line 2076 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) = (yyvsp[-1].AST);
			}
#line 3499 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 61:
#line 2081 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) -> addID((yyvsp[0].s));
				(yyval.AST) -> addType(findType((yyvsp[0].s)));
				(yyval.AST) -> addPrimary(prim);
			}
#line 3510 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 62:
#line 2088 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) -> addType((char*)"INTLITERAL");
				(yyval.AST) -> addID((yyvsp[0].s));
				(yyval.AST) -> addPrimary(prim);
			}
#line 3521 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 63:
#line 2095 "src/parser.yy" /* yacc.c:1666  */
    {
				(yyval.AST) = new ASTNode();
				(yyval.AST) -> addType((char*)"FLOATLITERAL");
				long double temp = atof((yyvsp[0].s));
				char* convert = new char[10];
				strcpy(convert, to_string(temp).c_str());
				(yyval.AST) -> addID(convert);
				(yyval.AST) -> addPrimary(prim);
			}
#line 3535 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 64:
#line 2105 "src/parser.yy" /* yacc.c:1666  */
    { 
				(yyval.AST) = new ASTNode(); 
				(yyval.AST) -> addSign((yyvsp[0].s));
				(yyval.AST) -> addPrimary(prim);
			}
#line 3545 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 65:
#line 2111 "src/parser.yy" /* yacc.c:1666  */
    { 
				(yyval.AST) = new ASTNode(); 
				(yyval.AST) -> addSign((yyvsp[0].s));
				(yyval.AST) -> addPrimary(prim);
			}
#line 3555 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 66:
#line 2117 "src/parser.yy" /* yacc.c:1666  */
    { 
				(yyval.AST) = new ASTNode(); 
				(yyval.AST) -> addSign((yyvsp[0].s));
				(yyval.AST) -> addPrimary(prim);
			}
#line 3565 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 67:
#line 2123 "src/parser.yy" /* yacc.c:1666  */
    { 
				(yyval.AST) = new ASTNode(); 
				(yyval.AST) -> addSign((yyvsp[0].s));
				(yyval.AST) -> addPrimary(prim);
			}
#line 3575 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 68:
#line 2131 "src/parser.yy" /* yacc.c:1666  */
    {
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addNode((yyvsp[-1].AST));
						temp -> addOp((char*)"IF_COND_START");
						temp -> addDestType((yyvsp[-1].AST) -> type);
						myList.push_back(temp);
						print_toList();
						clear_toList();
					}
#line 3591 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 69:
#line 2143 "src/parser.yy" /* yacc.c:1666  */
    {
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"IF_COND_END");
						myList.push_back(temp);
						print_toList();
						clear_toList();
					}
#line 3605 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 70:
#line 2153 "src/parser.yy" /* yacc.c:1666  */
    {
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"ELSE_COND");
						myList.push_back(temp);
					}
#line 3617 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 72:
#line 2161 "src/parser.yy" /* yacc.c:1666  */
    {
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"ELSE_COND");
						myList.push_back(temp);
					}
#line 3629 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 73:
#line 2169 "src/parser.yy" /* yacc.c:1666  */
    {
						(yyval.AST) = new ASTNode();
						(yyval.AST) -> left = (yyvsp[-2].AST);
						(yyval.AST) -> right = (yyvsp[0].AST);
						(yyval.AST) -> sign = (yyvsp[-1].s);
						(yyval.AST) -> type = findType((yyvsp[-2].AST) -> id);
					}
#line 3641 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 74:
#line 2177 "src/parser.yy" /* yacc.c:1666  */
    {
						(yyval.AST) = new ASTNode();
						(yyval.AST) -> id = (yyvsp[0].s);
					}
#line 3650 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 75:
#line 2181 "src/parser.yy" /* yacc.c:1666  */
    {
						(yyval.AST) = new ASTNode();
						(yyval.AST) -> id = (yyvsp[0].s);
					}
#line 3659 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 82:
#line 2187 "src/parser.yy" /* yacc.c:1666  */
    {
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addNode((yyvsp[-1].AST));
						temp -> addOp((char*)"WHILE_COND_START");
						temp -> addDestType((yyvsp[-1].AST) -> type);
						myList.push_back(temp);
						print_toList();
						clear_toList();
					}
#line 3675 "generated/parser.cpp" /* yacc.c:1666  */
    break;

  case 83:
#line 2198 "src/parser.yy" /* yacc.c:1666  */
    {
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"WHILE_COND_END");
						myList.push_back(temp);
						print_toList();
						clear_toList();
					}
#line 3689 "generated/parser.cpp" /* yacc.c:1666  */
    break;


#line 3693 "generated/parser.cpp" /* yacc.c:1666  */
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
#line 2212 "src/parser.yy" /* yacc.c:1910  */

