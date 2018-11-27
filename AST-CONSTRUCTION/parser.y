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
				$$=getASTNodePentnaryNode(getASTUnaryNode(getASTNodeNONE(),ID),$3,$4,$6,$7,FOR);
			}
			| return_keyword ';'
			{
				$$=getASTNodeBinaryNode(getASTUnaryNode(getASTNodeNONE(),RET),getASTNodeNONE(),RETURN);
			}
			| return_keyword expr ';'
			{
				$$=getASTNodeBinaryNode(getASTUnaryNode(getASTNodeNONE(),RET),$2,RETURN);
			}
			| break_keyword ';'
			{
				$$=getASTUnaryNode(getASTNodeNONE(),BREAK);
			}
			| continue_keyword ';'
			{
				$$=getASTUnaryNode(getASTNodeNONE(),CONT);
			}
			| block
			{
				$$=getASTUnaryNode(getASTNodeNONE(),BLOCK);
			}
			;

assign_op 	: ass
			{
				$$=getASTUnaryNode(getASTNodeNONE(),ASS);
			}
			| pe
			{
				$$=getASTUnaryNode(getASTNodeNONE(),PLUS_EQ);
			}
			| me
			{
				$$=getASTUnaryNode(getASTNodeNONE(),MINUS_EQ);
			}
			;

method_call : method_name '(' ')'
			{
				$$=getASTNodeBinaryNode($1,getASTNodeNONE(),METHOD_CALL);
			}
			| method_name '(' exprs ')'
			{
				$$=getASTNodeBinaryNode($1,$3,METHOD_CALL);
			}
			| callout_keyword '(' str_lit ')'
			{
				$$=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),CALLOUT),getASTUnaryNode(getASTNodeNONE(),STR_LIT),getASTNodeNONE(),METHOD_CALL);
			}
			| callout_keyword '(' str_lit ',' callout_args ')'
			{
				$$=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),CALLOUT),getASTUnaryNode(getASTNodeNONE(),STR_LIT),$5,METHOD_CALL);
			}
			;

callout_args : callout_arg ',' callout_args
			{
				$$=getASTNodeBinaryNode($1,$3,CALLOUT_ARGS);
			}
			| callout_arg
			{
				$$=getASTNodeBinaryNode($1,getASTNodeNONE(),CALLOUT_ARGS);
			}
			;

location 	: id
			{
				$$=getASTNodeBinaryNode(getASTUnaryNode(getASTNodeNONE(),ID),getASTNodeNONE(),LOCATION);
			}
			| id '[' expr ']'
			{
				$$=getASTNodeBinaryNode(getASTUnaryNode(getASTNodeNONE(),ID),$3,LOCATION);
			}

exprs		: expr
			{
				$$=getASTNodeBinaryNode($1,getASTNodeNONE(),EXPRS);
			}
			| exprs ',' expr
			{
				$$=getASTNodeBinaryNode($1,$3,EXPRS);
			}
			;

expr : 	literal
	 {
		 $$=getASTNodeTernaryNode($1,getASTNodeNONE(),getASTNodeNONE(),EXPR);
	 }
	 | id
  	 {
   	 	 $$=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),ID),getASTNodeNONE(),getASTNodeNONE(),EXPR);
 	 }
	 | '(' expr ')'
	 {
	 	$$=$2;
	 }
	 |  not expr
	 {
	 	$$=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),NOT),$2,getASTNodeNONE(),EXPR);
	 }
	 |  '-' expr
	 {
	 	$$=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),SUB),$2,getASTNodeNONE(),EXPR);
	 }
	 |  expr bin_op expr
	 {
	 	$$=getASTNodeTernaryNode($1,$2,$3,EXPR);
	 }
	 ;

method_name  : id
			{
				$$=getASTUnaryNode(getASTNodeNONE(),ID);
			}
			 ;

callout_arg  : expr
			{
				$$=getASTUnaryNode($1,CALLOUT_ARG);
			}
             | str_lit
             {
             	$$=getASTUnaryNode(getASTUnaryNode(getASTNodeNONE(),STR_LIT),CALLOUT_ARG);
             }
             ;


bin_op : arith_op
		{
			$$=getASTUnaryNode($1,BIN_OP);
		}
	 |  rel_op
		{
			$$=getASTUnaryNode($1,BIN_OP);
		}
	 |  eq_op
		{
			$$=getASTUnaryNode($1,BIN_OP);
		}
	 |  cond_op
		{
			$$=getASTUnaryNode($1,BIN_OP);
		}
	 ;

arith_op : '+'
		{
			$$=getASTUnaryNode(getASTNodeNONE(),ADD);
		}
	 |  '-'
		{
			$$=getASTUnaryNode(getASTNodeNONE(),SUB);
		}
	 |  '*'
		{
			$$=getASTUnaryNode(getASTNodeNONE(),MUL);
		}
	 |  '/'
		{
			$$=getASTUnaryNode(getASTNodeNONE(),DIV);
		}
	 |  '%'
		{
			$$=getASTUnaryNode(getASTNodeNONE(),MOD);
		}
	 ;

rel_op : gt
	{
		$$=getASTUnaryNode(getASTNodeNONE(),GT);
	}
	 |  lt
	{
		$$=getASTUnaryNode(getASTNodeNONE(),LT);
	}
	 |  ge
	{
		$$=getASTUnaryNode(getASTNodeNONE(),GE);
	}
	 |  le
	{
		$$=getASTUnaryNode(getASTNodeNONE(),LE);
	}
	 ;

eq_op : eq
	{
		$$=getASTUnaryNode(getASTNodeNONE(),EQ);
	}
	 |  neq
	{
		$$=getASTUnaryNode(getASTNodeNONE(),NEQ);
	}
	 ;

cond_op : and
	{
		$$=getASTUnaryNode(getASTNodeNONE(),AND);
	}
	 |  or
	{
		$$=getASTUnaryNode(getASTNodeNONE(),OR);
	}
	 ;

literal : int_literal
	{
		$$=getASTUnaryNode(getASTNodeNONE(),INT_LIT);
	}
	 |  char_lit
	{
		$$=getASTUnaryNode(getASTNodeNONE(),CHAR_LIT);
	}
	 |  bool_literal
	{
		$$=getASTUnaryNode(getASTNodeNONE(),BOOL_LIT);
	}
	 ;

int_literal : dec
	{
		$$=getASTNodeIntLiteral(yylval);
	}
	 |  hex
	{
		$$=getASTNodeIntLiteral(yylval);
	}
	 ;

bool_literal : true
	{
		$$=getASTUnaryNode(getASTNodeNONE(),T);
	}
	 |  false
	{
		$$=getASTUnaryNode(getASTNodeNONE(),F);
	}
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