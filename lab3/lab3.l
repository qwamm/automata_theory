%option c++
%{
	#define YYSTYPE char*
	#include "lab3.tab.h"
	#include <stdlib.h>
	#include <stdbool.h>
	#include <string.h>
	#include <math.h>
	void yyerror(const char*);
%}

%%

[0-9]+ {		
	yylva2l = yytext;
	return INTNUM;
}

TRUE|FALSE {
	yylval = yytext;
	return BOOLNUM;
}

NUMERIC|LOGIC|STRING {
	yylval = yytext;
	return TYPE;
}

UNDEF {
	yylval = yytext;
	return UNDEF;
}

\".\" {
	yylval = yytext;
	return SVAL;
}

[-+*/^?!<>\n\"] {
	return *yytext;
}

[ \t]	;	/* skip tabs and whitespaces */

. {
	yyerror("Unknown character");
}
%%

int yywrap(void)
{
	return 1;
}
