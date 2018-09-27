%{
#include <stdio.h>	
%}

%token id
%token dec
%token hex
%token bool
%left '+' '-'
%left '*' '/' '%'
%precedence "<="
%precedence ">="
%precedence "=="
%precedence "true"
%%

expr : '(' expr ')'
	 |  '!' expr
	 |  '-' expr
	 |  expr bin_op expr
	 |  literal
	 |  id
	 ;

bin_op : arith_op
	 |  rel_op
	 |  eq_op
	 |  cond_op
	 ;

arith_op : '+'
	 |  '-'
	 |  '*'
	 |  '/'
	 |  '%'
	 ;

rel_op : "gt"
	 |  "lt"
	 |  "ge"
	 |  "le"
	 ;

eq_op : "=="
	 |  "!="
	 ;

cond_op : "&&"
	 |  "||"
	 ;

literal : int_literal
	 |  "char"
	 |  bool_literal
	 ;

int_literal : dec
	 |  hex
	 ;

bool_literal : 't'
	 |  'f'
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