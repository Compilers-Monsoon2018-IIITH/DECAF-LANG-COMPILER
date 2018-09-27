%{
#include "parser.tab.h"
int lineno = 0;
%}

%%
"true" | "flase"		{return bool;}
[a-zA-Z][a-zA-Z0-9]*	{return id;}
[0-9][0-9]*				{return dec;}
[0x][a-fA-F0-9]+		{return hex;}
["'"][a-zA-z]["'"]		{return "char";}
['"'][a-zA-z]*['"']		{return "str";}
"+"						{return '+';}
"-"						{return '-';}
"*"						{return '*';}
"/"						{return '/';}
"%"						{return '%';}
"<"						{return '<';}
">"						{return '>';}
"<="					{return "<=";}
">="					{return ">=";}
"=="					{return "==";}
"!="					{return "!=";}
"&&"					{return "&&";}
"||"					{return "||";}
"("						{return '(';}
")"						{return ')';}
[ \t]					{ }
\n		     			{++lineno;}
.						{ printf("Line No %d: Unrecognized Character\n", lineno); }

%%

