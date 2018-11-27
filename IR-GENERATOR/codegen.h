#ifndef incl_codegen
#define incl_codegen

#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Pass.h>
#include <llvm/Support/raw_ostream.h>

#include <cstdlib>
#include <iostream>

#ifndef incl_ast
#include "ast.h"
#endif

class Visitor
{
public:
    virtual void * visit(ASTArrayLocation *) = 0;
    virtual void * visit(ASTAssignmentStatement *) = 0;
    virtual void * visit(ASTBinaryOpExpr *) = 0;
    virtual void * visit(ASTBlock *) = 0;
    virtual void * visit(ASTBreakStatement *) = 0;
    virtual void * visit(ASTCalloutArg *) = 0;
    virtual void * visit(ASTCallout *) = 0;
    virtual void * visit(ASTCharLiteralExpression *) = 0;
    virtual void * visit(ASTContinueStatement *) = 0;
    virtual void * visit(ASTExpression *) = 0;
    virtual void * visit(ASTExpressionCalloutArg *) = 0;
    virtual void * visit(ASTFalseLiteralExpression *) = 0;
    virtual void * visit(ASTFieldDecl *) = 0;
    virtual void * visit(ASTForStatement *) = 0;
    virtual void * visit(ASTId *) = 0;
    virtual void * visit(ASTIfStatement *) = 0;
    virtual void * visit(ASTIntegerLiteralExpression *) = 0;
    virtual void * visit(ASTLiteralExpression *) = 0;
    virtual void * visit(ASTLocation *) = 0;
    virtual void * visit(ASTMethodCall *) = 0;
    virtual void * visit(ASTMethodDecl *) = 0;
    virtual void * visit(ASTMethod *) = 0;
    virtual void * visit(ASTProgram *) = 0;
    virtual void * visit(ASTReturnStatement *) = 0;
    virtual void * visit(ASTStatement *) = 0;
    virtual void * visit(ASTStringCalloutArg *) = 0;
    virtual void * visit(ASTTrueLiteralExpression *) = 0;
    virtual void * visit(ASTInput *) = 0;
    virtual void * visit(ASTUnaryOpExpr *) = 0;
    virtual void * visit(ASTVarDecl *) = 0;
    virtual void * visit(ASTVarLocation *) = 0;
};


class codegenVisitor : public Visitor
{
private:
    llvm::Module * module;
    ASTProgram * start;
    llvm::Function * mainFunction;
    SymbolTable table;
public:
    codegenVisitor(ASTProgram * start) {
        module = new llvm::Module(start->getId(), llvm::getGlobalContext());
        this->start = start;
        llvm::FunctionType *ftype = llvm::FunctionType::get(llvm::Type::getVoidTy(llvm::getGlobalContext()), false);
        mainFunction = llvm::Function::Create(ftype, llvm::GlobalValue::ExternalLinkage, "main", module);
    }

    ~codegenVisitor() {
    }

    void codegen()
    {
        llvm::BasicBlock *block = llvm::BasicBlock::Create(llvm::getGlobalContext(), "entry", mainFunction, 0);
        table.pushBlock(block);
        this->visit(start);
        block = table.topBlock();
        table.popBlock();
        llvm::ReturnInst::Create(llvm::getGlobalContext(), block);
        llvm::verifyModule(*module);
        llvm::legacy::PassManager PM;
        PM.add(llvm::createPrintModulePass(llvm::outs()));
        PM.run(*module);
    }

