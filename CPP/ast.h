#ifndef incl_ast
#define incl_ast

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <llvm/IR/BasicBlock.h>

class ASTProgram;
class ASTFieldDecl;
class ASTVarDecl;
class ASTId;
class ASTMethodDecl;
class ASTInput;
class ASTStatement;
class ASTExpression;
class ASTBlock;
class ASTAssignmentStatement;
class ASTMethodCall;
class ASTMethod;
class ASTCallout;
class ASTCalloutArg;
class ASTStringCalloutArg;
class ASTExpressionCalloutArg;
class ASTIfStatement;
class ASTForStatement;
class ASTReturnStatement;
class ASTContinueStatement;
class ASTBreakStatement;
class ASTLocation;
class ASTVarLocation;
class ASTArrayLocation;
class ASTLiteralExpression;
class ASTIntegerLiteralExpression;
class ASTCharLiteralExpression;
class ASTTrueLiteralExpression;
class ASTFalseLiteralExpression;
class ASTBinaryOpExpr;
class ASTUnaryOpExpr;
class SymbolTable;
class SymbolTableNode;

enum class assign_op_type 
{
    plus_equal,
    minus_equal,
    ass
};

enum class binary_op_type 
{
    plus_op,
    minus_op,
    multiply_op,
    divide_op,
    modulo_op,
    lt_op,
    gt_op,
    le_op,
    ge_op,
    neq_op,
    eq_op,
    and_op,
    or_op
};

enum class Datatype {
    int_type,
    void_type,
    bool_type
};

enum class UnOp {
    uminus_op,
    not_op
};

class ASTNode {
public:
    ASTNode() {
    }
    ~ASTNode() {
    }
};

class ASTProgram : public ASTNode
{
    std::string id="Program";
    std::vector<ASTFieldDecl *> * fdl;
    std::vector<ASTMethodDecl *> * mdl;
public:
    ASTProgram(std::vector<ASTFieldDecl *> * fdl, std::vector<ASTMethodDecl *> * mdl)
    {
        this->mdl = mdl;
        this->fdl = fdl;
    }
    std::string getId()
    {
        return this->id;
    }
    std::vector<ASTMethodDecl *> * getMdl() 
    {
        return this->mdl;
    }
    std::vector<ASTFieldDecl *> * getFdl() 
    {
        return this->fdl;
    }
    ~ASTProgram() 
    {

    }
};

class ASTFieldDecl : public ASTNode
{
    Datatype type;
    std::vector<ASTId *> * id_list;
public:
    ASTFieldDecl(std::vector<ASTId *> * id_list, Datatype type)
    {
        this->type = type;
        this->id_list = id_list;
    }
    std::vector<ASTId *> * getId_list() 
    {
        return this->id_list;
    }
    Datatype getType() 
    {
        return this->type;
    }
    ~ASTFieldDecl() {

    }
};

class ASTVarDecl : public ASTNode
{
    Datatype type;
    std::vector<ASTId *> * id_list;
public:
    ASTVarDecl(std::vector<ASTId *> * id_list, Datatype type) 
    {
        this->type = type;
        this->id_list = id_list;
    }
    std::vector<ASTId *> * getId_list() 
    {
        return this->id_list;
    }
    Datatype getType() 
    {
        return this->type;
    }
    ~ASTVarDecl() 
    {

    }
};

class ASTId
{
    std::string id;
    int size;
public:
    ASTId(std::string id, int size) 
    {
        if (size <= 0) 
        {
            std::cerr << "Invalid Size" << std::endl;
            exit(-1);
        }
        this->id = id;
        this->size = size;
    }
    ASTId(std::string id) 
    {
        this->id = id;
        this->size = 0;
    }
    std::string getId() 
    {
        return this->id;
    }
    int getSize() 
    {
        return this->size;
    }
    ~ASTId() 
    {

    }
};

