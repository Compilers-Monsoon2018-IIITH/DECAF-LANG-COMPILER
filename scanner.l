%{
#include "parser.tab.h"
int lineno = 0;
%}

%%
[i][n][t]				{printf("int_type "); return int_type;}
[v][o][i][d]			{printf("void_type "); return void_type;}
[b][o][o][l]			{printf("bool_type "); return bool_type;}
[i][f]					{printf("if keyword "); return if_keyword;}
[e][l][s][e]			{printf("else keyword "); return else_keyword;}
[f][o][r]				{printf("for keyword "); return for_keyword;}
[r][e][t][u][r][n]		{printf("return keyword "); return return_keyword;}
[b][r][e][a][k]			{printf("break keyword "); return break_keyword;}
[c][a][l][l][o][u][t]	{printf("callout keyword "); return callout_keyword;}
[c][o][n][t][i][n][u][e] {printf("continue keyword "); return continue_keyword;}
"class"					{printf("class "); return class_def;}
"Program"				{printf("program "); return prog;}
[t][r][u][e]			{printf("true "); return true;}
[f][a][l][s][e]			{printf("false "); return false;}
[a-zA-Z][a-zA-Z0-9]*	{printf("id "); return id;}
[0-9][0-9]*				{printf("dec "); return dec;}
[0x][a-fA-F0-9]+		{printf("hex "); return hex;}
["'"][a-zA-z]["'"]		{printf("char "); return char_lit;}
['"'][a-zA-z]*['"']		{printf("str "); return str_lit;}
"+="					{printf("plus_eq "); return pe;}
"+"						{printf("add "); return '+';}
"-="					{printf("minus_eq "); return me;}
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
","						{printf("comma "); return ',';}
[ \t]					{ }
\n		     			{++lineno;printf("\n");}
.						{ printf("Line No %d: Unrecognized Character\n", lineno); }

%%