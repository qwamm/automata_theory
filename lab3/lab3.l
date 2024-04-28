%{
	#include "lab3.tab.h"
	#include <stdlib.h>
	#include <stdbool.h>
	#include <string.h>
	#include <math.h>
	void yyerror(const char*);
%}

TRUE "TRUE"

FALSE "FALSE"

%%

[0-9]+ {		
	yylval.ival = atoi(yytext);		
	//printf("INTNUM\n");
	return INTNUM;	
}

TRUE|FALSE {
	printf("%s\n", yytext);
	if (strcmp(yytext, "TRUE") == 0)
	{
		yylval.bval = true;
	}
	else
	{
		yylval.bval = false;
	}
	printf("%d\n", yylval.bval);
	return BOOLNUM;
}

[-+*/^?!<>\n] {
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
