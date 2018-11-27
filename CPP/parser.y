%{
  #include <iostream>
  #include <string>
  #include <vector>

  #ifndef incl_ast
  #include "ast.h"
  #endif
  #ifndef incl_codegen
  #include "codegen.h"
  #endif

  int yylex();
  int yyparse();
  void yyerror(const char *s);
%}

%union {
  assign_op_type assign_op;
  ASTBlock * block;
  ASTCalloutArg * callout_arg;
  ASTExpression * expr;
  ASTFieldDecl * field_decl;
  ASTId * ids;
  ASTLiteralExpression * literal;
  ASTLocation * location;
  ASTMethodCall * method_call;
  ASTMethodDecl * method_decl;
  ASTProgram * program;
  ASTStatement * statement;
  ASTInput * input;
  ASTVarDecl * var_declaration;
  char *sval;
  char cval;
  Datatype type;
  int ival;
  std::vector<ASTCalloutArg *> * callout_args;
  std::vector<ASTExpression *> * exprs;
  std::vector<ASTFieldDecl *> * field_decls;
  std::vector<ASTId *> * identifier_list;
  std::vector<ASTId *> * list_id;
  std::vector<ASTMethodDecl *> * method_decls;
  std::vector<ASTStatement *> * statements;
  std::vector<ASTInput *> * inputs;
  std::vector<ASTVarDecl *> * var_declarations;
}

%token bool_type
%token break_keyword
%token callout_keyword
%token class_def
%token prog
%token continue_keyword
%token else_keyword
%token bool_false
%token for_keyword
%token if_keyword
%token int_type
%token return_keyword
%token bool_true
%token void_type

%left or_op
%left and_op
%token ass pe me
%left eq neq
%nonassoc le lt ge gt
%left '+' '-'
%left '*' '/' '%'
%precedence not_op UMINUS

%token <cval> char_lit
%token <ival> int_val
%token <sval> id
%token <sval> str_lit
%type <assign_op> assign_op
%type <block> block
%type <callout_arg> callout_arg
%type <callout_args> callout_args
%type <expr> expr
%type <exprs> exprs
%type <field_decl> field_decl
%type <field_decls> field_decls
%type <identifier_list> identifier_list
%type <literal> literal
%type <location> location
%type <method_call> method_call
%type <method_decl> method_decl
%type <method_decls> method_decls
%type <program> program
%type <statement> statement
%type <statements> statements
%type <type> type
%type <input> input
%type <inputs> inputs
%type <var_declaration> var_declaration
%type <var_declarations> var_declarations
%type <ids> ids
%type <list_id> list_id

%%

program : class_def prog '{' '}' 
          { 
            $$ = new ASTProgram(NULL, NULL);
            codegenVisitor *root = new codegenVisitor($$);
            root->codegen();
          }
        | class_def prog '{' field_decls '}'  
          { 
            $$ = new ASTProgram($4, NULL);
            codegenVisitor *root = new codegenVisitor($$);
            root->codegen();
          }
        | class_def prog '{' method_decls '}' 
          { 
            $$ = new ASTProgram(NULL, $4);
            codegenVisitor *root = new codegenVisitor($$);
            root->codegen();
          }
        | class_def prog '{' field_decls method_decls '}' 
          { 
            $$ = new ASTProgram($4, $5);
            codegenVisitor *root = new codegenVisitor($$);
            root->codegen();
          }
        ;

field_decls     : field_decl 
                  { 
                    $$ = new std::vector<ASTFieldDecl *>(); $$->push_back($1); 
                  }
                | field_decls field_decl 
                  { 
                    $1->push_back($2); $$ = $1; 
                  }
                ;

field_decl  : type list_id ';' 
              { 
                $$ = new ASTFieldDecl($2, $1); 
              }
            ;

list_id : ids 
          { 
            $$ = new std::vector<ASTId *>(); $$->push_back($1); 
          }
        | list_id ',' ids 
          { 
            $1->push_back($3); $$ = $1; 
          }
        ;

identifier_list : id 
                  { 
                    $$ = new std::vector<ASTId *>(); $$->push_back(new ASTId(std::string($1))); 
                  }
                | identifier_list ',' id 
                  { 
                    $1->push_back(new ASTId(std::string($3))); $$ = $1; 
                  }
                ;

