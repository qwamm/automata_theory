%{
	#include "lab3.tab.h"
	#include <stdlib.h>
	#include <stdbool.h>
	#include <math.h>
	void yyerror(const char*);
%}

TRUE "true"

FALSE "false"

%%

[0-9]+ {		
	yylval.ival = atoi(yytext);		
	return INTNUM;	
}

[01]|{TRUE}|{FALSE}	{
				yylval.bval = yytext;
				return BOOLNUM;
			}

[-+*/^?!<>\n] {return *yytext;}

[ \t]	;	/* skip tabs and whitespaces */

.	yyerror("Unknown character");

%%

int yywrap(void)
{
	return 1;
}
