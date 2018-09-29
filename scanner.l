%{
#include "parser.tab.h"
int lineno = 0;
%}

%%
[t][r][u][e]			{printf("true "); return true;}
[f][a][l][s][e]			{printf("false "); return false;}
[a-zA-Z][a-zA-Z0-9]*	{printf("id "); return id;}
[0-9][0-9]*				{printf("dec "); return dec;}
[0x][a-fA-F0-9]+		{printf("hex "); return hex;}
["'"][a-zA-z]["'"]		{printf("char "); return char_lit;}
['"'][a-zA-z]*['"']		{printf("str "); return str_lit;}
"+"						{printf("add "); return '+';}
"-"						{printf("sub "); return '-';}
"*"						{printf("prod "); return '*';}
"/"						{printf("div "); return '/';}
"%"						{printf("mod "); return '%';}
"<"						{printf("lt "); return lt;}
">"						{printf("gt "); return gt;}
"<="					{printf("le "); return le;}
">="					{printf("ge "); return ge;}
"=="					{printf("eq "); return eq;}
"="						{printf("ass "); return ass;}
"!"						{printf("not "); return not;}
"!="					{printf("neq "); return neq;}
"&&"					{printf("and "); return and;}
"||"					{printf("or "); return or;}
"("						{printf("openr "); return '(';}
")"						{printf("closer ");return ')';}
"["						{printf("opens "); return '[';}
"]"						{printf("closes ");return ']';}
"{"						{printf("openp "); return '{';}
"}"						{printf("closep "); return '}';}
[ \t]					{ }
\n		     			{++lineno;printf("\n");}
.						{ printf("Line No %d: Unrecognized Character\n", lineno); }

%%

