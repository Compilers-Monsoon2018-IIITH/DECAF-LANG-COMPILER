%{
#include "calc.tab.h"
int lineno = 0;
%}

%%
[0-9]+				{yylval=atoi(yytext); return INT_LITERAL;}
"+"					{return '+';}
"-"					{return '-';}
"*"					{return '*';}
"/"					{return '/';}
"?"					{return '?';}
"("					{return '(';}
")"					{return ')';}
":"					{return ':';}
[ \t]				{ }
\n		     		{++lineno; return '\n';}
"$"					{return '$';}
.					{ printf("Line No %d: Unrecognized Character\n", lineno); }

%%

