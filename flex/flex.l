%option noyywrap
%option c++

%{
#include <iostream>
#include <string>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>
std::string fname, s;
std::unordered_map<std::string, int> overloads;
int i,j;
clock_t t;
%}

COMMA "," 
SEMICOLON ";" 
RIGHT_PARENT ")" 
LEFT_PARENT "(" 
SPACESHIP [ \t]
FIRST_LETTER [^0-9 ] 
NAME [a-zA-Z0-9]{0,15} 
TYPE (?:int|long|short) 
 
%% 
{TYPE} {std::cout << "1" << "\n";} 
({SPACESHIP}+) {std::cout << "2" << "\n";}
({FIRST_LETTER})({NAME}{0,15}) {std::cout << "3" << "\n";}
(LEFT_PARENT) {std::cout << "4" << "\n";}
{TYPE}({SPACESHIP}+)({FIRST_LETTER})({NAME}{0,15})(({SPACESHIP})*{COMMA}?({SPACESHIP})*)* {std::cout << "5" << "\n";}
RIGHT_PARENT {std::cout << "6" << "\n";}
SEMICOLON {std::cout << "7" << "\n";}

<<EOF>>   { return 2; }
%% 

#include <iostream>
#include <fstream>
#include <FlexLexer.h>
int main()
{
	yyFlexLexer flp;
	std::ifstream in;
	in.open("input.txt");
	flp.switch_streams(in, std::cout);
        while (1)
	{
		if (flp.yylex() == 2)
			break;
	}
	in.close();
}
