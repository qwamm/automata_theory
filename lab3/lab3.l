%{
	#include "nodes.h"
        struct val
        {
                char *text;
		bool one = true;
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

VISION {
	yylval.text = yytext;
	return VISION;
}

VOICE {
        yylval.text = yytext;
        return VOICE;
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

[-+*/^?!<>\n\"()=\[\],{}] {
        return *yytext;
}

[a-zA-Z]([a-zA-Z0-9])* {
	//yylval.text = yytext;
	yylval.text = (char*)malloc(strlen(yytext) + 1);
	strcpy(yylval.text, yytext);
	printf("SVAL CAPTURED: %s\n", yytext);
	return SVAL;
}

[ \t]	;	/* skip tabs and whitespaces */

. {
	printf("%s\n", yytext);
	yyerror("Unknown character");
}

<<EOF>> {return EF;}

%%

int yywrap(void)
{
	return 1;
}
