%{
	#include <stdio.h>
	#include <stdbool.h>
	#include <math.h>
	int yylex(void);
	void yyerror(const char*);
%}

%union {
	bool bval;
	int ival;
}

%token <ival> INTNUM
%token <bval> BOOLNUM

%%

program:
	program '\n' 
	{
		printf("empty string\n");
	}

	| program expr '\n'
	{
		printf("result = %d\n", $<ival>2);
	}
	|
	{
		printf("entern a expression:\n");
	}
	;
compare:
	compare '>' unary
	{
		$<ival>$ = $<ival>1 > $<ival>2;
		$<bval>$ = $<bval>1 > $<bval>2;
	}
	|
        compare '<' unary
        {
                $<ival>$ = $<ival>1 < $<ival>2;
                $<bval>$ = $<bval>1 < $<bval>2;
        }
	|
	compare '?' unary
	{
                $<ival>$ = $<ival>1 == $<ival>2;
                $<bval>$ = $<bval>1 == $<bval>2;
	}
	|
        compare '!' unary
        {
                $<ival>$ = $<ival>1 != $<ival>2;
                $<bval>$ = $<bval>1 != $<bval>2;
        }
	|
	unary
	{
		$<ival>$ = $<ival>1;
		$<bval>$ = $<bval>1;
	}
	;
unary:
	'-' expr
	{
		$<ival>$ = -$<ival>2;
		$<bval>$ = !($<bval>2);
	}
	|
	expr
	{
                $<ival>$ = $<ival>1;
                $<bval>$ = $<bval>1;
	}
	;
expr:
	INTNUM '+' INTNUM
	{
		$<ival>$ = $<ival>1 + $<ival>3;
	}
	|
	BOOLNUM '+' BOOLNUM
	{
		$<bval>$ = $<bval>1 || $<bval>3;
	}
	| expr '-' term
	{
		$<ival>$ = $<ival>1 - $<ival>3;
		$<bval>$ = $<bval>1 ^ $<bval>3;
	}
	| term
	{
                $<ival>$ = $<ival>1;
                $<bval>$ = $<bval>1;
	}
	;
term:
	term '*' power
	{
		$<ival>$ = $<ival>1 * $<ival>3;
		$<bval>$ = $<bval>1 && $<bval>3;
	}
	| term '/' power
	{
		$<ival>$ = $<ival>1 / $<ival>3;
		$<bval>$ = !($<bval>1 && $<bval>3);
	}
	| power
	{
                $<ival>$ = $<ival>1;
                $<bval>$ = $<bval>1;
	}
	;

power:
	factor '^' power
	{
		$<ival>$ = pow($<ival>1, $<ival>3);
		$<bval>$ = !($<bval>1 || $<bval>3);
	}
	|
	factor {
                $<ival>$ = $<ival>1;
                $<bval>$ = $<bval>1;
	}
	;

factor:
	INTNUM
	{
		printf("int=%d to factor : %d\n", $<ival>1, $<ival>$);
	}
	|
	BOOLNUM
	{
		printf("bool=%d to factor : %d\n", $<bval>1, $<bval>$);
	}
	|
	'(' expr ')'
	{
		$<ival>$ = $<ival>2;
		$<bval>$ = $<bval>2;
	}
	;
%%
#include <stdbool.h>

void yyerror(const char *s)
{
	fprintf(stderr, "%s\n", s);
}

int yylex(void)
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
}

int main(void)
{
	yyparse();
	return 0;
}
