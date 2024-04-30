%{
	#include "nodes.h"
	#define YYSTYPE val
	struct val
	{
		char *text;
		node *tree;
	};
	ast *syntax_tree;
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
%token EF
%left '>' '<'
%left '+' '-'
%left '?' '!'
%left '*' '/'
%left '^'
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
		syntax_tree = new ast();
 		printf("enter a expression:\n");
 	}
 	; 
expr:
	INTNUM {$$.tree = new int_node(atoi($1.text), INTN); syntax_tree->root = $$.tree;; printf("INTNUM\n");}
	| BOOLNUM {bool buf; if ($1.text == "TRUE") {buf = true;} else {buf = false;} $$.tree = new bool_node(buf,
	 BOOLN); syntax_tree->root = $$.tree; printf("BOOLNUM\n");}
	| SVAL {$$.tree = new str_node($1.text, SVAL); printf("SVAL\n"); }
	| '(' expr ')' {$$.tree = $2.tree; syntax_tree->root = $$.tree;}
	| expr '<' expr {$$.tree = new operation_node($1.tree, $3.tree, LESSN); syntax_tree->root = $$.tree;}
	| expr '>' expr {$$.tree = new operation_node($1.tree, $3.tree, GREATERN); syntax_tree->root = $$.tree;}
	| expr '+' expr {$$.tree = new operation_node($1.tree, $3.tree, PLUSN); syntax_tree->root = $$.tree;}
	| expr '-' expr {$$.tree = new operation_node($1.tree, $3.tree, NEGN); syntax_tree->root = $$.tree;}
	| expr '?' expr {$$.tree = new operation_node($1.tree, $3.tree, EQUN); syntax_tree->root = $$.tree;}
	| expr '!' expr {$$.tree = new operation_node($1.tree, $3.tree, NOTEQUN); syntax_tree->root = $$.tree;}
	| expr '*' expr {$$.tree = new operation_node($1.tree, $3.tree, MULN); syntax_tree->root = $$.tree;}
	| expr '/' expr {$$.tree = new operation_node($1.tree, $3.tree, DIVN); syntax_tree->root = $$.tree;}
	| expr '^' expr {$$.tree = new operation_node($1.tree, $3.tree, EXPN); syntax_tree->root = $$.tree;}
	| '-' expr %prec UMINUS {$$.tree = new unary_node($1.tree, UMINN); syntax_tree->add($$.tree);} 
	| TYPE SVAL {$$.tree = new decl_node($1.text, $2.text, nullptr, UNDEFVARN); syntax_tree->add($$.tree);
	syntax_tree->put_tree($$.tree, 0);}
	| TYPE SVAL '=' expr	{$$.tree = new decl_node($1.text, $2.text, $4.tree, VARN); syntax_tree->
	put_tree($$.tree, 0); syntax_tree->add($$.tree);}     
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
	printf("ITERATION\n");
	syntax_tree->put_tree(syntax_tree->root, 0);
	return 0;
}
