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
	
%}

%union{
	struct ID_List* id_l;
	char* s;
	struct Param_Decl* p_decl;
	struct Param_Decl_List* p_list;
	struct ASTNode* AST;
	struct toList* mL;
}

%type <s> id str var_type any_type compop;
%type <id_l> id_list id_tail;
%type <p_decl> param_decl;
%type <p_list> param_decl_list param_decl_tail;
%type <AST> expr expr_prefix factor addop mulop factor_prefix postfix_expr primary call_expr expr_list cond;
%type <mL> assign_expr read_stmt write_stmt return_stmt ;

%token	_PRG
%token	_BGN
%token	_END
%token	_FNC
%token	_RD
%token	_WR
%token	<s> _IF
%token	_ELSE
%token	_ENDIF
%token	_WHILE
%token	_ENDWH
%token	_RTN
%token	<s> _INT
%token	<s> _VOID
%token	<s> _STRING
%token	<s> _FLOAT
%token	<s> _TRUE
%token	<s> _FALSE
%token	_ASSIGN
%token <s>	_PLUS
%token <s>	_MINUS
%token <s>	_MUL
%token <s>	_DIV
%token	<s> _NQ
%token	<s> _GT
%token	<s> _LT
%token	_OPENP
%token  _CLOSEP
%token	_SEMICOLON
%token	_COMMA
%token	<s> _GTE
%token	<s> _LTE
%token	<s> _EQ
%token	<s> IDENTIFIER
%token	<s> FLOATLITERAL
%token	<s> INTLITERAL
%token	<s> STRINGLITERAL
%token	COMMENT
%token	WHITESPACE

%start program

%%
program:	_PRG
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
			} id _BGN pgm_body _END 
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
			};
id:		IDENTIFIER ;
pgm_body:	decl
			{
				global_var = 0;
			} func_declarations ;
decl:		string_decl decl | var_decl decl | 
			{
				if (link_count_enable == 1) {
					string link_num_string = to_string(link_num);
					buffer << ";LINK " << link_num_string << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
				}
				link_count_enable = 0;
				link_num = 0;
			} ;

