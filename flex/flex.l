%option noyywrap
%option c++

%{
#include <iostream>
#include <string>
#include <unordered_map>
#include "rec.hpp"
#include <stdlib.h>
#include <chrono>
Recognizer rec;
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
LINE_BREAK "\n"
%% 
{TYPE} {std::cout << "1" << "\n"; rec.Type();} 
{SPACESHIP}+ {std::cout << "2" << "\n"; rec.Spaceship();}
{FIRST_LETTER}({NAME}{0,15}) {std::cout << "4" << "\n";
 if(rec.is_parameter == true)
 {
	rec.ParameterName();
 }
 else
 {
	rec.FunctionName();
 }
 if (c == 0) {s = yytext; c++;}}
{LEFT_PARENT} {std::cout << "5" << "\n"; rec.LeftParent();}
{COMMA} {std::cout << "8" << "\n"; rec.Comma();}
{RIGHT_PARENT} {std::cout << "6" << "\n"; rec.RightParent();}
{SEMICOLON} {std::cout << "7" << "\n"; rec.Semicolon(); }
{LINE_BREAK} {return 0;}
<<EOF>>   { return 2; }
%% 

#include <iostream>
#include <fstream>
#include <chrono>
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
                auto end = std::chrono::system_clock::now();
		if (rec.getState() == State::SEMICOLON)
		{
			std::cout << "OK\n";
        		if (overloads.contains(s))
        		{
                		overloads[s]++;
        		}
        		else
        		{
                		overloads[s] = 0;
        		}
		}
		else if (rec.getState() == State::ERROR)
		{
			std::cout << "ERROR\n";
		}
		else
		{
			std::cout << "MACHINE ERROR\n";
		}
		c = 0;
		rec.setState(State::DEFAULT);
                sum += (float)(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
        }
        std::cout << "TIME: " << sum << "\n";
        std::cout << "OVERLOADS:\n";
        for (auto &pair : overloads)
        {
                std::cout << pair.first << "\t" << pair.second << "\n";
        }
}
