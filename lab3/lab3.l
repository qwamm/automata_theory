%{
	#include "nodes.h"
        struct val
        {
                char *text;
		node *tree;
        };
        #define YYSTYPE val
	#include "lab3.tab.h"
	#include <cstdlib>
	#include <string>
	#include <cmath>
	void yyerror(const char*);
%}

%%

[0-9]+ {		
	yylval.text = yytext;
	return INTNUM;
}

TRUE|FALSE {
	yylval.text = yytext;
	return BOOLNUM;
}

NUMERIC|LOGIC|STRING {
	yylval.text = yytext;
	return TYPE;
}

UNDEF {
	yylval.text = yytext;
	return UNDEF;
}

\".\" {
	yylval.text = yytext;
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
