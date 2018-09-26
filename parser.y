%{
#include <stdio.h>	
%}

%token id
%token dec
%token hex
%left '+' '-'
%left '*' '/'

%%

expr : '(' expr ')'
	 |  expr '+' expr
	 |  expr '-' expr
	 |  expr '*' expr
	 |  expr '/' expr
	 |  id
	 ;

%%

main(int argc, char **argv)
{
	yyparse();
	printf("Parsing Over\n");
}

yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}