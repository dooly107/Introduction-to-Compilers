#include <cstdio>
#include <string>
#include <vector>
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

/*
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


