#include <cstdio>
#include <string>
#include <iostream>
#include "../generated/parser.hpp"
#include "../src/parserStruct.hpp"
extern int yylex();
extern FILE* yyin;
extern char* yytext;

int main(int argc, char** argv) {
	char* err;
	FILE* file = fopen(argv[1], "r");
	yyin = file;
	freopen(argv[2], "w", stdout);
	yyparse();
	err = error();
	if (err != NULL) {
		freopen(argv[2], "w", stdout);
		std::cout << "DECLARATION ERROR " << err << endl;
	}
	fclose(file);
	return 0;
}
