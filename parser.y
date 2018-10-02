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

%left '+' '-' pe me
%left '*' '/' '%'
%left lt le
%left gt ge
%left not neq
%left eq ass
%left str_lit id true false int_type void_type bool_type if_keyword for_keyword return_keyword break_keyword continue_keyword else_keyword callout_keyword

%%
program : class_def prog '{' '}'
		| class_def prog '{' fields '}'
		;

fields  : method_decls fields
		| field_decls fields
		| method_decls
		| field_decls
		;

field_decls : field_decl field_decls
			| field_decl
			;

field_decl : type list_id
		   ;

list_id : id
		  | id '[' int_literal ']'
		  | id ',' list_id
		  | id '[' int_literal ']' ',' list_id

method_decls : method_decl method_decls
			 | method_decl
			 ;

method_decl  : method_type id '(' ')' block
			 | method_type id '(' inputs ')' block
			 ;

inputs	: input
		| input ',' inputs
		;

input 	: type id
		; 

block	: '{' var_declarations statements '}'
		;

var_declarations : var_declaration
				 | var_declaration var_declarations
				 |
				 ;

statements	: statement
			| statement statements
			|
			;

var_declaration : type ids
				;

ids	: id
	| id ',' ids
	;

method_type : int_type
			| void_type
			| bool_type
			;

type 		: int_type
			| bool_type
			;

statement 	: location assign_op expr
			| method_call
			| if_keyword '(' expr ')' block
			| if_keyword '(' expr ')' else_keyword block
			| for_keyword id ass expr ',' expr block
			| return_keyword
			| return_keyword expr
			| break_keyword
			| continue_keyword
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
			| expr ',' exprs
			;

expr : '(' expr ')'
	 |  not expr
	 |  '-' expr
	 |  expr bin_op expr
	 |  literal
	 |  id
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