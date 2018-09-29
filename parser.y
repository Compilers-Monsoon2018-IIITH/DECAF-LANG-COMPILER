%{
#include <stdio.h>	
%}

%token id
%token char_lit
%token str_lit
%token dec
%token hex
%token true
%token false
%token lt le gt ge eq ass not neq
%token or and

%left '+' '-'
%left '*' '/' '%'
%left lt le
%left gt ge
%left not neq
%left eq ass
%left str_lit id true false

%%

callout_arg  : expr
             | str_lit
             ;

expr : '(' expr ')'
	 |  not expr
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

rel_op : gt
	 |  lt
	 |  ge
	 |  le
	 ;

eq_op : eq
	 |  neq
	 ;

cond_op : and
	 |  or
	 ;

literal : int_literal
	 |  char_lit
	 |  bool_literal
	 ;

int_literal : dec
	 |  hex
	 ;

bool_literal : true
	 |  false
	 ;

%%

main(int argc, char **argv)
{
	while(true)
	{
		yyparse();
	}
	printf("Parsing Over\n");
}

yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}