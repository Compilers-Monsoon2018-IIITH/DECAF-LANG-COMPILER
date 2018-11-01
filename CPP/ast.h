#include <bits/stdc++.h>

using namespace std;

typedef enum  exprType { binary = 1, location = 2, literal = 3, enclExpr = 4 } exprType;
typedef enum literalType { Int = 1, Bool = 2, Char = 3, String = 4 } literalType;

union Node{
	int number;
	char* value;
	class Prog* prog;
	class fieldDecls* fields;
	class fieldDecl* field;
	class Vars* vars;
	class Var* var;
	class methodDecls* methods;
	class methodDecl* method;
	class Block* block;
	class varDecls* var_decls;
	class varDecl* var_decl;
	class Stmts* stmts;
	class Stmt* stmt;
	class Expr* expr;
	class calloutArg* callout_arg;
	class calloutArgs* callout_args;
	class Params* parameters;
	class methodArgs* method_args;
	class methodArg* method_arg;
	class methodCall* method_call;
	class Location* location;
	class Assignment* assignment;
	class Literal* literal;
	class stringList* mylist;

	Node(){
		number = 0;
		value = NULL;
		fields = NULL;
		field = NULL;
		methods = NULL;
		method = NULL;
		var_decls = NULL;
		stmts = NULL;
		callout_args = NULL;
		method_args = NULL;
	}
	~Node(){};
};

typedef union Node YYSTYPE;

#define YYSTYPE_IS_DECLARED 1

class Var{
private:
	string declType;
	string name;
	string dataType;
	unsigned int length;
public:
	/* Constructors */
	Var(string,string,unsigned int);
	Var(string,string);
	/* Methods */
	void setDataType(string);
	void traverse();
};

class Vars{
private:
	vector<class Var*> vars_list;
	int cnt;
public:
	Vars(){}
	void push_back(class Var*);
	vector<class Var*> getVarsList();
	void traverse();
};

class fieldDecl{
private:
	string dataType;
	vector<class Var*> var_list;
public:
	fieldDecl(string,class Vars*);
	vector<class Var*> getVarsList();
	void traverse();
};

class fieldDecls{
private:
	vector<class fieldDecl*> decl_list;
	int cnt;
public:
	fieldDecls();
	void push_back(class fieldDecl*);
	void traverse();
};

class Expr{
protected:
	exprType etype;
public:
	void setEtype(exprType x){etype = x;}
	exprType getEtype();
	virtual string toString(){}
	virtual void traverse(){}
};

class EnclExpr:public Expr{
private:
	class Expr* expr;
public:
	EnclExpr(class Expr*);
	void traverse();
};

class unExpr:public Expr{
private:
	class Expr* body;
	string opr;
public:
	unExpr(string,class Expr*);
	void traverse();
};

class binExpr:public Expr{
private:
	class Expr* lhs;
	class Expr* rhs;
	string opr;
public:
	binExpr(class Expr*, string, class Expr*);
	void traverse();
};

class Location:public Expr{
private:
	string var;
	string location_type;
	class Expr* expr;
public:
	Location(string,string,class Expr*);
	Location(string,string);
	void traverse();
	string getVar();
	bool is_array();
	class Expr* getExpr();
};

class Literal:public Expr{
protected:
	literalType ltype;
public:
	virtual void traverse(){}
	virtual int getValue(){}
	virtual string toString(){}
};

class intLiteral:public Literal{
private:
	int value;
public:
	intLiteral(int);
	void traverse();
	int getValue();
	string toString();
};

class boolLiteral:public Literal{
private:
	string value;
public:
	boolLiteral(string);
	void traverse();
	string toString();
};

class charLiteral:public Literal{
private:
	char value;
public:
	charLiteral(string);
	void traverse();
};

class stringLiteral:public Literal{
private:
	string value;
public:
	stringLiteral(string);
	void traverse();
};

class Stmt{
public:
	virtual void traverse(){}
};

class Stmts{
private:
	vector<class Stmt*> stmts;
	int cnt;
public:
	Stmts();
	void push_back(class Stmt*);
	void traverse();
};
class methodCall:public Stmt,public Expr{
protected:
	string method_name;
public:
	virtual void traverse(){}
};

class calloutCall:public methodCall{
private:
	class calloutArgs* args;
public:
	calloutCall(string, class calloutArgs*);
	void traverse();
};

class Method:public methodCall{
private:
	class Params* params;
public:
	Method(string, class Params*);
	void traverse();
};

class Params{
private:
	vector<class Expr*> expr_list;
	int cnt;
public:
	Params();
	void push_back(class Expr*);
	void traverse();
};

class calloutArg{
private:
	class Expr* expr;
public:
	calloutArg(class Expr*);
	calloutArg(string literal);
	void traverse();
};

class calloutArgs{
private:
	vector<class calloutArg*> args_list;
	int cnt;
public:
	calloutArgs();
	void traverse();
	void push_back(class calloutArg*);
};


class Assignment:public Stmt{
private:
	class Location* loc;
	class Expr* expr;
	string opr;
public:
	Assignment(class Location*, string, class Expr*);
	void traverse();
};

class Block:public Stmt{
private:
	class varDecls* decls_list;
	class Stmts* stmts_list;
public:
	Block(class varDecls*,class Stmts*);
	void traverse();
};

class varDecl{
private:
	string type;
	vector<string> var_list;
	int cnt;
public:
	varDecl(string,class stringList*);
	void push_back(string);
	void traverse();
};

class stringList{
private:
	vector<string> list;
public:
	stringList(){}
	void push_back(string);
	vector<string> getList();
};
class varDecls{
private:
	vector<class varDecl*> decl_list;
	int cnt;
public:
	varDecls();
	void push_back(class varDecl*);
	void traverse();
};

class forStmt:public Stmt{
private:
	string var;
	class Expr* init;
	class Expr* condition;
	class Block* body;
public:
	forStmt(string, class Expr*, class Expr*, class Block*);
	void traverse();
};

class ifElseStmt:public Stmt{
private:
	class Expr* condition;
	class Block* if_block;
	class Block* else_block;
public:
	ifElseStmt(class Expr*, class Block*, class Block*);
	void traverse();
};

class returnStmt:public Stmt{
private:
	class Expr* ret;
public:
	returnStmt(class Expr*);
	void traverse();
};

class breakStmt:public Stmt{
public:
	breakStmt(){}
	void traverse();
};

class continueStmt:public Stmt{
public:
	continueStmt(){}
	void traverse();
};

class methodDecl{
private:
	string type;
	string name;
	class methodArgs* arg_list;
	class Block* body;
public:
	methodDecl(string type, string name, class methodArgs*, class Block*);
	void traverse();
};

class methodDecls{
private:
	vector< class methodDecl* > decl_list;
	int cnt;
public:
	methodDecls();
	void push_back(class methodDecl*);
	void traverse();
};

class methodArgs{
private:
	vector<class methodArg*> arg_list;
	int cnt;
public:
	methodArgs();
	void push_back(class methodArg*);
	void traverse();
};

class methodArg{
private:
	string type;
	string name;
public:
	methodArg(string,string);
	void traverse();
};

class Prog{
private:
	string name;
	class methodDecls* methods;
	class fieldDecls* fields;
public:
	Prog(string name,class fieldDecls*,class methodDecls*);
	void traverse();
};
