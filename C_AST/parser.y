%{
#include <stdio.h>	
#include "ast.h"
#define YYSTYPE struct ASTNode *
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
program : class_def prog '{' '}' {$$ = getASTUnaryNode(getASTNodeNONE(),PROG_TYPE);printPostFix($$);printf("\n");return 0;}
		| class_def prog '{' fields '}' { $$ = getASTUnaryNode($4,PROG_TYPE); printPostFix($$);printf("\n");return 0;}
		;

fields  : field_decls
		{
		$$=getASTNodeBinaryNode($1,getASTNodeNONE(),FIELDS);
		}
		| method_decls
		{
		$$=getASTNodeBinaryNode(getASTNodeNONE(),$1,FIELDS);
		}
		| field_decls method_decls
		{
		$$=getASTNodeBinaryNode($1,$2,FIELDS);
		}
		;

field_decls : field_decls field_decl ';'
			{
			$$=getASTNodeBinaryNode($1,$2,FIELD_DECLS);
			}
			| field_decl ';'
			{
			$$=getASTNodeBinaryNode($1,getASTNodeNONE(),FIELD_DECLS);
			}
			;

field_decl : type list_id
			{
			$$=getASTNodeBinaryNode($1,$2,FIELD_DECL);
			}
		   ;

list_id   : id
			{
			$$=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),ID),getASTNodeNONE(),getASTNodeNONE(),LIST_ID);
			}
		  | id '[' int_literal ']'
			{
			$$=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),ID),$3,getASTNodeNONE(),LIST_ID);
			}
		  | list_id ',' id
			{
			$$=getASTNodeTernaryNode($1,getASTUnaryNode(getASTNodeNONE(),ID),getASTNodeNONE(),LIST_ID);
			}
		  | list_id ',' id '[' int_literal ']'
			{
			$$=getASTNodeTernaryNode($1,getASTUnaryNode(getASTNodeNONE(),ID),$5,LIST_ID);
			}

method_decls : method_decls method_decl
			   {
		    	$$=getASTNodeBinaryNode($1,$2,METHOD_DECLS);
			   }
			 | method_decl
				{
				$$=getASTNodeBinaryNode($1,getASTNodeNONE(),METHOD_DECLS);
				}
			 ;

method_decl  : type id '(' ')' block
			  {
			  $$=getASTNodeQuaternaryNode($1,getASTUnaryNode(getASTNodeNONE(),ID),$5,getASTNodeNONE(),METHOD_DECL);
			  }
			 | type id '(' inputs ')' block
			  {
			  $$=getASTNodeQuaternaryNode($1,getASTUnaryNode(getASTNodeNONE(),ID),$4,$6,METHOD_DECL);
			  }
			 | void_type id '(' ')' block
			  {
			  $$=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),ID),$5,getASTNodeNONE(),VOID_METHOD_DECL);
			  }
			 | void_type id '(' inputs ')' block
			  {
			  $$=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),ID),$4,$6,VOID_METHOD_DECL);
			  }
			 ;

inputs	: input
		{
		$$=getASTNodeBinaryNode($1,getASTNodeNONE(),INPUTS);
		}
		| inputs ',' input
		{
		$$=getASTNodeBinaryNode($1,$2,INPUTS);
		}
		;

input 	: type id
		{
		$$=getASTNodeBinaryNode($1,getASTUnaryNode(getASTNodeNONE(),ID),INPUT);
		}
		; 

block	: '{' block_parts '}'
		{
		$$=getASTUnaryNode($2,BLOCK);
		}
		| '{' '}'
		{
		$$=getASTUnaryNode(getASTNodeNONE(),BLOCK);
		}
		;

block_parts : var_declarations statements
			{
			$$=getASTNodeBinaryNode($1,$2,BLOCK_PARTS);
			}
			| statements
			{
			$$=getASTNodeBinaryNode($1,getASTNodeNONE(),BLOCK_PARTS);
			}
			| var_declarations
			{
			$$=getASTNodeBinaryNode(getASTNodeNONE(),$1,BLOCK_PARTS);
			}
			;

var_declarations : var_declaration ';'
					{
						$$=getASTNodeBinaryNode($1,getASTNodeNONE(),VAR_DECLS);
					}
				 | var_declarations var_declaration ';'
				 	{
				 		$$=getASTNodeBinaryNode($1,$2,VAR_DECLS);
				 	}
				 ;

statements	: statement
			{
				$$=getASTNodeBinaryNode($1,getASTNodeNONE(),STMTS);
			}
			| statements statement
			{
				$$=getASTNodeBinaryNode($1,$2,STMTS);
			}
			;

var_declaration : type ids
				{
					$$=getASTNodeBinaryNode($1,$2,VAR_DECL);
				}
				;

ids	: id
	{
		$$=getASTUnaryNode(getASTNodeNONE(),ID);
	}
	| ids ',' id
	{
		$$=getASTNodeBinaryNode($1,getASTUnaryNode(getASTNodeNONE(),ID),IDS);
	}
	;

type 		: int_type
			{
				$$=getASTUnaryNode(getASTNodeNONE(),INT_TYPE);
			}
			| bool_type
			{
				$$=getASTUnaryNode(getASTNodeNONE(),BOOL_TYPE);
			}
			;

statement 	: location assign_op expr ';'
			{
				$$=getASTNodeTernaryNode($1,$2,$3,STMT);
			}
			| method_call ';'
			{
				$$=getASTNodeTernaryNode($1,getASTNodeNONE(),getASTNodeNONE(),STMT);
			}
			| if_keyword '(' expr ')' block
			{
				$$=getASTNodeTernaryNode($3,$5,getASTNodeNONE(),STMT_IF);
			}
			| if_keyword '(' expr ')' block else_keyword block
			{
				$$=getASTNodeTernaryNode($3,$5,$7,STMT_IF_ELSE);
			}
			| for_keyword id ass expr ',' expr block
			{
				
			}
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