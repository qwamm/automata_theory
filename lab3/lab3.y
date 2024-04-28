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

%left '>' '<'
%left '+' '-'
%left '*' '/'
%right '^'
%right UMINUS

%%

program:
 	program '\n' {
 		printf("empty string\n", $<ival>2);
 	}
 	| program expr '\n' {
 		printf("int result = %d\n", $<ival>2);
 		printf("bool result = %d\n", $<bval>2);
 	}
 	| {
 	printf("enter a expression:\n");
 	}
 	; 
expr:
	INTNUM {$<ival>$ = $<ival>1;}
	|
	BOOLNUM {$<bval>$ = $<bval>1; printf("BOOLNUM\n");}
	| expr '<' expr {$<ival>$ = $<ival>1 < $<ival>3;}
	| expr '>' expr {$<bval>$ = $<bval>1 > $<bval>3;}
	| expr '+' expr {$<ival>$ = $<ival>1 + $<ival>3;}
	| expr '-' expr {$<ival>$ = $<ival>1 - $<ival>3;}
	| expr '*' expr {$<ival>$ = $<ival>1 * $<ival>3;}
	| expr '/' expr {$<ival>$ = $<ival>1 / $<ival>3;}
	| expr '^' expr {$<ival>$ = pow($<ival>1 , $<ival>3);}
	| '(' expr ')' {$<ival>$ = $<ival>2;}
	| '-' expr %prec UMINUS      { $<ival>$ = -$<ival>2; } 
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