    void * visit(ASTProgram * node)
    {
        if (node->getFdl())
        {
            for(auto it = (node->getFdl())->begin() ; it != (node->getFdl())->end(); it++)
            {
                this->visit(*it);
            }               
        }
        llvm::Function * iterator = NULL;
        llvm::Function * userMain = NULL;
        if (node->getMdl())
        {
            for(auto it = (node->getMdl())->begin() ; it != (node->getMdl())->end(); it++)
            {
                if(module->getFunction((*it)->getId()) && (*it)->getId() != "main")
                {
                    fprintf(stderr, "error: Many mains\n");
                    exit(-1);
                }
                if ((*it)->getId() == "main" && userMain)
                {
                    fprintf(stderr, "error: Many mains\n");
                    exit(-1);
                }
                iterator = static_cast<llvm::Function *>(this->visit(*it));
                if ((*it)->getId() == "main" && !userMain)
                {
                    userMain = iterator;
                }
            }               
        }
        if (!userMain)
        {
            fprintf(stderr, "error: No main\n");
            exit(-1);
        }
        else
        {
            llvm::CallInst::Create(userMain, "", table.topBlock());
        }
        return NULL;
    }

    void * visit(ASTFieldDecl * node)
    {
        if (node->getId_list())
        {
            for(auto it = (node->getId_list())->begin() ; it != (node->getId_list())->end(); it++)
            {
                this->visit(*it);            
            }   
        }
        return NULL;
    }

    void * visit(ASTVarDecl * node)
    {
        if (node->getId_list())
        {
            for(auto it = (node->getId_list())->begin() ; it != (node->getId_list())->end(); it++)
            {
                this->visit(*it);
            }
        }
        return NULL;
    }

