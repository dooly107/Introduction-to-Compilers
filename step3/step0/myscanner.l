%{
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;
ifstream read_file;
ofstream write_file;
%}

%option noyywrap c++

KEYWORD		(PROGRAM|BEGIN|END|FUNCTION|READ|WRITE|IF|ELSE|ENDIF|WHILE|ENDWHILE|RETURN|INT|VOID|STRING|FLOAT|TRUE|FALSE)
OPERATOR	\:=|\+|\-|\*|\/|\=|\!=|\<|\>|\(|\)|\;|\,|\<=|\>=
IDENTIFIER	[A-Za-z][A-Za-z0-9]*
FLOATLITERAL	[0-9]*\.[0-9]+
INTLITERAL	[0-9]+
STRINGLITERAL	(\".+\")
COMMENT		(\-\-.*)
WHITESPACE	\t|\r|\n|" "


%%

{KEYWORD}	{
			write_file << "Token Type: KEYWORD\n" << "Value: " << YYText() << endl;
		}

{OPERATOR}	{
			write_file << "Token Type: OPERATOR\n" << "Value: " << YYText() << endl;
		}

{IDENTIFIER}	{
			write_file << "Token Type: IDENTIFIER\n" << "Value: " << YYText() << endl;
		}

{FLOATLITERAL} 	{
			write_file << "Token Type: FLOATLITERAL\n" << "Value: " << YYText() << endl;
		}

{INTLITERAL}	{
			write_file << "Token Type: INTLITERAL\n" << "Value: " << YYText() << endl;
		}

{STRINGLITERAL}	{
			write_file << "Token Type: STRINGLITERAL\n" << "Value: " << YYText() << endl;
		}

{COMMENT}       {}

{WHITESPACE}	{}

%%

int main(int argc, char** argv) {
	read_file.open(argv[1], std::ifstream::in);
	write_file.open(argv[2], std::ofstream::out);
	FlexLexer* lexer = new yyFlexLexer;
	while(lexer -> yylex(&read_file, &write_file) != 0);
	read_file.close();
	write_file.close();
	return 0;
}
