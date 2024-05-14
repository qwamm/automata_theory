%{
	#ifndef AST
	#define AST
	#include "nodes.h"
	#endif
        struct val
        {
                char *text;
		bool one = true;
		node *tree;
        };
        #define YYSTYPE val
	#include "lab3.tab.h"
	#include <cstdlib>
	#include <cstring>
	#include <cmath>
	void yyerror(const char*);
%}

%%

[0-9]+ {
	std::cout << "INTNUM CAPTURED " << yytext << "\n";
	yylval.text = new char[strlen(yytext) + 1];
	strcpy(yylval.text, yytext);
	return INTNUM;
}

TRUE|FALSE {
	yylval.text = yytext;
	return BOOLNUM;
}

NUMERIC|LOGIC|STRING {
	yylval.text = (char*)malloc(strlen(yytext) + 1);
	strcpy(yylval.text, yytext);
	printf("TYPE CAPTURED: %s\n", yytext);
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

RECORD {
        yylval.text = (char*)malloc(strlen(yytext) + 1);
        strcpy(yylval.text, yytext);
	return RECORD;
}

DATA {
	yylval.text = yytext;
	return DATA;
}

CONVERSION {
	yylval.text = yytext;
	std::cout << "CONVERSION CAPTURED\n";
	return CONVERSION;
}

TO {
	yylval.text = yytext;
	std::cout << "TO CAPTURED\n";
	return TO;
}

FROM {
	yylval.text = yytext;
	return FROM;
}

BLOCK {
	yylval.text = yytext;
	std::cout << "BLOCK CAPTURED\n";
	return BLOCK;
}

UNBLOCK {
	yylval.text = yytext;
	std::cout << "UNBLOCK CAPTURED\n";
	return UNBLOCK;
}

MOVEUP|MOVEDOWN|MOVERIGHT|MOVELEFT {
        yylval.text = (char*)malloc(strlen(yytext) + 1);
        strcpy(yylval.text, yytext);
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

[-&+*/^?!<>\n\"()=\[\],.{}@|] {
	std::cout << "SYMBOL CAPTURED " << yytext << "\n";
        return *yytext;
}

[a-zA-Z]([a-zA-Z0-9])* {
	yylval.text = (char*)malloc(strlen(yytext) + 1);
	strcpy(yylval.text, yytext);
	printf("SVAL CAPTURED: %s\n", yytext);
	return SVAL;
}
\"[a-zA-Z]([a-zA-Z0-9])*\" {
        yylval.text = (char*)malloc(strlen(yytext) + 1);
	int i = 0;
        for (i = 1; i < strlen(yytext) - 1; i++)
	{
		yylval.text[i-1] = yytext[i];
	}
	yylval.text[i-1] = '\0';
	printf("%d\n", i);
        printf("LITERAL CAPTURED: %s\n", yytext);
        return LITERAL;
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
