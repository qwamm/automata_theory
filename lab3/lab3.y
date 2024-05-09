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
	#include <iostream>
	#include <string>
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
%left '@'
%left ','
%left '>' '<'
%left '+' '-'
%left '?' '!'
%left '*' '/'
%left '^'
%left '[' ']'
%left SVAL
%right UMINUS

%%

program:
	program record '\n' {
		std::cout << "HERE RECORD\n";
		tree_parser x;
		std::cout << "SYNTAX TREE:\n";
		syntax_tree->put_tree(syntax_tree->root, 0);
		x.parse(syntax_tree->root);
	}
	| program block '\n' {
		std::cout << "HERE BLOCK\n";
		tree_parser x;
		std::cout << "SYNTAX TREE:\n";
		syntax_tree->put_tree(syntax_tree->root, 0);
		x.parse(syntax_tree->root);
	}
	| program proc '\n' {
		std::cout << "HERE PROC\n";
		tree_parser x;
		std::cout << "SYNTAX TREE:\n";
		syntax_tree->put_tree(syntax_tree->root, 0);
		x.parse(syntax_tree->root);
	}
	| program sentence '\n' {
		std::cout << "HERE SENTENCE\n";
		tree_parser x;
		std::cout << "SYNTAX TREE:\n";
		syntax_tree->put_tree(syntax_tree->root, 0);
		x.parse(syntax_tree->root);
	}
	| {
		syntax_tree = new ast();
		printf("enter a expression:\n");
	}
	;
record:
	RECORD SVAL DATA '['sentence']' CONVERSION FROM '[' sentence ']' CONVERSION TO '[' sentence ']'
	{
		$$.tree = new record_node(std::string($2.text), $5.tree, $10.tree, $15.tree , RECORDN);
		if ($$.tree) {syntax_tree->add($$.tree);}
	}
	|	RECORD SVAL DATA '['sentence']' CONVERSION FROM '[' sentence ']'
	{
		$$.tree = new record_node(std::string($2.text), $5.tree, $10.tree, nullptr, RECORDN);
		if ($$.tree) {syntax_tree->add($$.tree);}
	}
	| 	RECORD SVAL DATA '['sentence']' CONVERSION TO '[' sentence ']'
	{
		$$.tree = new record_node(std::string($2.text), $5.tree, nullptr, $10.tree , RECORDN);
		if ($$.tree) {syntax_tree->add($$.tree);}
	}
	;
block:
	BLOCK sentence UNBLOCK
	{
		if ($2.one) {syntax_tree->del_root();}
		$$.tree = new block_node($2.tree, BLOCKN);
		//if ($$.tree) {syntax_tree->add($$.tree);}
	}
	;

proc:
	PROC SVAL group_comma '&' block
	{
		$$.tree = new proc_node(std::string($2.text), $3.tree, $5.tree, PROCN);
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
        | PROC SVAL group_comma '&' sentence
        {
                $$.tree = new proc_node(std::string($2.text), $3.tree, $5.tree, PROCN);
                if ($3.one && $$.tree)
                {
                        syntax_tree->del_root();
                }
                if ($$.tree)
                {
                        syntax_tree->add($$.tree);
                }
        }
	;

declaration:
	TYPE SVAL {$$.tree = new decl_node(std::string($1.text), std::string($2.text), nullptr, nullptr, UNDEFVARN);
	syntax_tree->put_tree($$.tree, 0);}
	| TYPE SVAL '=' expr	{$$.tree = new decl_node(std::string($1.text), std::string($2.text), nullptr, $4.tree, VARN);
	 printf("NAME: %s\n", $2.text); printf("TYPE: %s\n", $1.text); syntax_tree->put_tree($$.tree, 0);}
	| TYPE SVAL '[' expr ']' {
		$$.tree = new decl_node(std::string($1.text), std::string($2.text), $4.tree, nullptr, UNDEFVARN); syntax_tree->put_tree($$.tree, 0);  
	}
	;

sentence:
	declaration  {$$ = $1; if ($$.tree){syntax_tree->add($$.tree);}}
	| expr {$$ = $1; if ($$.tree){syntax_tree->add($$.tree);}}
	| declaration '\n' sentence {$3.tree->set_left($1.tree); $$ = $3; std::cout << "SENTENCE AND GROUP SET\n";}
	| expr '\n' sentence {$3.tree->set_left($1.tree); $$ = $3; std::cout << "EXPR AND GROUP SET\n";}
	| '{' expr '}' block
	{
		$$.tree = new cond_node($2.tree, $4.tree, CONDN);
	}
	;

group_comma:
	declaration {$$ = $1;}
	| declaration ',' group_comma {std::cout << "GROUP COMMA\n";}
	;

arg_set:
	'\n' {printf("emprty string\n");}
	| expr { $$ = $1; std::cout << $1.text  << "\n";}
	| expr ',' arg_set {std::cout << "HERE\n";}
	;

expr:
	SVAL {$$.tree = new str_node(std::string($1.text), STRN); printf("SVAL WITH VAL = \"%s\"\n", $1.text);}
	| LITERAL {$$.tree = new str_node(std::string($1.text), LITERALN);  printf("LITERAL WITH VAL = \"%s\"\n", $1.text);}
	| INTNUM {$$.tree = new int_node(atoi($1.text), INTN); printf("INTNUM %d\n", atoi($1.text));}
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
	| '@' SVAL arg_set '|'
	{
	    		std::cout << "CALL HERE!\n";
	            $$.tree = new proc_node(std::string($2.text), $3.tree, nullptr, CALLN);
	            if ($$.tree)
	            {
	                    syntax_tree->add($$.tree);
	            }
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
