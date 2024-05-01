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

PROC {
	yylval.text = yytext;
	return PROC;
}

BLOCK {
	yylval.text = yytext;
	return BLOCK;
}

UNBLOCK {
	yylval.text = yytext;
	return UNBLOCK;
}

MOVEUP|MOVEDOWN|MOVERIGHT|MOVELEFT {
	yylval.text = yytext;
	return MOVE;
}

PINGUP|PINGDOWN|PINGLEFT|PINGRIGHT {
	yylval.text = yytext;
	return PING;
}

UNDEF {
	yylval.text = yytext;
	return UNDEF;
}

[a-zA-Z][a-zA-Z]* {
	yylval.text = yytext;
	return SVAL;
}

[-+*/^?!<>\n\"()=\[\],] {
	return *yytext;
}

[ \t]	;	/* skip tabs and whitespaces */

. {
	yyerror("Unknown character");
}

<<EOF>> {return EF;}

%%

int yywrap(void)
{
	return 1;
}