method_decls  : method_decl 
                { 
                  $$ = new std::vector<ASTMethodDecl *>(); $$->push_back($1); 
                }
              | method_decls method_decl 
                { 
                  $1->push_back($2); $$ = $1; 
                }
              ;

method_decl : type id '(' ')' block 
              { 
                $$ = new ASTMethodDecl(std::string($2), $1, NULL, $5); 
              }
            | type id '(' inputs ')' block 
              { 
                $$ = new ASTMethodDecl(std::string($2), $1, $4, $6); 
              }
            | void_type id '(' ')' block 
              { 
                $$ = new ASTMethodDecl(std::string($2), Datatype::void_type, NULL, $5); 
              }
            | void_type id '(' inputs ')' block 
              { 
                $$ = new ASTMethodDecl(std::string($2), Datatype::void_type, $4, $6); 
              }
            ;

inputs  : input 
          { 
            $$ = new std::vector<ASTInput *>(); $$->push_back($1); 
          }
        | inputs ',' input 
          { 
            $1->push_back($3); $$ = $1; 
          }
        ;

input : type id 
        { 
          $$ = new ASTInput(std::string($2), $1); 
        }
        ;

block : '{' '}' 
        { 
          $$ = new ASTBlock(NULL, NULL); 
        }
      | '{' var_declarations '}' 
        { 
          $$ = new ASTBlock(NULL, $2); 
        }
      | '{' statements '}' 
        { 
          $$ = new ASTBlock($2, NULL); 
        }
      | '{' var_declarations statements '}' 
        { 
          $$ = new ASTBlock($3, $2); 
        }
      ;

statements  : statement 
            { 
              $$ = new std::vector<ASTStatement *>(); $$->push_back($1); 
            }
            | statements statement 
            { 
              $1->push_back($2); $$ = $1; 
            }
            ;

var_declarations  : var_declaration 
                    { 
                      $$ = new std::vector<ASTVarDecl *>(); $$->push_back($1); 
                    }
                  | var_declarations var_declaration 
                    { 
                      $1->push_back($2); $$ = $1; 
                    }
                  ;

var_declaration : type identifier_list ';' 
                { 
                  $$ = new ASTVarDecl($2, $1); 
                }
                ;

ids   : id 
      { 
        $$ = new ASTId(std::string($1)); 
      }
      | id '[' int_val ']' 
      { 
        $$ = new ASTId(std::string($1), $3); 
      }

type  : int_type 
        { 
          $$ = Datatype::int_type; 
        }
      | bool_type 
        { 
          $$ = Datatype::bool_type; 
        }
      ;

statement   : ';' 
              { 
                $$ = NULL; 
              }
            | location assign_op expr ';' 
              { 
                $$ = new ASTAssignmentStatement($2, $1, $3); 
              }
            | method_call ';' 
              { 
                $$ = $1; 
              }
            | if_keyword '(' expr ')' block 
              { 
                $$ = new ASTIfStatement($3, $5, NULL); 
              }
            | if_keyword '(' expr ')' block else_keyword block 
              { 
                $$ = new ASTIfStatement($3, $5, $7); 
              }
            | for_keyword id ass expr ',' expr block 
              { 
                $$ = new ASTForStatement($4, $6, $7, std::string($2)); 
              }
            | return_keyword ';' 
              { 
                $$ = new ASTReturnStatement(NULL); 
              }
            | return_keyword expr ';' 
              { 
                $$ = new ASTReturnStatement($2); 
              }
            | break_keyword ';' 
              { 
                $$ = new ASTBreakStatement(); 
              }
            | continue_keyword ';' 
              { 
                $$ = new ASTContinueStatement(); 
              }
            | block 
              { 
                $$ = $1; 
              }
            ;

assign_op   : ass 
              { 
                $$ = assign_op_type::ass; 
              }
            | pe 
              { 
                $$ = assign_op_type::plus_equal; 
              }
            | me 
              { 
                $$ = assign_op_type::minus_equal; 
              }
          ;

