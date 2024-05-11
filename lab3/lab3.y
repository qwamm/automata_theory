%{
	#ifndef AST
	#define AST
	#include "nodes.h"
	#include "robot.h"
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
	#include <fstream>
	#include <vector>
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
		std::cout << "SYNTAX TREE:\n";
		syntax_tree->put_tree(syntax_tree->root, 0);
	}
	| program block '\n' {
		std::cout << "HERE BLOCK\n";
		std::cout << "SYNTAX TREE:\n";
		syntax_tree->put_tree(syntax_tree->root, 0);
	}
	| program proc '\n' {
		std::cout << "HERE PROC\n";
		std::cout << "SYNTAX TREE:\n";
		if ($2.tree) {syntax_tree->add($2.tree);}
		syntax_tree->put_tree(syntax_tree->root, 0);
	}
	| program sentence '\n' {
		std::cout << "HERE SENTENCE\n";
		std::cout << "SYNTAX TREE:\n";
		if ($2.tree) {syntax_tree->add($2.tree);}
		syntax_tree->put_tree(syntax_tree->root, 0);
	}
	| {
		syntax_tree = new ast();
		printf("enter a expression:\n");
	}
	;
record:
	RECORD SVAL DATA '[' group_comma ']' CONVERSION FROM '[' TYPE ']' CONVERSION TO '[' TYPE ']'
	{
		$$.tree = new record_node(std::string($2.text), $5.tree, std::string($10.text), std::string($15.text) , RECORDN);
		if ($$.tree) {syntax_tree->add($$.tree);}
	}
	|	RECORD SVAL DATA '[' group_comma ']' CONVERSION FROM '[' TYPE ']'
	{
		$$.tree = new record_node(std::string($2.text), $5.tree, std::string($10.text), nullptr, RECORDN);
		if ($$.tree) {syntax_tree->add($$.tree);}
	}
	| 	RECORD SVAL DATA '[' '\n' group_comma ']' CONVERSION TO '[' TYPE ']'
	{
		$$.tree = new record_node(std::string($2.text), $5.tree, nullptr, std::string($10.text) , RECORDN);
		if ($$.tree) {syntax_tree->add($$.tree);}
	}
	;
block:
	BLOCK '\n' sentence UNBLOCK
	{
		$$.tree = new block_node($3.tree, BLOCKN);
		//if ($$.tree) {syntax_tree->add($$.tree);}
	}
	;

proc:
	PROC SVAL group_comma '&' block 
	{
			$$.tree = new proc_node(std::string($2.text), $3.tree, $5.tree, PROCN);
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
	declaration '\n'  {$$ = $1; }
	| expr '\n' {$$ = $1; }
	| cond '\n' {$$ = $1;}
	| declaration '\n' sentence {$3.tree->set_left($1.tree); $$ = $3; std::cout << "SENTENCE AND GROUP SET\n"; syntax_tree->put_tree($$.tree, 0);}
	| expr '\n' sentence {$3.tree->set_left($1.tree); $$ = $3; std::cout << "EXPR AND GROUP SET\n"; syntax_tree->put_tree($$.tree, 0);}
	| cond '\n' sentence {$3.tree->set_left($1.tree); $$ = $3; std::cout << "BLOCK AND GROUP SET\n"; syntax_tree->put_tree($$.tree, 0);}
	;

cond:
	'{' expr '}' block
	{
		$$.tree = new cond_node($2.tree, $4.tree, CONDN);
	}
	;

group_comma:
	declaration {$$ = $1;}
	| declaration ',' group_comma {$3.tree->set_left($1.tree); $$ = $3; std::cout << "DECLARATION GROUP COMMA\n"; syntax_tree->put_tree($$.tree, 0);}
	;

arg_set:
	expr { $$ = $1;}
	| expr ',' arg_set {$3.tree->set_left($1.tree); $$ = $3; std::cout << "EXPR AND ARG_SET\n"; syntax_tree->put_tree($$.tree, 0);}
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
	std::string line;
	std::vector<std::string> v;
	std::ifstream in;
	in.open("maze.txt");
	if (in.is_open())
	{
		while(std::getline(in,line))
		{
			v.push_back(line);
		}
		in.close();
	}
	robot r(v);
	std::cout << "BEFORE\n";
	r.print_field();
	std::cout << "GLOBAL\n";
	tree_parser x;
	x.parse(syntax_tree->root, x.global, r);
	x.global.print();
	std::cout << "AFTER\n";
	r.print_field();
	return 0;
}
