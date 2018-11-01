typedef enum  astnodetype {NONE, BinaryOp, TernaryOp, INTLITERAL, Unary, Binary, Ternary, Quaternary} ASTNodeType;
typedef enum  binaryoptype {ADD, SUB, MUL, DIV} BinaryOpType; 
typedef enum  binarynodetype {FIELDS, FIELD_DECLS,FIELD_DECL, METHOD_DECLS, INPUTS} BinaryNodeType;
typedef enum  ternarynodetype {LIST_ID,VOID_METHOD_DECL} TernaryNodeType;
typedef enum  quaternarynodetype {METHOD_DECL} QuaternaryNodeType;
typedef enum  unarytype {PROG_TYPE, TYPE} UnaryType;

extern struct ASTNode *getASTNodeNONE();

extern struct ASTNode *getASTNodeBinaryOp(struct ASTNode *left,
									struct ASTNode *right,
									BinaryOpType operator);

extern struct ASTNode *getASTNodeBinaryNode(struct ASTNode *left,
									struct ASTNode *right,
									BinaryNodeType type);

extern struct ASTNode *getASTNodeTernaryNode(struct ASTNode *first,
									struct ASTNode *second,
									struct ASTNode *third,
									TernaryNodeType type);

extern struct ASTNode *getASTNodeQuaternaryNode(struct ASTNode *first,
									struct ASTNode *second,
									struct ASTNode *third,
									struct ASTNode *fourth,
									QuaternaryNodeType type);

extern struct ASTNode *getASTNodeTernaryOp(struct ASTNode *first, 
									struct ASTNode *second,
									struct ASTNode *third);

extern struct ASTNode *getASTNodeIntLiteral(int litval);

extern struct ASTNode *getASTUnaryNode(struct ASTNode *child, UnaryType type);

extern void printPostFix(struct ASTNode *root);


struct ASTNode {
	ASTNodeType nodetype;

	union {
	
		struct ASTExprBinOp {
			BinaryOpType operator; 
			struct ASTNode *left;
			struct ASTNode *right; 
		} binarynode;	

		struct ASTBinaryNode {
			BinaryNodeType type; 
			struct ASTNode *left;
			struct ASTNode *right; 
		} binarynodetype;

		struct ASTTernaryNode {
			TernaryNodeType type;
			struct ASTNode *first;
			struct ASTNode *second;
			struct ASTNode *third; 
		} ternarynodetype;

		struct ASTQuaternaryNode {
			QuaternaryNodeType type;
			struct ASTNode *first;
			struct ASTNode *second;
			struct ASTNode *third; 
			struct ASTNode *fourth; 
		} quaternarynodetype;

		struct ASTExprTernaryOp {
			struct ASTNode *first;
			struct ASTNode *second;
			struct ASTNode *third; 
		} ternarynode;

		struct ASTUnaryNode
		{
			UnaryType type;
			struct ASTNode *child;
		} unarynode;

		int litval;
	};

};