class ASTMethodDecl : public ASTNode
{
    std::string id;
    Datatype returnType;
    std::vector<ASTInput *> * arguments;
    ASTBlock * block;
public:
    ASTMethodDecl(std::string id, Datatype returnType, std::vector<ASTInput *> * arguments, ASTBlock * block) 
    {
        this->id = id;
        this->returnType = returnType;
        this->arguments = arguments;
        this->block = block;
    }
    std::string getId() 
    {
        return this->id;
    }
    Datatype getReturnType() 
    {
        return this->returnType;
    }
    std::vector<ASTInput *> * getArguments() 
    {
        return this->arguments;
    }
    ASTBlock * getBlock() 
    {
        return this->block;
    }
    ~ASTMethodDecl() 
    {

    }
};

class ASTInput : public ASTNode
{
    std::string id;
    Datatype type;
public:
    ASTInput(std::string id, Datatype type) 
    {
        this->id = id;
        this->type = type;
    }
    ~ASTInput() 
    {

    }
    std::string getId() 
    {
        return this->id;
    }
    Datatype getType() 
    {
        return this->type;
    }
};

class ASTStatement : public ASTNode 
{
public:
    ASTStatement() 
    {

    }
    virtual ~ASTStatement() 
    {

    }
};


class ASTExpression : public ASTNode
{
public:
    ASTExpression() 
    {

    }
    virtual ~ASTExpression() 
    {

    }
};

class ASTBlock : public ASTStatement
{
    std::vector<ASTVarDecl *> * id_list;
    std::vector<ASTStatement *> * stmtlist;
public:
    ASTBlock(std::vector<ASTStatement *> * stmtlist, std::vector<ASTVarDecl *> * id_list) 
    {
        this->stmtlist = stmtlist;
        this->id_list = id_list;
    }
    std::vector<ASTVarDecl *> * getId_list() 
    {
        return this->id_list;
    }
    std::vector<ASTStatement *> * get_statements() 
    {
        return this->stmtlist;
    }
    ~ASTBlock() 
    {

    }
};

class ASTAssignmentStatement : public ASTStatement
{
    assign_op_type op;
    ASTLocation * location;
    ASTExpression * expr;
public:
    ASTAssignmentStatement(assign_op_type op, ASTLocation * location, ASTExpression * expr) 
    {
        this->op = op;
        this->location = location;
        this->expr = expr;
    }
    assign_op_type getOp() 
    {
        return this->op;
    }
    ASTLocation * getLocation() 
    {
        return this->location;
    }
    ASTExpression * getExpr() 
    {
        return this->expr;
    }
    ~ASTAssignmentStatement() 
    {

    }
};

class ASTMethodCall : public ASTStatement, public ASTExpression 
{
public:
    ASTMethodCall() 
    {

    }
    virtual ~ASTMethodCall() 
    {

    }
};

class ASTMethod : public ASTMethodCall 
{
    std::string id;
    std::vector<ASTExpression *> * arguments;
public:
    ASTMethod(std::string id, std::vector<ASTExpression *> * arguments) 
    {
        this->id = id;
        this->arguments = arguments;
    }
    std::string getId() 
    {
        return this->id;
    }
    std::vector<ASTExpression *> * getArguments() 
    {
        return this->arguments;
    }
    ~ASTMethod() 
    {

    }
};

class ASTCallout : public ASTMethodCall 
{
    std::string method_name;
    std::vector<ASTCalloutArg *> * arguments;
public:
    ASTCallout(std::string method_name, std::vector<ASTCalloutArg *> * arguments) 
    {
        this->method_name = method_name;
        this->arguments = arguments;
    }
    std::string getMethod_name() 
    {
        return this->method_name;
    }
    std::vector<ASTCalloutArg *> * getArguments() 
    {
        return this->arguments;
    }
    ~ASTCallout() 
    {

    }
};

class ASTCalloutArg : public ASTExpression
{
public:
    ASTCalloutArg() 
    {

    }
    virtual ~ASTCalloutArg() 
    {

    }
};

class ASTStringCalloutArg : public ASTCalloutArg 
{
    std::string argument;
public:
    ASTStringCalloutArg(std::string argument) 
    {
        this->argument = argument;
    }
    std::string getArgument() 
    {
        return this->argument;
    }
    ~ASTStringCalloutArg() 
    {

    }
};

