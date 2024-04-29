%{
	#include "nodes.h"
	#define YYSTYPE val
	struct val
	{
		char *text;
		node *tree;
	};
	node *ast;
	#include <stdio.h>
	#include <stdbool.h>
	#include <math.h>
	int yylex(void);
	void yyerror(const char*);
%}

%token INTNUM
%token BOOLNUM
%token TYPE
%token UNDEF
%token SVAL
%left '>' '<'
%left '+' '-'
%left '?' '!'
%left '*' '/'
%right '^'
%right UMINUS

%%

program:
 	program '\n' {
 		printf("emprty string\n");
 	}
 	| program expr '\n' {
 		printf("result = %d\n", $2);
 	}
 	| {
 	printf("enter a expression:\n");
 	}
 	; 
expr:
	INTNUM {$$.tree = new node(INTN); printf("INTNUM\n");}
	| BOOLNUM {$$.tree = new node(BOOLN); printf("BOOLNUM\n");}
	| SVAL {$$.tree = new node(SVAL); printf("SVAL\n");}
	| expr '<' expr {$$.tree = new operation_node($1.tree, $2.tree, LESSN);}
	| expr '>' expr {$$.tree = new operation_node($1.tree, $2.tree, GREATERN);}
	| expr '+' expr {$$.tree = new operation_node($1.tree, $2.tree, PLUSN);}
	| expr '-' expr {$$.tree = new operation_node($1.tree, $2.tree, NEGN);}
	| expr '?' expr {$$.tree = new operation_node($1.tree, $2.tree, EQUN);}
	| expr '!' expr {$$.tree = new operation_node($1.tree, $2.tree, NOTEQUN);}
	| expr '*' expr {$$.tree = new operation_node($1.tree, $2.tree, MULN);}
	| expr '/' expr {$$.tree = new operation_node($1.tree, $2.tree, DIVN);}
	| expr '^' expr {$$.tree = new operation_node($1.tree, $2.tree, EXPN);}
	| '(' expr ')' {$$.tree = $1.tree;}
	| '-' expr %prec UMINUS      {$$.tree = new unary_node($1.tree, UMINN);} 
	;


%%

#include <stdbool.h>

void yyerror(const char *s)
{
	fprintf(stderr, "%s\n", s);
}

/*int yylex(void)
{
	int c;
	while ((c = getchar()) == ' '|| c == '\t')
	;
	if (isdigit(c) && (c == '0' || c == '1'))
	{
		ungetc (c, stdin);
		scanf ("%d", &yylval);
		return BOOLNUM;
	}
	else if (isdigit(c))
	{
		ungetc (c, stdin);
		scanf ("%d", &yylval);
		return INTNUM;
	}
	if (c == EOF)
		return 0;
	return c;  
}*/

int main(void)
{
	yyparse();
	return 0;
}
