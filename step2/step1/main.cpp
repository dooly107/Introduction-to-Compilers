#include <cstdio>
#include <string>
#include <iostream>
#include "parser.hpp"
using namespace std;
extern int yylex();
extern int yyparse();
extern FILE* yyin;

int main(int argc, char** argv) {
	FILE* file = fopen(argv[1], "r");
	yyin = file;
	yyparse();
	fclose(file);
}