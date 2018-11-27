#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

struct ASTNode *getASTNodeNONE()
{
	struct ASTNode *node; 
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = NONE;
	return node;
}

struct ASTNode *getASTNodeBinaryOp(struct ASTNode *left, 
									struct ASTNode *right, 
									BinaryOpType operator)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));

	node->nodetype = BinaryOp;
	node->binarynode.left = left;
	node->binarynode.right = right;
	node->binarynode.operator = operator;

	return node;
}

struct ASTNode *getASTNodeBinaryNode(struct ASTNode *left, 
									struct ASTNode *right, 
									BinaryNodeType type)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));

	node->nodetype = Binary;
	node->binarynodetype.left = left;
	node->binarynodetype.right = right;
	node->binarynodetype.type = type;

	return node;
}

struct ASTNode *getASTNodeTernaryNode(struct ASTNode *first,
									struct ASTNode *second,
									struct ASTNode *third,
									TernaryNodeType type)
{
	struct ASTNode *node;

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));

	node->nodetype = Ternary;
	node->ternarynodetype.first = first;
	node->ternarynodetype.second = second;
	node->ternarynodetype.third = third;
	node->ternarynodetype.type = type;	
}

struct ASTNode *getASTNodeQuaternaryNode(struct ASTNode *first,
									struct ASTNode *second,
									struct ASTNode *third,
									struct ASTNode *fourth,
									QuaternaryNodeType type)
{
	struct ASTNode *node;

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));

	node->nodetype = Quaternary;
	node->quaternarynodetype.first = first;
	node->quaternarynodetype.second = second;
	node->quaternarynodetype.third = third;
	node->quaternarynodetype.fourth = fourth;
	node->quaternarynodetype.type = type;
}

struct ASTNode *getASTNodePentnaryNode(struct ASTNode *first,
									struct ASTNode *second,
									struct ASTNode *third,
									struct ASTNode *fourth,
									struct ASTNode *fifth,
									PentnaryNodeType type)
{
	struct ASTNode *node;

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));

	node->nodetype = Pentnary;
	node->pentnarynodetype.first = first;
	node->pentnarynodetype.second = second;
	node->pentnarynodetype.third = third;
	node->pentnarynodetype.fourth = fourth;
	node->pentnarynodetype.fifth = fifth;
	node->pentnarynodetype.type = type;
}


struct ASTNode *getASTNodeTernaryOp(struct ASTNode *first, 
									struct ASTNode *second,
									struct ASTNode *third)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));

	node->nodetype = TernaryOp;
	node->ternarynode.first = first;
	node->ternarynode.second = second;
	node->ternarynode.third = third;

	return node;
}

struct ASTNode *getASTUnaryNode(struct ASTNode *child, 
									UnaryType type)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));

	node->nodetype = Unary;
	node->unarynode.child = child;
	node->unarynode.type = type;

	return node;
}


struct ASTNode *getASTNodeIntLiteral(int litval)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));

	node->nodetype = INTLITERAL;
	node->litval = litval;

	return node;
}

void printPostFix(struct ASTNode *root)
{
	switch (root->nodetype) 
	{
		case NONE: break;
		case Unary:		switch (root->unarynode.type)
						{
							case PROG_TYPE: printf("Class Program ");
											break;
							case ID:	printf("id ");
										break;
							case INT_TYPE: printf("int ");
										break;
							case BOOL_TYPE: printf("bool ");
										break;
							case BLOCK: printf("block ");
										break;
							case RET: printf("return ");
										break;
							case BREAK: printf("break ");
										break;
							case CONT: printf("continue ");
										break;
							case ASS: printf("= ");
										break;
							case PLUS_EQ: printf("+= ");
										break;
							case MINUS_EQ: printf("-= ");
										break;
							case METHOD_NAME: printf("method_name ");
										break;
							case CALLOUT: printf("callout ");
										break;
							case STR_LIT: printf("string_literal ");
										break;
							case NOT: printf("! ");
										break;
							case CALLOUT_ARG: printf("callout_arg");
										break;
							case BIN_OP: printf("binary_operation");
										break;
							case ADD: printf("+ ");
										break;
							case SUB: printf("- ");
										break;
							case MUL: printf("* ");
										break;
							case DIV: printf("/ ");
										break;
							case MOD: printf("%% ");
										break;
							case GT: printf("> ");
										break;
							case LT: printf("< ");
										break;
							case GE: printf(">= ");
										break;
							case LE: printf("<= ");
										break;
							case EQ: printf("== ");
										break;
							case NEQ: printf("!= ");
										break;
							case AND: printf("&& ");
										break;
							case OR: printf("|| ");
										break;
							case INT_LIT: printf("int_literal ");
										break;
							case BOOL_LIT: printf("bool_literal ");
										break;
							case DEC: printf("decimal ");
										break;
							case HEX: printf("hexadecimal ");
										break;
							case T:	printf("true ");
										break;
							case F: printf("false ");
										break;
						}
						printPostFix(root->unarynode.child);
						break;
		case Binary:	switch (root->binarynodetype.type)
						{
							case RETURN: printf("return ");
							break;
						}
						printPostFix(root->binarynodetype.left);
						printPostFix(root->binarynodetype.right);
						break;
		case Ternary:	switch (root->ternarynodetype.type)
						{
							case VOID_METHOD_DECL: printf("void ");
												break;
							case STMT_IF: printf("if ");
											break;
							case STMT_IF_ELSE: printf("if ");
											break;
						}
						printPostFix(root->ternarynodetype.first);
						printPostFix(root->ternarynodetype.second);
						switch (root->ternarynodetype.type)
						{
						case STMT_IF_ELSE: printf("else ");
											break;	
						}
						printPostFix(root->ternarynodetype.third);
						break;
		case Quaternary:printPostFix(root->quaternarynodetype.first);
						printPostFix(root->quaternarynodetype.second);
						printPostFix(root->quaternarynodetype.third);
						printPostFix(root->quaternarynodetype.fourth);
						break;
		case Pentnary:switch (root->pentnarynodetype.type)
						{
							case FOR: printf("for ");
									break;
						}
						printPostFix(root->pentnarynodetype.first);
						printPostFix(root->pentnarynodetype.second);
						printPostFix(root->pentnarynodetype.third);
						printPostFix(root->pentnarynodetype.fourth);
						printPostFix(root->pentnarynodetype.fifth);
						break;
		case INTLITERAL: printf("%d ", root->litval);
						break;
	}
};