    void * visit(ASTId * node)
    {
        if (node->getSize() == 0)
        {
            if(table.topBlock() == table.bottomBlock())
            {
                // This means it is a global variable
                llvm::GlobalVariable * globalInteger = new llvm::GlobalVariable(*module, llvm::Type::getInt64Ty(llvm::getGlobalContext()), false, llvm::GlobalValue::CommonLinkage, NULL, node->getId());
                globalInteger->setInitializer(llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), 0, true));
                table.locals_decl(node->getId(), globalInteger);
                return globalInteger;
            }
            else
            {
                // If not there make one
                llvm::AllocaInst * allocaInst = new llvm::AllocaInst(llvm::Type::getInt64Ty(llvm::getGlobalContext()), node->getId(), table.topBlock());
                new llvm::StoreInst(llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), 0, true), allocaInst, false, table.topBlock());
                table.locals_decl(node->getId(), allocaInst);
                return allocaInst;
            }
        } 
        else
        {
            // Initialization of a variable
            llvm::GlobalVariable* variable = new llvm::GlobalVariable(*module, llvm::ArrayType::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), node->getSize()), false, llvm::GlobalValue::CommonLinkage, NULL, node->getId());
            variable->setInitializer(llvm::ConstantAggregateZero::get(llvm::ArrayType::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), node->getSize())));
            table.locals_decl(node->getId(), variable);
            return variable;
        }
    }

    llvm::Type * parseType(Datatype type)
    {
        switch(type)
        {
            case Datatype::int_type: 
            return llvm::Type::getInt64Ty(llvm::getGlobalContext());
            case Datatype::bool_type: 
            return llvm::Type::getInt64Ty(llvm::getGlobalContext());                   
            case Datatype::void_type: 
            return llvm::Type::getVoidTy(llvm::getGlobalContext());
        }
        fprintf(stderr, "error: Invalid datatype\n");
        exit(-1);
    }

    void * visit(ASTMethodDecl * node) 
    {
        std::vector<llvm::Type*> argTypes; // array of the type of arguments
        if (node->getArguments()) 
        {
            for (auto it = (node->getArguments())->begin(); it != (node->getArguments())->end(); it++) 
            {
                argTypes.push_back(parseType((*it)->getType()));
            }
        }

        llvm::FunctionType *ftype = llvm::FunctionType::get(parseType(node->getReturnType()), llvm::makeArrayRef(argTypes), false);
        llvm::Function *function = llvm::Function::Create(ftype, llvm::GlobalValue::InternalLinkage, node->getId(), module);
        llvm::BasicBlock *block = llvm::BasicBlock::Create(llvm::getGlobalContext(), "entry", function, 0); 
        table.pushBlock(block);
        // create variables for each of the arguments in the context
        if (node->getArguments()) 
        {
            llvm::Function::arg_iterator it2 = function->arg_begin();
            for (auto it = (node->getArguments())->begin(); it != (node->getArguments())->end(); it++, it2++) 
            {
                llvm::Value * arg = &(*it2);
                arg->setName((*it)->getId());
                llvm::AllocaInst * allocaInst = NULL;
                allocaInst = new llvm::AllocaInst(llvm::Type::getInt64Ty(llvm::getGlobalContext()), (*it)->getId(), table.topBlock());
                new llvm::StoreInst(arg, allocaInst, false, table.topBlock());
                table.locals_decl((*it)->getId(), allocaInst);
            }
        }
        this->visit(node->getBlock());
        if(!table.topBlock()->getTerminator()) 
        {
            if(node->getReturnType() == Datatype::void_type)
            {
                llvm::ReturnInst::Create(llvm::getGlobalContext(), table.topBlock());
            }
            else
            { 
                llvm::ReturnInst::Create(llvm::getGlobalContext(), llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), 0, true), table.topBlock());
            }
        }
        table.popBlock();
        return function;
    }

    void * visit(ASTInput * node)
    {
        // nothing needs to be done. Already handled in method_decl
        return NULL;
    }

    void * visit(ASTBlock * node)
    {
        // Blocks
        if(node->getId_list())
        {
            for(auto it = (node->getId_list())->begin() ; it != (node->getId_list())->end(); it++) 
            {
                this->visit(*it);
            }
        }
        if(node->get_statements())
        {
            for(auto it=(node->get_statements())->begin();it!=(node->get_statements())->end();it++) 
            {
                this->visit(*it);
                ASTReturnStatement * returnStatement = dynamic_cast<ASTReturnStatement *>(*it);
                ASTBreakStatement * breakStatement = dynamic_cast<ASTBreakStatement *>(*it);
                ASTContinueStatement * continueStatement = dynamic_cast<ASTContinueStatement *>(*it);
                if (returnStatement or breakStatement or continueStatement)
                {
                    break;
                }
            }
        }
        return NULL;
    }

    void * visit(ASTStatement * node) 
    { 
        llvm::BasicBlock * block = table.topBlock();
        if (block->getTerminator()) 
        {
            // terminate any and all instructions which end the current block when there are still instructions to do
            llvm::Instruction * terminator = block->getTerminator();
            terminator->eraseFromParent();
        }
        ASTAssignmentStatement * assignmentStatement = dynamic_cast<ASTAssignmentStatement *>(node);
        ASTBlock * blockStatement = dynamic_cast<ASTBlock *>(node);
        ASTMethodCall * methodCall = dynamic_cast<ASTMethodCall *>(node);
        ASTIfStatement * ifStatement = dynamic_cast<ASTIfStatement *>(node);
        ASTForStatement * forStatement = dynamic_cast<ASTForStatement *>(node);
        ASTReturnStatement * returnStatement = dynamic_cast<ASTReturnStatement *>(node);
        ASTContinueStatement * continueStatement = dynamic_cast<ASTContinueStatement *>(node);
        ASTBreakStatement * breakStatement = dynamic_cast<ASTBreakStatement *>(node);
        // Call functions according to CFG
        if(assignmentStatement) 
        {
            return this->visit(assignmentStatement);
        }
        else if(blockStatement) 
        {
            table.pushBlock(NULL);
            this->visit(blockStatement);
            table.popBlock();
            return NULL;
        }
        else if(methodCall) 
        {
            return this->visit(methodCall);
        }
        else if(ifStatement) 
        {
            return this->visit(ifStatement);
        }
        else if(forStatement) 
        {
            return this->visit(forStatement);
        }
        else if(returnStatement) 
        {
            return this->visit(returnStatement);
        }
        else if(continueStatement) 
        {
            return this->visit(continueStatement);
        }
        else if(breakStatement) 
        {
            return this->visit(breakStatement);
        }
    }

    void * visit(ASTAssignmentStatement * node)
    {
        llvm::Value * location = NULL;
        llvm::Value * existingValue = NULL;
        ASTVarLocation * varLocation = dynamic_cast<ASTVarLocation *>(node->getLocation());
        ASTArrayLocation * arrayLocation = dynamic_cast<ASTArrayLocation *>(node->getLocation());
        if (arrayLocation) 
        {
            //array should be declared global
            if (!table.global_find(arrayLocation->getId())) 
            {
                fprintf(stderr, "error: No such variable\n");
                exit(-1);
            }
            std::vector <llvm::Value *> index;
            index.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), 0, true));
            index.push_back(static_cast<llvm::Value *>(this->visit(arrayLocation->getIndex())));
            llvm::Value * val = table.get_local_vars(arrayLocation->getId());
            location = llvm::GetElementPtrInst::CreateInBounds(val, index, "tmp", table.topBlock());
        }
        if (varLocation) 
        {
            if (!table.global_find(varLocation->getId())) 
            {
                fprintf(stderr, "error: No such variable\n");
                exit(-1);
            }
            location = table.get_local_vars(varLocation->getId());
        }
        llvm::Value * expr = static_cast<llvm::Value *>(this->visit(node->getExpr()));
        existingValue = new llvm::LoadInst(location, "load", table.topBlock());
        switch(node->getOp()) 
        {
            case assign_op_type::plus_equal:
                expr = llvm::BinaryOperator::Create(llvm::Instruction::Add, existingValue, expr, "tmp", table.topBlock());
                break;
            case assign_op_type::minus_equal: 
                expr = llvm::BinaryOperator::Create(llvm::Instruction::Sub, existingValue, expr, "tmp", table.topBlock());
                break;
            case assign_op_type::ass: 
                break;
        }
        if (!expr->getType()->isIntegerTy(64)) 
        {
            fprintf(stderr, "error: Type of LHS RHS not same\n");
            exit(-1);
        }
        if (!location->getType()->isPointerTy()) 
        {
            fprintf(stderr, "error: Type of LHS RHS not same\n");
            exit(-1);
        }
        return new llvm::StoreInst(expr, location, false, table.topBlock());
    }

    void * visit(ASTMethodCall * node) 
    {
        ASTCallout * calloutMethod = dynamic_cast<ASTCallout *>(node);
        ASTMethod * normalMethod = dynamic_cast<ASTMethod *>(node);
        if (normalMethod) 
        {
            return this->visit(normalMethod);
        }
        else if (calloutMethod) 
        {
            return this->visit(calloutMethod);
        }
    }

    void * visit(ASTMethod * node) 
    {
        std::vector<llvm::Value *> args;
        llvm::Function * function = module->getFunction(node->getId());
        if (!function) 
        {
            fprintf(stderr, "error: no such function\n");
            exit(-1);
        }
        if (!function->isVarArg() && (node->getArguments()) && (function->getArgumentList().size() != node->getArguments()->size())) 
        {
            fprintf(stderr, "error: no of arguments:%d expected:%d\n",int(node->getArguments()->size()),int(function->getArgumentList().size()));
            exit(-1);
        }
        if (node->getArguments()) 
        {
            for (auto it = (node->getArguments())->begin(); it != (node->getArguments())->end(); it++) 
            {
                args.push_back(static_cast<llvm::Value *>(this->visit(*it)));
            }
        }
        if (function->getReturnType()->isVoidTy()) 
        {
            return llvm::CallInst::Create(function, llvm::makeArrayRef(args), "", table.topBlock());    
        }
        return llvm::CallInst::Create(function, llvm::makeArrayRef(args), node->getId(), table.topBlock());
    }

    void * visit(ASTCallout * node) 
    {
        llvm::Function * function = module->getFunction(node->getMethod_name());
        if (!function) 
        {
            llvm::FunctionType *ftype = llvm::FunctionType::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), true);
            function = llvm::Function::Create(ftype, llvm::GlobalValue::ExternalLinkage, node->getMethod_name(), module);
        }
        std::vector<llvm::Value *> args;
        if (node->getArguments()) 
        {
            for (auto it = (node->getArguments())->begin(); it != (node->getArguments())->end(); it++) 
            {
                args.push_back(static_cast<llvm::Value *>(this->visit(*it)));
            }
        }
        llvm::CallInst *call = llvm::CallInst::Create(function, llvm::makeArrayRef(args), node->getMethod_name(), table.topBlock());
        return call;
    }

    void * visit(ASTIfStatement * node) 
    {
        llvm::BasicBlock * entryBlock = table.topBlock();
        llvm::Value * condition = static_cast<llvm::Value *>(this->visit(node->getCondition()));
        // initializing conditio to be i!=0 so that if(x) kind of instructions work
        llvm::ICmpInst * comparison = new llvm::ICmpInst(*entryBlock, llvm::ICmpInst::ICMP_NE, condition, llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), 0, true), "tmp");
        llvm::BasicBlock * ifBlock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "ifBlock", entryBlock->getParent());
        llvm::BasicBlock * mergeBlock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "mergeBlock", entryBlock->getParent());

        llvm::BasicBlock * returnedBlock = NULL;

        table.pushBlock(ifBlock);
        this->visit(node->getIf_block());
        returnedBlock = table.topBlock();
        table.popBlock();
        if(!returnedBlock->getTerminator()) 
        {
            llvm::BranchInst::Create(mergeBlock, returnedBlock);
        }
        if(node->getElse_block()) 
        {
            llvm::BasicBlock * elseBlock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "elseBlock", entryBlock->getParent());
            table.pushBlock(elseBlock);
            this->visit(node->getElse_block());
            returnedBlock = table.topBlock();
            table.popBlock();
            if (!returnedBlock->getTerminator()) 
            {
                llvm::BranchInst::Create(mergeBlock, returnedBlock);
            }
            llvm::BranchInst::Create(ifBlock, elseBlock, comparison, entryBlock);
        }
        else 
        {
            llvm::BranchInst::Create(ifBlock, mergeBlock, comparison, entryBlock);
        }
        auto locals = table.get_locals();
        table.popBlock();
        table.pushBlock(mergeBlock);
        table.set_locals(locals);
        return NULL;
    }

    void * visit(ASTForStatement * node) 
    {
        if (!table.global_find(node->getId())) 
        {
            fprintf(stderr, "error: variable not defined\n");
            exit(-1);
        }
        llvm::BasicBlock * entryBlock = table.topBlock();
        llvm::BasicBlock * headerBlock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "loop_header", entryBlock->getParent(), 0);
        llvm::BasicBlock * bodyBlock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "loop_body", entryBlock->getParent(), 0);
        llvm::BasicBlock * afterLoopBlock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "after_loop", entryBlock->getParent(), 0);

        table.pushBCS(afterLoopBlock, headerBlock);

        new llvm::StoreInst(static_cast<llvm::Value *>(this->visit(node->getInit_condition())), table.get_local_vars(node->getId()), false, entryBlock);
        llvm::Value * val = new llvm::LoadInst(table.get_local_vars(node->getId()), "load", headerBlock);
        llvm::ICmpInst * comparison = new llvm::ICmpInst(*headerBlock, llvm::ICmpInst::ICMP_SLT, val, static_cast<llvm::Value *>(this->visit(node->getEnd_condition())), "tmp");
        llvm::BranchInst::Create(bodyBlock, afterLoopBlock, comparison, headerBlock);
        llvm::BranchInst::Create(headerBlock, entryBlock);

        table.pushBlock(bodyBlock);
        this->visit(node->getBlock());
        bodyBlock = table.topBlock();
        table.popBlock();
        if (!bodyBlock->getTerminator()) 
        {
            llvm::BranchInst::Create(headerBlock, bodyBlock);
        }

        auto locals = table.get_locals();
        table.popBlock();
        table.pushBlock(afterLoopBlock);
        table.set_locals(locals);

        table.popBCS();
        return NULL;
    }

    void * visit(ASTReturnStatement * node) 
    {
        llvm::Function * function = table.topBlock()->getParent();
        llvm::Type * type = function->getReturnType();
        if (type->isVoidTy()) 
        {
            if(node->getExpr()) 
            {
                fprintf(stderr, "error: wrong return type\n");
                exit(-1);
            } 
            else 
            {
                return llvm::ReturnInst::Create(llvm::getGlobalContext(),table.topBlock());
            }
        } 
        else 
        {
            if (node->getExpr()) 
            {
                llvm::Value * expression = static_cast<llvm::Value *>(this->visit(node->getExpr()));
                return llvm::ReturnInst::Create(llvm::getGlobalContext(), expression, table.topBlock());
            } 
            else 
            {
                fprintf(stderr, "error: wrong return type\n");
                exit(-1);
            }
        }
    }

    void * visit(ASTContinueStatement * node) 
    {
        llvm::BasicBlock * block = table.getCS();
        if (!block) 
        {
            fprintf(stderr, "error: continue can't be used\n");
            exit(-1);
        }
        llvm::BasicBlock * curBlock = table.topBlock();
        return llvm::BranchInst::Create(block, curBlock);
    }

    void * visit(ASTBreakStatement * node) 
    {
        llvm::BasicBlock * block = table.getBS();
        if (!block) 
        {
            fprintf(stderr, "error: break can't be used\n");
            exit(-1);
        }
        llvm::BasicBlock * curBlock = table.topBlock();
        auto locals = table.get_locals();
        table.popBlock();
        table.pushBlock(block);
        table.set_locals(locals);
        return llvm::BranchInst::Create(block, curBlock);
    }

    void * visit(ASTExpression * node) 
    {
        // Call functions according to CFG
        ASTBinaryOpExpr * binaryOperationExpression = dynamic_cast<ASTBinaryOpExpr *>(node);
        ASTLiteralExpression * literalExpression = dynamic_cast<ASTLiteralExpression *>(node);
        ASTMethodCall * methodCall = dynamic_cast<ASTMethodCall *>(node);
        ASTUnaryOpExpr * unaryOperationExpression = dynamic_cast<ASTUnaryOpExpr *>(node);
        ASTLocation * location = dynamic_cast<ASTLocation *>(node);
        ASTCalloutArg * calloutArg = dynamic_cast<ASTCalloutArg *>(node);
        if(binaryOperationExpression) 
        {
            return this->visit(binaryOperationExpression);
        }
        else if(literalExpression) 
        {
            return this->visit(literalExpression);
        }
        else if(methodCall)
        {
            return this->visit(methodCall);
        }
        else if(unaryOperationExpression)
        {
            return this->visit(unaryOperationExpression);
        }
        else if(location)
        {
            return this->visit(location);
        }
        else if(calloutArg)
        {
            return this->visit(calloutArg);
        }
    }



    void * visit(ASTBinaryOpExpr * node) 
    {
        switch(node->getOp()) {
            case binary_op_type::plus_op:
                return llvm::BinaryOperator::Create(llvm::Instruction::Add, static_cast<llvm::Value*>(this->visit(node->getLeft())), static_cast<llvm::Value*>(this->visit(node->getRight())), "tmp", table.topBlock());
            case binary_op_type::minus_op: 
                return llvm::BinaryOperator::Create(llvm::Instruction::Sub, static_cast<llvm::Value*>(this->visit(node->getLeft())), static_cast<llvm::Value*>(this->visit(node->getRight())), "tmp", table.topBlock());
            case binary_op_type::multiply_op: 
                return llvm::BinaryOperator::Create(llvm::Instruction::Mul, static_cast<llvm::Value*>(this->visit(node->getLeft())), static_cast<llvm::Value*>(this->visit(node->getRight())), "tmp", table.topBlock());
            case binary_op_type::divide_op: 
                return llvm::BinaryOperator::Create(llvm::Instruction::SDiv, static_cast<llvm::Value*>(this->visit(node->getLeft())), static_cast<llvm::Value*>(this->visit(node->getRight())), "tmp", table.topBlock());
            case binary_op_type::modulo_op: 
                return llvm::BinaryOperator::Create(llvm::Instruction::SRem, static_cast<llvm::Value*>(this->visit(node->getLeft())), static_cast<llvm::Value*>(this->visit(node->getRight())), "tmp", table.topBlock());
            case binary_op_type::lt_op: 
                return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_SLT, static_cast<llvm::Value*>(this->visit(node->getLeft())), static_cast<llvm::Value*>(this->visit(node->getRight())),"tmp", table.topBlock()), llvm::Type::getInt64Ty(llvm::getGlobalContext()), "zext", table.topBlock());
            case binary_op_type::gt_op: 
                return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_SGT, static_cast<llvm::Value*>(this->visit(node->getLeft())), static_cast<llvm::Value*>(this->visit(node->getRight())),"tmp", table.topBlock()), llvm::Type::getInt64Ty(llvm::getGlobalContext()), "zext", table.topBlock());
            case binary_op_type::le_op: 
                return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_SLE, static_cast<llvm::Value*>(this->visit(node->getLeft())), static_cast<llvm::Value*>(this->visit(node->getRight())),"tmp", table.topBlock()), llvm::Type::getInt64Ty(llvm::getGlobalContext()), "zext", table.topBlock());
            case binary_op_type::ge_op: 
                return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_SGE, static_cast<llvm::Value*>(this->visit(node->getLeft())), static_cast<llvm::Value*>(this->visit(node->getRight())),"tmp", table.topBlock()), llvm::Type::getInt64Ty(llvm::getGlobalContext()), "zext", table.topBlock());
            case binary_op_type::neq_op: 
                return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_NE, static_cast<llvm::Value*>(this->visit(node->getLeft())), static_cast<llvm::Value*>(this->visit(node->getRight())),"tmp", table.topBlock()), llvm::Type::getInt64Ty(llvm::getGlobalContext()), "zext", table.topBlock());
            case binary_op_type::eq_op: 
                return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_EQ, static_cast<llvm::Value*>(this->visit(node->getLeft())), static_cast<llvm::Value*>(this->visit(node->getRight())),"tmp", table.topBlock()), llvm::Type::getInt64Ty(llvm::getGlobalContext()), "zext", table.topBlock());
            case binary_op_type::and_op: 
                return llvm::BinaryOperator::Create(llvm::Instruction::And, static_cast<llvm::Value*>(this->visit(node->getLeft())), static_cast<llvm::Value*>(this->visit(node->getRight())), "tmp", table.topBlock());
            case binary_op_type::or_op: 
                return llvm::BinaryOperator::Create(llvm::Instruction::Or, static_cast<llvm::Value*>(this->visit(node->getLeft())), static_cast<llvm::Value*>(this->visit(node->getRight())), "tmp", table.topBlock());
        }
    }

    void * visit(ASTLiteralExpression * node) 
    {
        ASTIntegerLiteralExpression * integerLiteralExpression = dynamic_cast<ASTIntegerLiteralExpression *>(node);
        ASTCharLiteralExpression * charLiteralExpression = dynamic_cast<ASTCharLiteralExpression *>(node);
        ASTTrueLiteralExpression * trueLiteralExpression = dynamic_cast<ASTTrueLiteralExpression *>(node);
        ASTFalseLiteralExpression * falseLiteralExpression = dynamic_cast<ASTFalseLiteralExpression *>(node);
        if (integerLiteralExpression) 
        {
            return this->visit(integerLiteralExpression);
        }
        if (charLiteralExpression) 
        {
            return this->visit(charLiteralExpression);
        }
        if (trueLiteralExpression) 
        {
            return this->visit(trueLiteralExpression);
        }
        if (falseLiteralExpression) 
        {
            return this->visit(falseLiteralExpression);
        }
    }

    void * visit(ASTIntegerLiteralExpression * node) 
    {
        return llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), node->getValue(), true);
    }

    void * visit(ASTCharLiteralExpression * node) 
    {
        return llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), node->getValue(), true);
    }

    void * visit(ASTTrueLiteralExpression * node) 
    {
        return llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), node->getValue(), true);
    }

    void * visit(ASTFalseLiteralExpression * node) 
    {
        return llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), node->getValue(), true);
    }

    void * visit(ASTUnaryOpExpr * node) 
    {
        switch(node->getOp()) {
            case UnOp::uminus_op: 
                return llvm::BinaryOperator::Create(llvm::Instruction::Sub, llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), 0, true), static_cast<llvm::Value*>(this->visit(node->getExpr())), "tmp", table.topBlock());
            case UnOp::not_op: 
                return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_EQ, llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), 0, true), static_cast<llvm::Value*>(this->visit(node->getExpr())),"tmp", table.topBlock()), llvm::Type::getInt64Ty(llvm::getGlobalContext()), "zext", table.topBlock());
        }
    }

    void * visit(ASTLocation * node) 
    {
        ASTArrayLocation * arrayLocation = dynamic_cast<ASTArrayLocation *>(node);
        ASTVarLocation * varLocation = dynamic_cast<ASTVarLocation *>(node);
        if (arrayLocation)
        {
            return this->visit(arrayLocation);
        }
        if (varLocation)
        {
            return this->visit(varLocation);
        }
    }

    void * visit(ASTVarLocation * node) 
    {
        if (!table.global_find(node->getId())) 
        {
            fprintf(stderr, "error: declare var\n");
            exit(-1);
        }
        llvm::Value * val = table.get_local_vars(node->getId());
        if (val)
        {
            return new llvm::LoadInst(val, "tmp", table.topBlock());
        }
    }

    void * visit(ASTArrayLocation * node) 
    {
        if (!table.global_find(node->getId())) 
        {
            fprintf(stderr, "error: declare var\n");
            exit(-1);
        }
        std::vector <llvm::Value *> index;
        index.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), 0, true));
        index.push_back(static_cast<llvm::Value *>(this->visit(node->getIndex())));
        llvm::Value * val = table.get_local_vars(node->getId());
        llvm::Value * offset = llvm::GetElementPtrInst::CreateInBounds(val, index, "tmp", table.topBlock());
        if (val) 
        {
            llvm::LoadInst * load = new llvm::LoadInst(offset, "tmp", table.topBlock());
            return load;
        }
    }

    void * visit(ASTCalloutArg * node) 
    { 
        ASTStringCalloutArg * stringCalloutArg = dynamic_cast<ASTStringCalloutArg *>(node);
        ASTExpressionCalloutArg * expressionCalloutArg = dynamic_cast<ASTExpressionCalloutArg *>(node);
        if (stringCalloutArg) 
        {
            return this->visit(stringCalloutArg);
        }
        if (expressionCalloutArg)
        {
            return this->visit(expressionCalloutArg);
        }
    }

    void * visit(ASTStringCalloutArg * node) 
    {
        std::string argument = node->getArgument();
        llvm::GlobalVariable* variable = new llvm::GlobalVariable(*module, llvm::ArrayType::get(llvm::IntegerType::get(llvm::getGlobalContext(), 8), argument.size() + 1), true, llvm::GlobalValue::InternalLinkage, NULL, "string");
        variable->setInitializer(llvm::ConstantDataArray::getString(llvm::getGlobalContext(), argument, true));
        return variable;
    }

    void * visit(ASTExpressionCalloutArg * node) 
    {
        return this->visit(node->getArgument());
    }

};

#endif