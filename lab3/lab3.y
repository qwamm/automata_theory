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
%token PROC
%token BLOCK
%token UNBLOCK
%token MOVE
%token PING
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
	| program group '\n' {
		//printf("result = %d\n", $2);
	}
	| {
		syntax_tree = new ast();
		printf("enter a expression:\n");
	}
	; 
group:
	sentence {$$ = $1; syntax_tree->put_tree($$.tree, 0); }
	| sentence ',' group
	{
		$1.tree->set_left($3.tree);
		$$ = $1;
	}
	| block { $$ = $1; }
	;
block:
	BLOCK group UNBLOCK
	{
		$$.tree = new block_node($1.tree, BLOCKN);  printf("%d\n", $1.tree == nullptr);
	}
	;
sentence:	
	expr {printf("%s\n", $1.text);}
	| TYPE SVAL {$$.tree = new decl_node($1.text, $2.text, 1, nullptr, UNDEFVARN);  syntax_tree->add($$.tree);
	syntax_tree->put_tree($$.tree, 0);}
	| TYPE SVAL '=' expr	{$$.tree = new decl_node($1.text, $2.text, 1, $4.tree, VARN); syntax_tree->add($$.tree); syntax_tree->
	put_tree($$.tree, 0); }
	| TYPE SVAL '[' INTNUM ']' {
		$$.tree = new decl_node($1.text, $2.text, atoi($4.text), nullptr, UNDEFVARN); syntax_tree->add($$.tree); syntax_tree->
		put_tree($$.tree, 0); 
	}
	| SVAL '[' INTNUM ']' '=' expr {
            $$.tree = new assign_node($1.text, atoi($3.text), $6.tree, ARRASSIGNN); syntax_tree->add($$.tree);
	 syntax_tree->put_tree($$.tree, 0); 
    }
    | SVAL '=' expr {
            $$.tree = new assign_node($1.text, 0, $3.tree, ASSIGNN); syntax_tree->add($$.tree);
             syntax_tree->put_tree($$.tree, 0); 
    }
	;
expr:
	INTNUM {$$.tree = new int_node(atoi($1.text), INTN); printf("INTNUM\n");}
	| BOOLNUM {bool buf; if (strcmp($1.text, "TRUE") == 0) {buf = true;} else {buf = false;} $$.tree = new bool_node(buf,
	 BOOLN); printf("BOOLNUM %d\n", buf);}
	| SVAL {$$.tree = new str_node($1.text, SVAL); printf("SVAL\n"); }
	| EF {printf("Programm finished successfully!\n");}
	| '(' expr ')' {$$.tree = $2.tree;}
	| expr '<' expr {$$.tree = new operation_node($1.tree, $3.tree, LESSN); }
	| expr '>' expr {$$.tree = new operation_node($1.tree, $3.tree, GREATERN); }
	| expr '+' expr {$$.tree = new operation_node($1.tree, $3.tree, PLUSN); }
	| expr '-' expr {$$.tree = new operation_node($1.tree, $3.tree, NEGN); }
	| expr '?' expr {$$.tree = new operation_node($1.tree, $3.tree, EQUN); }
	| expr '!' expr {$$.tree = new operation_node($1.tree, $3.tree, NOTEQUN); }
	| expr '*' expr {$$.tree = new operation_node($1.tree, $3.tree, MULN); }
	| expr '/' expr {$$.tree = new operation_node($1.tree, $3.tree, DIVN); }
	| expr '^' expr {$$.tree = new operation_node($1.tree, $3.tree, EXPN); }
	| '-' expr %prec UMINUS {$$.tree = new unary_node($1.tree, UMINN);}
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
	syntax_tree->put_tree(syntax_tree->root, 0);
	return 0;
}
