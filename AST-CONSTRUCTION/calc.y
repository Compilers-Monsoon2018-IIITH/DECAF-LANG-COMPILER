%{
#include <stdio.h>	
#include "ast.h"
#define YYSTYPE struct ASTNode *
%}

%token INT_LITERAL
%left '?'
%left '+' '-'
%left '*' '/'


%%

input	:	/* empty */		
		|	input line		
		;

line :	'\n'				{ printf(">>"); }
		|  expr '\n' 		{ printPostFix($1); printf("\n>>");}
		;

expr : '(' expr ')'			{ $$ = $2 ; }
	 |  expr '+' expr       { $$ = getASTNodeBinaryOp($1, $3, ADD); }
	 |  expr '-' expr       { $$ = getASTNodeBinaryOp($1, $3, SUB); }
	 |  expr '*' expr       { $$ = getASTNodeBinaryOp($1, $3, MUL); }
	 |  expr '/' expr       { $$ = getASTNodeBinaryOp($1, $3, DIV); }
	 |  expr '?' expr ':' expr  
	 	{ $$ = getASTNodeTernaryOp($1, $3, $5); }

	 |  INT_LITERAL         { $$ = getASTNodeIntLiteral(yylval); }
	 ;	

%%

main(int argc, char **argv)
{
	printf(">>");
	yyparse();
	printf("Parsing Over\n");
}

yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}