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
		case BinaryOp:
						printPostFix(root->binarynode.left);
						printPostFix(root->binarynode.right);
						switch (root->binarynode.operator) 
						{
							case ADD: printf("+ ");
									break; 
							case SUB: printf("- ");
									break;
							case MUL: printf("* ");
									break;
							case DIV: printf("/ ");
									break;
						}
						break;
		case Binary:	printPostFix(root->binarynode.left);
						printPostFix(root->binarynode.right);
						break;
		case TernaryOp: printPostFix(root->ternarynode.first);
						printPostFix(root->ternarynode.second);
						printPostFix(root->ternarynode.third);
						printf("? ");
						break;
		case INTLITERAL: printf("%d ", root->litval);
						break;
		case Unary: 	switch (root->unarynode.type)
						{
							case PROG_TYPE: printf("Class Program ");
											break;
						}
						printPostFix(root->unarynode.child);
						break;
	}
};