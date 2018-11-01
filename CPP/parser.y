%{
#include <stdio.h>	
%}

%token id
%token class_def
%token prog
%token char_lit
%token str_lit
%token dec
%token hex
%token true
%token false
%token lt le gt ge eq ass not neq
%token or and
%token int_type void_type bool_type
%token if_keyword for_keyword return_keyword break_keyword continue_keyword else_keyword 
%token pe me
%token callout_keyword

%left eq ass pe me
%left '+' '-'
%left '*' '/' '%'
%left lt le
%left gt ge
%left not neq
%left str_lit id true false int_type void_type bool_type if_keyword for_keyword return_keyword break_keyword continue_keyword else_keyword callout_keyword

%%
program : class_def prog '{' '}'
		| class_def prog '{' fields '}'
		;

fields  : field_decls 
		| method_decls
		| field_decls method_decls
		;

field_decls : field_decls field_decl ';'
			| field_decl ';'
			;

field_decl : type list_id
		   ;

list_id   : id
		  | id '[' int_literal ']'
		  | list_id ',' id
		  | list_id ',' id '[' int_literal ']'

method_decls : method_decls method_decl
			 | method_decl
			 ;

method_decl  : type id '(' ')' block
			 | type id '(' inputs ')' block
			 | void_type id '(' ')' block
			 | void_type id '(' inputs ')' block
			 ;

inputs	: input
		| inputs ',' input
		;

input 	: type id
		; 

block	: '{' block_parts '}'
		| '{' '}'
		;

block_parts : var_declarations statements
			| statements
			| var_declarations
			;

var_declarations : var_declaration ';'
				 | var_declarations var_declaration ';'
				 ;

statements	: statement
			| statements statement
			;

var_declaration : type ids
				;

ids	: id
	| ids ',' id
	;

type 		: int_type
			| bool_type
			;

statement 	: location assign_op expr ';'
			| method_call ';'
			| if_keyword '(' expr ')' block
			| if_keyword '(' expr ')' block else_keyword block
			| for_keyword id ass expr ',' expr block
			| return_keyword ';'
			| return_keyword expr ';'
			| break_keyword ';'
			| continue_keyword ';'
			| block
			;

assign_op 	: ass
			| pe
			| me
			;

method_call : method_name '(' ')'
			| method_name '(' exprs ')'
			| callout_keyword '(' str_lit ')'
			| callout_keyword '(' str_lit ',' callout_args ')'
			;

callout_args : callout_arg ',' callout_args
			| callout_arg
			;

location 	: id
			| id '[' expr ']'

exprs		: expr
			| exprs ',' expr
			;

expr : literal
	 | id
	 | '(' expr ')'
	 |  not expr
	 |  '-' expr
	 |  expr bin_op expr
	 ;

method_name  : id
			 ;

callout_arg  : expr
             | str_lit
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
	yyparse();
}

yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}