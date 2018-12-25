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

/*
struct IR {
	toList* list;
	map<char*, char*> stringList;
	list<char*> intList;
	list<char*> floatList;

	void addToList(toList* lst) {
		list = lst;
	}
	void addStringList(map <char*, char*> lst) {
		stringList = lst;
	}
	void addIntList(list <char*> lst) {
		intList = lst;
	}
	void addFloatList(list <char*> lst) {
		floatList = lst;
	}
};
*/




/*
//Step4


struct Primary {
	Expr* exp;
	char* id;
	char* i_val;
	char* f_val;
	void addExpr(Expr* ep) {
		exp = ep;
		id = NULL;
		i_val = NULL;
		f_val = NULL;
	}
	void addID(char* id_val) {
		id = id_val;
		exp = NULL;
		i_val = NULL;
		f_val = NULL;
	}
	void addInt(char* intval) {
		i_val = intval;
		exp = NULL;
		id = NULL;
		f_val = NULL;
	}
	void addFloat(char* floatval) {
		f_val = floatval;
		exp = NULL;
		id = NULL;
		i_val = NULL;
	}
};

struct Postfix_Expr {
	Primary* prim;
	Call_Expr* CE;
	void addPrimary(Primary* p) {
		prim = p;
		CE = NULL;
	}
	void addCallExpr(Call_Expr* call) {
		CE = call;
		prim = NULL;
	}
};

struct Factor_Prefix {
	Factor_Prefix* factor_prefix;
	Postfix_Expr* post_expr;
	char* sign;
	void addFactorPrefix(Factor_Prefix* fp) {
		factor_prefix = fp;
	}
	void addPostfix(Postfix_Expr* pf) {
		post_expr = pf;
	}
	void mulopNode(char* mulordiv) {
		sign = mulordiv;
	}
};

struct Factor {
	Factor_Prefix* factor_prefix;
	Postfix_Expr* post_expr;
	void addFactorPrefix(Factor_Prefix* fp) {
		factor_prefix = fp;
	}
	void addPostfix(Postfix_Expr* pf) {
		post_expr = pf;
	}
};

struct Expr_Prefix {
	Expr_Prefix* expr_prefix;
	Factor* factor;
	char* sign;
	void addExprPrefix(Expr_Prefix* ep) {
		expr_prefix = ep;
	}
	void addFactor(Factor* f) {
		factor = f;
	}
	void addopNode(char* plusorminus) {
		sign = plusorminus;
	}
};

struct Expr_List {
	Expr* exp;
	Expr_List* nextExp;
	void addExpr(Expr* ep) {
		exp = ep;
	}
	void nextExpr(Expr_List* NE) {
		nextExp = NE;
	}
};

struct Expr {
	Expr_Prefix* expr_prefix;
	Factor* factor;
	void addExprPrefix(Expr_Prefix* ep) {
		expr_prefix = ep;
	}
	void addFactor(Factor* f) {
		factor = f;
	}
};

struct Call_Expr {
	char* id;
	Expr_List* EL;
	void addID(char* id_val) {
		id = id_val;
	}
	void addExprList(Expr_List* list) {
		EL = list;
	}
};
*/
/*
struct ASTNode_List {
	ASTNode* curAST;
	ASTNode_List* nextAST;
	void addAST(ASTNode* AST) {
		curAST = AST;
	}
	void nextAST(ASTNode_List* nxtAST) {
		nextAST = nxtAST;
	}
};

struct ExpressionNode {
	char* expr;
	ExpressionNode* op1;
	ExpressionNode* op2;
	void addNode(char* expression, ExpressionNode* node1, ExpressionNode* node2) {
		expr = expression;
		op1 = node1;
		op2 = node2;
	}
	void addNode(char* expression) {
		expr = expression;
		op1 = NULL;
		op2 = NULL;
	}
};

struct Stmt_List {
	Stmt_List* next_stmt_list;
	void printST() {
		cout << "\nSymbol table BLOCK " << i << endl;
		i = i + 1;
	}
	void nextST(Stmt_List* next_stmt) {
		next_stmt_list = next_stmt;
	}
};

struct Func_Body {
	Stmt_List* st_list;
	void insertStmtList(Stmt_List* list) {
		st_list = list;
	}
}

struct Func_Decl {
	char* any_type;
	char* id;
	Param_Decl_List* param_decl_lst;
	Func_Body* func_b;
	void addType(char* type) {
		any_type = type;
	}
	void addID(char* get_id) {
		id = get_id;
		cout << "\nSymbol table " << id << endl;
	}
	void insertParamList(Param_Decl_List* list) {
		param_decl_lst = list;
	}
	void insertFuncBody(Func_Body* bd) {
		statement_list = st_list;
	}
};

struct Func_Declarations {
	Func_Decl* fd;
	Func_Declarations* next_function;
	void addFD(Func_Decl* func_decl) {
		fd = func_decl;
	}
	void nextFD(Func_Declarations* next_fd) {
		next_function = next_fd;
	}
};
*/


