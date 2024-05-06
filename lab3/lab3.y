%{
	#ifndef AST
	#define AST
	#include "nodes.h"
	#endif
	#include "tree_parser.h"
	#define YYSTYPE val
	struct val
	{
		char *text;
		bool one = true;
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
%token LITERAL
%token RECORD
%token DATA
%token CONVERSION
%token TO
%token FROM
%token PROC
%token BLOCK
%token UNBLOCK
%token MOVE
%token PING
%token VISION
%token VOICE
%token EF
%left '='
%left '[' ']'
%left '>' '<'
%left '+' '-'
%left '?' '!'
%left '*' '/'
%left '^'
%left SVAL
%right UMINUS

%%

program:
	program '\n' {
		printf("emprty string\n");
	}
	| program group '\n' {
		tree_parser x;
		x.parse(syntax_tree->root);
	}
	| {
		syntax_tree = new ast();
		printf("enter a expression:\n");
	}
	;
group:
	sentence {$$ = $1; printf("%d\n", $$.tree == nullptr); if ($$.tree) {syntax_tree->add($$.tree);} printf("MARKER\n"); }
	| sentence ',' group
	{
		$1.tree->set_left($3.tree);
		$$ = $1;
		if ($2.one == false)
			$$.one = false;
	}
	| block { $$ = $1; }
	;
block:
	BLOCK group UNBLOCK
	{
		if ($2.one) {syntax_tree->del_root();}
		$$.tree = new block_node($2.tree, BLOCKN);
		if ($$.tree) {syntax_tree->add($$.tree);}
	}
	| cond_operator {$$ = $1;}
	;
cond_operator:
	'{' expr '}' block
	{
		$$.tree = new cond_node($2.tree, $4.tree, CONDN);
		if ($$.tree) {syntax_tree->del_root(); syntax_tree->add($$.tree);}
	}
	| record {$$ = $1;}
	;
record:
	RECORD SVAL DATA '['group']'
	{

	}
	| proc{$$ = $1;}
	;

proc:
	PROC SVAL group '&' block
	{
		$$.tree = new proc_node($2.text, $3.tree, $5.tree, PROCN);
		if ($$.tree)
		{
			syntax_tree->del_root();
		}
		if ($3.one && $$.tree)
		{
			syntax_tree->del_root();
		}
                if ($$.tree)
                {
                        syntax_tree->add($$.tree);
                }
	}
        | PROC SVAL group '&' sentence
        {
                $$.tree = new proc_node($2.text, $3.tree, $5.tree, PROCN);
                if ($3.one && $$.tree)
                {
                        syntax_tree->del_root();
                }
                if ($$.tree)
                {
                        syntax_tree->add($$.tree);
                }
        }
	| call {$$ = $1;}
	;
call:
        SVAL group
        {
                $$.tree = new proc_node($1.text, $2.tree, nullptr, CALLN);
                if ($2.one && $$.tree)
                {
                        syntax_tree->del_root();
                }
                if ($$.tree)
                {
                        syntax_tree->add($$.tree);
                }
        }
	;

sentence:	
	expr {$$ = $1; printf("EXPR\n");}
	| TYPE SVAL {$$.tree = new decl_node($1.text, $2.text, nullptr, nullptr, UNDEFVARN);
	syntax_tree->put_tree($$.tree, 0);}
	| TYPE SVAL '=' expr	{char *str = (char*)malloc(strlen($2.text) + 1); strcpy(str, $2.text); $$.tree = new decl_node($1.text, str, nullptr, $4.tree, VARN);
	 printf("NAME: %s\n", $2.text); printf("TYPE: %s\n", $1.text); syntax_tree->put_tree($$.tree, 0); }
	| TYPE SVAL '[' expr ']' {
		$$.tree = new decl_node($1.text, $2.text, $4.tree, nullptr, UNDEFVARN); syntax_tree->put_tree($$.tree, 0); 
	}
	;
expr:
	SVAL {$$.tree = new str_node($1.text, STRN); printf("SVAL WITH VAL = \"%s\"\n", $1.text);}
	| LITERAL {$$.tree = new str_node($1.text, LITERALN);  printf("LITERAL WITH VAL = \"%s\"\n", $1.text);}
	| INTNUM {$$.tree = new int_node(atoi($1.text), INTN); printf("INTNUM\n");}
	| BOOLNUM {bool buf; if (strcmp($1.text, "TRUE") == 0) {buf = true;} else {buf = false;} $$.tree = new bool_node(buf,
	 BOOLN); printf("BOOLNUM %d\n", buf);}
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
	| expr '[' expr ']' {
		$$.tree = new arr_node($1.tree, $3.tree, ARRASSIGNN);
	}
	| expr '=' expr {
            $$.tree = new assign_node($1.tree, $3.tree, ASSIGNN);
             syntax_tree->put_tree($$.tree, 0); 
	}
	| MOVE '[' expr ']'
	{
		int op;
		if (strcpy($1.text, "MOVERIGHT") == 0)
		{
			op = MOVERIGHT;
		}
		else if (strcpy($1.text, "MOVELEFT") == 0)
		{
			op = MOVELEFT;
		}
		else if (strcpy($1.text, "MOVEUP") == 0)
		{
			op = MOVEUP;
		}
		else
		{
			op = MOVEDOWN;
		}
		$$.tree = new move_node($3.tree, op);
	}
	| PING '[' expr ']'
	{
                int op;
                if (strcpy($1.text, "PINGRIGHT") == 0)
                {
                        op = PINGRIGHT;
                }
                else if (strcpy($1.text, "PINGLEFT") == 0)
                {
                        op = PINGLEFT;
                }
                else if (strcpy($1.text, "PINGUP") == 0)
                {
                        op = PINGUP;
                }
                else
                {
                        op = PINGDOWN;
                }
                $$.tree = new ping_node($3.tree, op);
	}
	| VISION '[' expr ']'
	{
                $$.tree = new vision_node($3.tree, VISIONN);
	}
    | VOICE '[' expr ']'
    {
            $$.tree = new voice_node($3.tree, VOICEN);
    }
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
