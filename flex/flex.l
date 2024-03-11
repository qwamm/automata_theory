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
std::string buf;
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
DIGIT [0-9]
NAME ([a-zA-Z0-9])
TYPE (?:int|long|short) 
LINE_BREAK "\n"
%% 
{TYPE} {std::cout << "1" << "\n"; rec.Type();} 
{SPACESHIP}+ {std::cout << "2" << "\n"; rec.Spaceship();}
[0-9]({NAME}{0,15}) {rec.setState(State::ERROR);}
{FIRST_LETTER}({NAME}{0,15}) {std::cout << "4" << "\n";
 //std::cout << yytext << "\n";
 if(rec.is_parameter == true)
 {
	rec.ParameterName();
 }
 else
 {
	rec.FunctionName();
 }
 if (c == 0) {buf = yytext; c++;}}
{LEFT_PARENT} {std::cout << "5" << "\n"; rec.LeftParent();}
{COMMA} {std::cout << "8" << "\n"; rec.Comma();}
{RIGHT_PARENT} {std::cout << "6" << "\n"; rec.RightParent();}
{SEMICOLON} {std::cout << "7" << "\n"; rec.Semicolon(); }
`{LINE_BREAK} {return 0;}
<<EOF>>   { return 2; }
%% 

#include <sstream>

bool Flex_Recognizer::check_string(std::string s)
{
	    rec.is_parameter = false;
            yyFlexLexer flp;
	    std::stringstream ss;
	    ss << s;
            flp.switch_streams(ss, std::cout);
	    bool ret = false;
	    std::cout << "STATE: " <<  (int)rec.getState() << "\n";
            flp.yylex();
            if (rec.getState() == State::SEMICOLON)
            {
                    std::cout << "OK\n";
		    fname = buf;
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
            rec.setState(State::DEFAULT);
	    return ret;
}