method_call   : id '(' exprs ')' 
              { 
                $$ = new ASTMethod(std::string($1), $3); 
              }
              | id '(' ')' 
              { 
                $$ = new ASTMethod(std::string($1), NULL); 
              }
              | callout_keyword '(' str_lit ',' callout_args ')' 
              { 
                $$ = new ASTCallout(std::string($3), $5); 
              }
              | callout_keyword '(' str_lit ')' 
              { 
                $$ = new ASTCallout(std::string($3), NULL); 
              }
              ;
  
callout_args  : callout_arg
                { 
                  $$ = new std::vector<ASTCalloutArg *>(); $$->push_back($1); 
                }
              | callout_args ',' callout_arg 
              { 
                $1->push_back($3); $$ = $1; 
              }
              ;

location  : id 
            {
              $$ = new ASTVarLocation(std::string($1)); 
            }
          | id '[' expr ']' 
            { 
              $$ = new ASTArrayLocation(std::string($1), $3); 
            }
          ;

exprs   : expr 
        { 
          $$ = new std::vector<ASTExpression *>(); $$->push_back($1); 
        }
        | exprs ',' expr 
        { 
          $1->push_back($3); $$ = $1; 
        }
        ;

expr  : location
        {
          $$ = $1;
        }
      | method_call 
        {
            $$ = $1; 
        }
      | literal 
         {
            $$ = $1;
         }
      | expr or_op expr 
        { 
          $$ = new ASTBinaryOpExpr($1, $3, binary_op_type::or_op); 
        }
      | expr and_op expr 
        { 
          $$ = new ASTBinaryOpExpr($1, $3, binary_op_type::and_op); 
        }
      | expr eq expr 
        { 
          $$ = new ASTBinaryOpExpr($1, $3, binary_op_type::eq_op); 
        }
      | expr neq expr 
        { 
          $$ = new ASTBinaryOpExpr($1, $3, binary_op_type::neq_op); 
        }
      | expr lt expr 
        { 
          $$ = new ASTBinaryOpExpr($1, $3, binary_op_type::lt_op); 
        }
      | expr le expr 
        { 
          $$ = new ASTBinaryOpExpr($1, $3, binary_op_type::le_op); 
        }
      | expr ge expr 
        { 
          $$ = new ASTBinaryOpExpr($1, $3, binary_op_type::ge_op); 
        }
      | expr gt expr 
        { 
          $$ = new ASTBinaryOpExpr($1, $3, binary_op_type::gt_op); 
        }
      | expr '+' expr 
        { 
          $$ = new ASTBinaryOpExpr($1, $3, binary_op_type::plus_op); 
        }
      | expr '-' expr 
        { 
          $$ = new ASTBinaryOpExpr($1, $3, binary_op_type::minus_op); 
        }
      | expr '*' expr 
        { 
          $$ = new ASTBinaryOpExpr($1, $3, binary_op_type::multiply_op); 
        }
      | expr '/' expr 
        { 
          $$ = new ASTBinaryOpExpr($1, $3, binary_op_type::divide_op); 
        }
      | expr '%' expr 
        { 
          $$ = new ASTBinaryOpExpr($1, $3, binary_op_type::modulo_op); 
        }
      | not_op expr 
        { 
          $$ = new ASTUnaryOpExpr($2, UnOp::not_op); 
        }
      | '-' expr %prec UMINUS 
        { 
          $$ = new ASTUnaryOpExpr($2, UnOp::uminus_op); 
        }
      | '(' expr ')' 
        { 
          $$ = $2; 
        }
      ;

callout_arg   : expr  
              { 
                $$ = new ASTExpressionCalloutArg($1); 
              }
              | str_lit 
              { 
                $$ = new ASTStringCalloutArg(std::string($1)); 
              }
              ;

literal : int_val { $$ = new ASTIntegerLiteralExpression($1); }
        | char_lit { $$ = new ASTCharLiteralExpression($1); }
        | bool_true { $$ = new ASTTrueLiteralExpression(); }
        | bool_false { $$ = new ASTFalseLiteralExpression(); }
        ;

%%
int main ()
{
    return yyparse();
}

void yyerror(const char *s)
{
  fprintf(stderr, "error: %s\n", s);
}

/*

IMPROVEMENTS MADE COMPARED TO C PARSER

1. Shift Reduce Conflicts removed
2. Unnecessary grammar rules eliminated
3. Unnecessary variables eliminated
4. NONE node eliminated.
5. UMINUS %prec operator added

*/