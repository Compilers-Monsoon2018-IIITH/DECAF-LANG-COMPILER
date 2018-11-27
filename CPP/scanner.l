%{
    #ifndef incl_ast
    #include "ast.h"
    #endif
    #include "parser.tab.h"

// for handling \n and all in printf

char * changeStr(char * string, int size) {
    char * ch = string;
    char * new_str = (char *) malloc(size + 1);
    char * temp = new_str;
    int i;
    for (i = 0; i < size; i++) {
        switch (*ch) {
            case '\\':
                i++;
                ch++;
                switch (*ch) {
                    case 'n':
                        *temp = '\n';
                        break;
                    case 't':
                        *temp = '\t';
                        break;
                    case '\\':
                        *temp = '\\';
                        break;
                    case '\'':
                        *temp = '\'';
                        break;
                    case '\"':
                        *temp = '\"';
                        break;
                    default:
                        break;
                }
                break;
            default: 
                *temp = *ch;
                break;
        }
        ch++;
        temp++;
    }
    *temp = '\0';
    return new_str;
}
    int lineno=0;
%}

%option nounput
%option noyywrap
%option yylineno

ALPHA [a-zA-Z]
CHAR ([\40-\176]{-}['"\\])|\\n|\\t|\\\\|\\\"|\\\'
DIGIT [0-9]
HEXADECIMAL [0-9a-fA-F]
UNDERSCOREDALPHA [a-zA-Z_]

%%
[i][n][t]                                       {/*printf("int_type ");*/ return int_type;}
[v][o][i][d]                                    {/*printf("void_type ");*/ return void_type;}
[b][o][o][l][e][a][n]                           {/*printf("bool_type "); */ return bool_type;}
[i][f]                                          {/*printf("if keyword ");*/ return if_keyword;}
[e][l][s][e]                                    {/*printf("else keyword ");*/ return else_keyword;}
[f][o][r]                                       {/*printf("for keyword ");*/ return for_keyword;}
[r][e][t][u][r][n]                              {/*printf("return_keyword ");*/ return return_keyword;}
[b][r][e][a][k]                                 {/*printf("break_keyword ");*/ return break_keyword;}
[c][a][l][l][o][u][t]                           {/*printf("callout_keyword ");*/ return callout_keyword;}
[c][o][n][t][i][n][u][e]                        {/*printf("continue_keyword ");*/ return continue_keyword;}
"class"                                         {/*printf("class ");*/ return class_def;}
"Program"                                       {/*printf("program ");*/ return prog;}
[t][r][u][e]                                    {/*printf("true ");*/ return bool_true;}
[f][a][l][s][e]                                 {/*printf("false ");*/ return bool_false;}
{UNDERSCOREDALPHA}({UNDERSCOREDALPHA}|{DIGIT})* {/*printf("id ");*/ yylval.sval = strdup(yytext);return id;}
{DIGIT}+                                        {/*printf("dec ");*/ yylval.ival = atoi(yytext); return int_val;}
0x{HEXADECIMAL}+                                {/*printf("hex ");*/ yylval.ival = atoi(yytext); return int_val;}
\"{CHAR}*\"                                     {/*printf("char ");*/ yylval.sval = changeStr(yytext + 1, strlen(yytext) - 2); return str_lit;}
\'{CHAR}\'                                      {/*printf("str ");*/  yylval.cval = yytext[1]; return char_lit; }
"+="                                            {/*printf("plus_eq ");*/return pe;}
"+"                                             {/*printf("add ");*/ return '+';}
"-="                                            {/*printf("minus_eq ");*/ return me;}
"-"                                             {/*printf("sub ");*/ return '-';}
"*"                                             {/*printf("prod ");*/ return '*';}
"/"                                             {/*printf("div ");*/ return '/';}
"%"                                             {/*printf("mod ");*/ return '%';}
"<"                                             {/*printf("lt ");*/ return lt;}
">"                                             {/*printf("gt ");*/ return gt;}
"<="                                            {/*printf("le ");*/ return le;}
">="                                            {/*printf("ge ");*/ return ge;}
"=="                                            {/*printf("eq ");*/ return eq;}
"="                                             {/*printf("ass ");*/ return ass;}
"!"                                             {/*printf("not ");*/ return not_op;}
"!="                                            {/*printf("neq ");*/ return neq;}
"&&"                                            {/*printf("and ");*/ return and_op;}
"||"                                            {/*printf("or ");*/ return or_op;}
"("                                             {/*printf("openr ");*/ return '(';}
")"                                             {/*printf("closer ");*/ return ')';}
"["                                             {/*printf("opens ");*/ return '[';}
"]"                                             {/*printf("closes ");*/ return ']';}
"{"                                             {/*printf("openp ");*/ return '{';}
"}"                                             {/*printf("closep ");*/ return '}';}
","                                             {/*printf("comma ");*/ return ',';}
";"                                             {/*printf("semi-colon ");*/ return ';';}
[\t ]                                           {}
[\n]                                            {++lineno;/*printf("\n");*/}
.                                               { printf("Line No %d: Unrecognized Character\n", lineno); exit(-1);}

%%