%{
	#include <iostream>
	#include <cctype>
	#include <cstring>
	#include <vector>
	#include <stack>
	#include <ast.h>

	void yyerror(const char *error);
	int yylex();
	void clear_stack();
	stack <Expression*> nodes;
%}

%token SYMBOL

%union {
	Expression *exp;
	char symbol;
}

%type <exp> exp
%type <value> SYMBOL

/* Precedence information to resolve ambiguity */
%left '.'

%%
expr:
	'(' expr ')'

%
% 

