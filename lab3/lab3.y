%language "c++"
%{
    #define YYSTYPE char*
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
 		std::cout << "emprty string\n";
 	}
 	| program expr '\n' {
 		printf("int result = %d\n", $<text>2);
 		printf("bool result = %d\n", $<text>2);
 	}
 	| {
 	printf("enter a expression:\n");
 	}
 	; 
expr:
	INTNUM {;}
	|
	BOOLNUM {printf("BOOLNUM\n");}
	| expr '<' expr {}
	| expr '>' expr {}
	| expr '+' expr {}
	| expr '-' expr {}
	| expr '?' expr {}
	| expr '!' expr {}
	| expr '*' expr {}
	| expr '/' expr {}
	| expr '^' expr {}
	| '(' expr ')' {}
	| '-' expr %prec UMINUS      {} 
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