/* Global String Declaration */
string_decl:	_STRING id _ASSIGN str _SEMICOLON 
		{
			stringList[$2] = $4;
			if (link_count_enable == 1) {
				link_num++;
			}
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
					if (global_var == 1) {
						globalfloatList.push_back($2 -> id);
					}
					$2 = $2 -> id_tail;
					if (link_count_enable == 1) {
						link_num++;
					}
				}
			}
			else
			{
				while ($2 != NULL)
				{
					intList.push_back($2 -> id);
					if (global_var == 1) {
						globalintList.push_back($2 -> id);
					}
					$2 = $2 -> id_tail;
					if (link_count_enable == 1) {
						link_num++;
					}
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
param_decl:			var_type id 
					{
						$$ = new Param_Decl(); 
						$$->addType($1); 
						$$->addID($2);
						if (!strcmp($$ -> type, "INT")) {
							param_intList.push_back($2);
						}
						else if (!strcmp($$ -> type, "FLOAT")) {
							param_floatList.push_back($2);
						}
						return_reg_place++;
					};
param_decl_tail:	_COMMA param_decl param_decl_tail {$$ = new Param_Decl_List(); $$->addPD($2); $$->nextPD($3);} | {$$ = NULL;};

/* Function Declarations */
func_declarations:	func_decl func_declarations | /* empty */ ;
func_decl:			_FNC any_type id
					{
						clear_varlist();
						return_reg_place = 0;
						if (!strcmp($3, "main")) {
							inMain = true;
						}
						buffer << ";LABEL FUNC_" << $3 << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
					} _OPENP param_decl_list _CLOSEP _BGN 
					{
						link_count_enable = 1;					
					} func_body _END 
					{
						print_toList();
						clear_toList();
						buffer << ";UNLINK" << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						buffer << ";RET" << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
					};
func_body:			decl stmt_list ;

/* Statement List */
stmt_list:			stmt stmt_list | ;
stmt:				base_stmt | if_stmt | loop_stmt ;
base_stmt:			assign_stmt | read_stmt | write_stmt | control_stmt ;

/* Basic Statements */
assign_stmt:		assign_expr _SEMICOLON ;
assign_expr:		id _ASSIGN expr 
			{
				if (!from_call_expr) {
					$$ = new toList(); 
					$$ -> addDestination($1);
					$$ -> addDestType(findType($1));
					$$ -> addNode($3);
					$$ -> addOp((char*)"ASSIGN");
					myList.push_back($$);
				}
				else {
					$$ = new toList(); 
					$$ -> addDestination($1);
					$$ -> addDestType(findType($1));
					$$ -> addNode($3);
					$$ -> addOp((char*)"ASSIGN");
					myList.push_back($$);
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
					char* find_id = find_fromList($1);
					buffer << ";STORE" << $$ -> destination_type[0] << " !T" << to_string(reg_count++) << " " << find_id << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					from_call_expr = 0;
				}
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
				print_toList();
				clear_toList();
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
				call_expr_id = $1;
				push_comp_exprList();
				exprList.clear();
				from_call_expr = 1;
			};
expr_list:		expr
			{
				if (!exprList.empty() || !comp_exprList.empty()) {
					exprList.clear();
					comp_exprList.clear();
				}
				exprList.push_back($1);
			} expr_list_tail | {$$ = NULL;};
expr_list_tail:	_COMMA expr
			{
				exprList.push_back($2);
			} expr_list_tail | ;
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
if_stmt:			_IF _OPENP cond _CLOSEP
					{
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addNode($3);
						temp -> addOp((char*)"IF_COND_START");
						if (!strcmp($3 -> type, "INTLITERAL")) {
							temp -> addDestType((char*)"INT");
						}
						else if (!strcmp($3 -> type, "FLOATLITERAL")) {
							temp -> addDestType((char*)"FLOAT");
						}
						else {
							temp -> addDestType($3 -> type);
						}
						myList.push_back(temp);
						print_toList();
						clear_toList();
					} 
					decl stmt_list else_part _ENDIF
					{
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"IF_COND_END");
						myList.push_back(temp);
						print_toList();
						clear_toList();
					};
else_part:			_ELSE
					{
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"ELSE_COND");
						myList.push_back(temp);
					} decl stmt_list
					 | 
					{
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"ELSE_COND");
						myList.push_back(temp);
					} ;
cond:				expr compop expr 
					{
						$$ = new ASTNode();
						$$ -> left = $1;
						$$ -> right = $3;
						$$ -> sign = $2;
						if ($3 -> sign == NULL) {
							$$ -> type = $3 -> type;
						}
						else {
							$$ -> type = $1 -> type;
						}
					}
					| _TRUE
					{
						$$ = new ASTNode();
						$$ -> id = $1;
					} | _FALSE 
					{
						$$ = new ASTNode();
						$$ -> id = $1;
					};
compop:				_LT | _GT | _EQ | _NQ | _LTE | _GTE ;
while_stmt:			_WHILE _OPENP cond _CLOSEP
					{
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addNode($3);
						temp -> addOp((char*)"WHILE_COND_START");
						if (!strcmp($3 -> type, "INTLITERAL")) {
							temp -> addDestType((char*)"INT");
						}
						else if (!strcmp($3 -> type, "FLOATLITERAL")) {
							temp -> addDestType((char*)"FLOAT");
						}
						else {
							temp -> addDestType($3 -> type);
						}
						myList.push_back(temp);
						print_toList();
						clear_toList();
					} decl stmt_list _ENDWH 
					{
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"WHILE_COND_END");
						myList.push_back(temp);
						print_toList();
						clear_toList();
					};


/*ECE468 ONLY*/
control_stmt:		return_stmt ;
loop_stmt:			while_stmt ;
%%
