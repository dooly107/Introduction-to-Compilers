#include <cstdio>
#include <string>
#include <iostream>
#include "../generated/parser.hpp"
using namespace std;
extern int yylex();
extern FILE* yyin;
extern char* yytext;

int main(int argc, char** argv) {
	FILE* file = fopen(argv[1], "r");
	FILE* output_file = fopen(argv[2], "w");
	yyin = file;
	int accept = yyparse();
	if (accept == 0) {
		fprintf(output_file, "Accepted");
	}
	else {
		fprintf(output_file, "Not Accepted");
	}
	fclose(file);
	fclose(output_file);
	return 0;
}
