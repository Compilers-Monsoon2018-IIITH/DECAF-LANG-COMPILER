%{
#include "parser.tab.h"
int lineno = 0;
%}

%%
("true"|"false")		{printf("bool"); return bool;}
[a-zA-Z][a-zA-Z0-9]*	{printf("id"); return id;}
[0-9][0-9]*				{printf("dec"); return dec;}
[0x][a-fA-F0-9]+		{printf("hex"); return hex;}
["'"][a-zA-z]["'"]		{printf("char"); return "char";}
['"'][a-zA-z]*['"']		{printf("str"); return "str";}
"+"						{printf("add"); return '+';}
"-"						{printf("sub"); return '-';}
"*"						{printf("prod"); return '*';}
"/"						{printf("div"); return '/';}
"%"						{printf("mod"); return '%';}
"<"						{printf("lt"); return lt;}
">"						{printf("gt"); return gt;}
"<="					{printf("le"); return le;}
">="					{printf("ge"); return ge;}
"=="					{printf("eq"); return "==";}
"!="					{printf("neq"); return "!=";}
"&&"					{printf("and"); return "&&";}
"||"					{printf("or"); return "||";}
"("						{printf("openp"); return '(';}
")"						{return ')';}
[ \t]					{ }
\n		     			{++lineno;}
.						{ printf("Line No %d: Unrecognized Character\n", lineno); }

%%

