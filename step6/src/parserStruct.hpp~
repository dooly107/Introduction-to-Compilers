#include <cstdio>
#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

char* error();

struct StrEntry {
	char* id;
	char* str;
	void addID(char* id_get) {
		id = id_get;
	}
	void addValue(char* str_get) {
		str = str_get;
	}
};

struct ID_List {
	char* id;
	ID_List* id_tail;
	void addID(char* id_get) {
		id = id_get;
	}
	void nextID(ID_List* next_ID) {
		id_tail = next_ID;
	}
};

struct VarEntry {
	char* var_type;
	ID_List* id_list;
	void addVartype(char* var_get) {
		var_type = var_get;
	}
	void addIDlist(ID_List* ID) {
		id_list = ID;
	}
};


struct Param_Decl {
	char* type;
	char* id;
	void addType(char* var_type) {
		type = var_type;
	}
	void addID(char* get_id) {
		id = get_id;
	}
};

struct Param_Decl_List {
	Param_Decl* pd;
	Param_Decl_List* nextpd;
	void addPD(Param_Decl* param_decl) {
		pd = param_decl;
	}
	void nextPD(Param_Decl_List* next) {
		nextpd = next;
	}
};

struct ASTNode {
	char* sign;
	char* id;
	char* value;
	char* type;
	ASTNode* left;
	ASTNode* right;
	int primary;

	void addLeft(ASTNode* prefix, ASTNode* factor) {
		if (prefix != NULL) {
			left = prefix;
		}
		else {
			left = factor;
		}
	}
	void addRight(ASTNode* factor) {
		right = factor;
	}
	void addSign(char* sign_get) {
		sign = sign_get;
	}
	void addID(char* ID) {
		id = ID;
	}
	void addType(char* TYPE) {
		type = TYPE;
	}
	void addValue(char* VAL) {
		value = VAL;
	}
	void addPrimary(int prim) {
		primary = prim;
	}
};


struct Expr_List {
	Expr_List* nxtExpr;
	ASTNode* expr;
	void nextExpr(Expr_List* nxt) {
		nxtExpr = nxt;
	}
	void addAST(ASTNode* ast) {
		expr = ast;
	}
};

struct toList {
	char* destination;
	ASTNode* node;
	ID_List* ids;
	char* destination_type;
	char* op;

	void addDestination(char* dest) {
		destination = dest;
	}
	void addNode(ASTNode* nd) {
		node = nd;
	}
	void addIDList(ID_List* idlist) {
		ids = idlist;
	}
	void addDestType(char* type) {
		destination_type = type;
	}
	void addOp(char* operation) {
		op = operation;
	}
};

struct IR {
	char* op;
	char* reg1;
	char* reg2;
	char* reg3;
	void addOp(char* thing) {
		op = thing;
	}
	void addReg1(char* thing) {
		reg1 = thing;
	}
	void addReg2(char* thing) {
		reg2 = thing;
	}
	void addReg3(char* thing) {
		reg3 = thing;
	}
};

struct new_threeAC {
	string op;
	string reg1;
	string reg2;
	string reg3;
	void addOp(string thing) {
		op = thing;
	}
	void addReg1(string thing) {
		reg1 = thing;
	}
	void addReg2(string thing) {
		reg2 = thing;
	}
	void addReg3(string thing) {
		reg3 = thing;
	}
};

struct Tiny {
	string op;
	string reg1;
	string reg2;
	void addOp(string thing) {
		op = thing;
	}
	void addReg1(string thing) {
		reg1 = thing;
	}
	void addReg2(string thing) {
		reg2 = thing;
	}
};
