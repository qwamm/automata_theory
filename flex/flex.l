%option noyywrap
%option c++

%{
#include <iostream>
#include <string>
#include <unordered_map>
#include <stdlib.h>
std::string fname, s;
std::unordered_map<std::string, int> overloads;
int i,j;
%}

COMMA "," 
SEMICOLON ";" 
RIGHT_PARENT ")" 
LEFT_PARENT "(" 
SPACESHIP " " 
FIRST_LETTER [^0-9 ] 
NAME [a-zA-Z0-9]{0,15} 
TYPE (?:int|long|short) 
 
%% 
{TYPE}({SPACESHIP}{1,})({FIRST_LETTER})({NAME}{0,15}){LEFT_PARENT}({TYPE}({SPACESHIP}{1,})({FIRST_LETTER})({NAME}{0,15})({COMMA}?({SPACESHIP})*))*{RIGHT_PARENT}{SEMICOLON} {s = yytext; return 0;} 
%% 

#include <iostream>
#include <fstream>
#include <FlexLexer.h>
int main()
{
    yyFlexLexer flp;
    while (1)
	{
		flp.yylex();
		std::string fname;
		for (i = 0; ;)
		{
			if (s[i] != ' ')
				i++;
			else
				break;
		}
		while (s[i] == ' ')
			i++;
		for (j = i; s[j] != ' ' && s[j] != '('; j++)
		{
			fname.push_back(s[j]);
		}
		std::cout << fname << "\n";
		if (fname == "stop")
			break;
		if (overloads.contains(fname))
		{
			overloads[fname]++;
		}
		else
		{
			overloads[fname] = 0;
		}
	}
	std::cout << "OVERLOADS:\n";
	for (auto &pair : overloads)
	{
		std::cout << pair.first << "\t" << pair.second << "\n";
	}
}
