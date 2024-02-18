%option noyywrap
%option c++

%{
#include <stdlib.h>
%}

COMMA "," 
SEMICOLON ";" 
RIGHT_PARENT ")" 
LEFT_PARENT "(" 
SPACESHIP " " 
FIRST_LETTER [^0-9] 
NAME [a-zA-Z0-9]{0,15} 
TYPE (?:int|long|short) 
 
%% 
{TYPE}{SPACESHIP}{FIRST_LETTER}{NAME}{LEFT_PARENT}({TYPE}{SPACESHIP}{FIRST_LETTER}{NAME}({COMMA})?)*{RIGHT_PARENT}{SEMICOLON} {std::cout << "GOOD\n";} 
%% 

#include <iostream>
#include <fstream>
#include <FlexLexer.h>
int main()
{
    yyFlexLexer flp;
    while (std::cin.good())
	if (flp.yylex())
		std::cout << "good\n";
	else
		std::cout<<"bad\n";
}