class ASTExpressionCalloutArg : public ASTCalloutArg 
{
    ASTExpression * argument;
public:
    ASTExpressionCalloutArg(ASTExpression * argument) 
    {
        this->argument = argument;
    }
    ASTExpression * getArgument() 
    {
        return this->argument;
    }
    ~ASTExpressionCalloutArg() 
    {

    }
};

class ASTIfStatement : public ASTStatement 
{
    ASTExpression * condition;
    ASTBlock * if_block;
    ASTBlock * else_block;
public:
    ASTIfStatement(ASTExpression * condition, ASTBlock * if_block, ASTBlock * else_block) 
    {
        this->condition = condition;
        this->if_block = if_block;
        this->else_block = else_block;
    }
    ASTExpression * getCondition() 
    {
        return this->condition;
    }
    ASTBlock * getIf_block() 
    {
        return this->if_block;
    }
    ASTBlock * getElse_block() 
    {
        return this->else_block;
    }
    ~ASTIfStatement() 
    {

    }
};

class ASTForStatement : public ASTStatement 
{
    std::string id;
    ASTExpression * init_condition;
    ASTExpression * end_condition;
    ASTBlock * block;
public:
    ASTForStatement(ASTExpression * init_condition, ASTExpression * end_condition, ASTBlock * block, std::string id) 
    {
        this->init_condition = init_condition;
        this->end_condition = end_condition;
        this->block = block;
        this->id = id;
    }
    std::string getId() 
    {
        return this->id;
    }
    ASTExpression * getInit_condition() 
    {
        return this->init_condition;
    }
    ASTExpression * getEnd_condition() 
    {
        return this->end_condition;
    }
    ASTBlock * getBlock() 
    {
        return this->block;
    }
    ~ASTForStatement() 
    {

    }
};

class ASTReturnStatement : public ASTStatement
{
    ASTExpression * expr;
public:
    ASTReturnStatement(ASTExpression * expr) 
    {
        this->expr = expr;
    }
    ASTExpression * getExpr() 
    {
        return this->expr;
    }
    ~ASTReturnStatement() 
    {

    }
};

class ASTContinueStatement : public ASTStatement
{
public:
    ASTContinueStatement() 
    {

    }
    ~ASTContinueStatement() 
    {

    }
};

class ASTBreakStatement : public ASTStatement
{
public:
    ASTBreakStatement() 
    {

    }
    ~ASTBreakStatement() 
    {

    }
};

class ASTLocation : public ASTExpression
{
public:
    ASTLocation() 
    {

    }
    virtual ~ASTLocation() 
    {

    }
};

class ASTVarLocation : public ASTLocation 
{
    std::string id;
public:
    ASTVarLocation(std::string id) 
    {
        this->id = id;
    }
    std::string getId() 
    {
        return this->id;
    }
    ~ASTVarLocation() 
    {

    }
};

class ASTArrayLocation : public ASTLocation
{
    std::string id;
    ASTExpression * index;
public:
    ASTArrayLocation(std::string id, ASTExpression * index) 
    {
        this->id = id;
        this->index = index;
    }
    std::string getId() 
    {
        return this->id;
    }
    ASTExpression * getIndex() 
    {
        return this->index;
    }
    ~ASTArrayLocation() 
    {

    }
};

class ASTLiteralExpression : public ASTExpression
{
public:
    ASTLiteralExpression() 
    {

    }
    virtual ~ASTLiteralExpression() 
    {

    }
};

class ASTIntegerLiteralExpression : public ASTLiteralExpression
{
    int value;
public:
    ASTIntegerLiteralExpression(int value) 
    {
        this->value = value;
    }
    int getValue() 
    {
        return this->value;
    }
    ~ASTIntegerLiteralExpression() 
    {

    }
};

class ASTCharLiteralExpression : public ASTLiteralExpression
{
    char value;
public:
    ASTCharLiteralExpression(char value) 
    {
        this->value = value;
    }
    char getValue() 
    {
        return this->value;
    }
    ~ASTCharLiteralExpression() 
    {

    }
};

class ASTTrueLiteralExpression : public ASTLiteralExpression
{
public:
    ASTTrueLiteralExpression() 
    {

    }
    bool getValue() 
    {
        return true;
    }
    ~ASTTrueLiteralExpression() 
    {

    }
};

