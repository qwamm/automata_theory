%option noyywrap
%option c++

%{
#include <iostream>
#include <string>
#include <unordered_map>
#include "flex_rec.hpp"
#include <stdlib.h>
#include <chrono>
Flex_Recognizer rec;
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

bool Flex_Recognizer::check_string(std::string s, std::string *fname)
{
            yyFlexLexer flp;
            flp.switch_streams(std::cin, std::cout);
            //while (1)
            //{
	    bool ret = false;
            flp.yylex();
            if (rec.getState() == State::SEMICOLON)
            {
                    std::cout << "OK\n";
		    ret = true;
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
            this->setState(State::DEFAULT);
            //}
	    return ret;
}
