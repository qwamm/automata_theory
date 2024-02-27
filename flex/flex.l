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
SPACESHIP " " 
FIRST_LETTER [^0-9 ] 
NAME [a-zA-Z0-9]{0,15} 
TYPE (?:int|long|short) 
 
%% 
{TYPE}({SPACESHIP}{1,})({FIRST_LETTER})({NAME}{0,15}){LEFT_PARENT}({TYPE}({SPACESHIP}{1,})({FIRST_LETTER})({NAME}{0,15})(({SPACESHIP})*{COMMA}?({SPACESHIP})*)*)*{RIGHT_PARENT}{SEMICOLON} {std::cout << "GOOD\n"; s = yytext; return 1;} 
<<EOF>>   { return 2; }
%% 

#include <iostream>
#include <fstream>
#include <FlexLexer.h>
int main()
{
	float sum = 0;
	yyFlexLexer flp;
	std::ifstream in;
	in.open("input.txt");
	flp.switch_streams(in, std::cout);
        while (1)
	{
		t = clock();
		if (flp.yylex() == 2)
			break;
		t = clock() - t;
		std::cout << s << "\n";
		float tm = ((float)t)/CLOCKS_PER_SEC; 
		sum+=tm;
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
		//if (fname == "stop")
		//	break;
		if (overloads.contains(fname))
		{
			overloads[fname]++;
		}
		else
		{
			overloads[fname] = 0;
		}
	}
	in.close();
	std::cout << "TIME: " << sum << "\n";
	std::cout << "OVERLOADS:\n";
	for (auto &pair : overloads)
	{
		std::cout << pair.first << "\t" << pair.second << "\n";
	}
}