class ASTFalseLiteralExpression : public ASTLiteralExpression
{
public:
    ASTFalseLiteralExpression() 
    {

    }
    bool getValue() 
    {
        return false;
    }
    ~ASTFalseLiteralExpression() 
    {

    }
};

class ASTBinaryOpExpr : public ASTExpression
{
    ASTExpression * left;
    ASTExpression * right;
    binary_op_type op;
public:
    ASTBinaryOpExpr(ASTExpression * left, ASTExpression * right, binary_op_type op) 
    {
        this->left = left;
        this->right = right;
        this->op = op;
    }
    ASTExpression * getLeft() 
    {
        return this->left;
    }
    ASTExpression * getRight() 
    {
        return this->right;
    }
    binary_op_type getOp() 
    {
        return this->op;
    }
    ~ASTBinaryOpExpr() 
    {

    }
};

class ASTUnaryOpExpr : public ASTExpression
{
    ASTExpression * expr;
    UnOp op;
public:
    ASTUnaryOpExpr(ASTExpression * expr, UnOp op) 
    {
        this->expr = expr;
        this->op = op;
    }
    ASTExpression * getExpr() 
    {
        return this->expr;
    }
    UnOp getOp () 
    {
        return this->op;
    }
    ~ASTUnaryOpExpr() 
    {

    }
};

class SymbolTableNode
{
public:
    llvm::BasicBlock * block;
    std::map<std::string, llvm::Value *> locals;

    SymbolTableNode(llvm::BasicBlock * block) 
    {
        this->block = block;
    }

    ~SymbolTableNode() 
    {

    }

};

class SymbolTable
{
private:
    std::list<SymbolTableNode> table;
    std::stack<std::pair<llvm::BasicBlock *, llvm::BasicBlock *>> break_continue_stack;

public:
    SymbolTable() 
    {

    }

    ~SymbolTable() {

    }

    std::map<std::string, llvm::Value *> get_locals()
    {
        return this->table.front().locals;
    }

    void set_locals(std::map<std::string, llvm::Value *> variables)
    {
        this->table.front().locals.insert(variables.begin(), variables.end());
    }

    bool locals_find(std::string name)
    {
        auto it = this->get_locals();
        return it.find(name) != it.end();
    }

    void locals_decl(std::string name, llvm::Value * value)
    {
        if (!this->locals_find(name))
        {
            this->table.front().locals.insert(std::pair<std::string, llvm::Value *>(name, value));
        }
        else
        {
            std::cerr<<"Variable "<<name<<" already declared";
            exit(0);
        }
    }

    bool global_find(std::string name)
    {
        return this->get_local_vars(name) != NULL;
    }

    llvm::Value * get_local_vars(std::string name)
    {
        for (auto it = this->table.begin(); it != this->table.end(); it++)
        {
            auto found_or_end = it->locals.find(name);
            if (found_or_end != it->locals.end())
            {
                return found_or_end->second;
            }
        }
        return NULL;
    }

    void pushBlock(llvm::BasicBlock * block)
    {
        this->table.push_front(SymbolTableNode(block));
    }

    void popBlock()
    {
        this->table.pop_front();
    }

    llvm::BasicBlock * topBlock()
    {
        for (auto it = this->table.begin(); it != this->table.end(); it++)
        {
            if (it->block)
            {
                return it->block;
            }
        }
        return this->table.front().block;
    }

    llvm::BasicBlock * bottomBlock()
    {
        return this->table.back().block;
    }

    void pushBCS(llvm::BasicBlock * breakSt, llvm::BasicBlock * returnSt)
    {
        this->break_continue_stack.push(std::make_pair(breakSt, returnSt));
    }

    void popBCS()
    {
        this->break_continue_stack.pop();
    }

    llvm::BasicBlock * getBS()
    {
        if (!this->break_continue_stack.empty())
        {
            return this->break_continue_stack.top().first;
        }
        return NULL;
    }

    llvm::BasicBlock * getCS()
    {
        if (!this->break_continue_stack.empty())
        {
            return this->break_continue_stack.top().second;
        }
        return NULL;
    }

};

#endif