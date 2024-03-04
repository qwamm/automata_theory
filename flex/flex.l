%option noyywrap
%option c++

%{
#include <iostream>
#include <string>
#include <unordered_map>
#include <stdlib.h>
#include <chrono>
std::string fname, s;
std::unordered_map<std::string, int> overloads;
int i,j;
int c = 0;
%}

COMMA "," 
SEMICOLON ";" 
RIGHT_PARENT ")" 
LEFT_PARENT "(" 
SPACESHIP [ \t]
FIRST_LETTER [a-zA-Z] 
NAME ([a-zA-Z0-9])
TYPE (?:int|long|short) 
 
%% 
{TYPE} {std::cout << "1" << "\n";} 
{SPACESHIP}+ {std::cout << "2" << "\n";}
{FIRST_LETTER}({NAME}{0,15}) {std::cout << "4" << "\n"; if (c == 0) {s = yytext; c++;}}
{LEFT_PARENT} {std::cout << "5" << "\n";}
{COMMA} {std::cout << "8" << "\n";}
{RIGHT_PARENT} {std::cout << "6" << "\n";}
{SEMICOLON} {std::cout << "7" << "\n";}

<<EOF>>   { return 2; }
%% 

#include <iostream>
#include <fstream>
#include <FlexLexer.h>
int main()
{
	float sum = 0;
	yyFlexLexer flp;
	flp.switch_streams(std::cin, std::cout);
        while (1)
	{
		auto start = std::chrono::system_clock::now();
		if (flp.yylex() == 2)
			break;
		std::cout << c << "\n";
		auto end = std::chrono::system_clock::now();
		sum += (float)(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
	}
	std::cout << "TIME: " << sum << "\n";
	std::cout << "OVERLOADS:\n";
	for (auto &pair : overloads)
	{
		std::cout << pair.first << "\t" << pair.second << "\n";
	}
}
