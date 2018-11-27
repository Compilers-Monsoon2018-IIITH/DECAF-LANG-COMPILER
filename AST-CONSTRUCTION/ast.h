typedef enum  astnodetype {NONE, BinaryOp, TernaryOp, INTLITERAL, Unary, Binary, Ternary, Quaternary, Pentnary} ASTNodeType;
typedef enum  binaryoptype { NO_USE } BinaryOpType;
typedef enum  binarynodetype {FIELDS, FIELD_DECLS,FIELD_DECL, METHOD_DECLS, INPUTS, INPUT, BLOCK_PARTS, VAR_DECLS, VAR_DECL, STMTS, IDS, RETURN, METHOD_CALL, CALLOUT_ARGS, LOCATION, EXPRS} BinaryNodeType;
typedef enum  ternarynodetype {LIST_ID,VOID_METHOD_DECL, STMT, STMT_IF, STMT_IF_ELSE, EXPR} TernaryNodeType;
typedef enum  quaternarynodetype {METHOD_DECL} QuaternaryNodeType;
typedef enum  pentnarynodetype {FOR} PentnaryNodeType;
typedef enum  unarytype {PROG_TYPE, TYPE, BLOCK, ID, INT_TYPE, BOOL_TYPE, RET, BREAK, CONT, ASS, PLUS_EQ, MINUS_EQ, METHOD_NAME, CALLOUT, STR_LIT, NOT, CALLOUT_ARG, BIN_OP, ADD, SUB, MUL, DIV, MOD, GT, LT, GE, LE, EQ, NEQ, AND, OR, INT_LIT, BOOL_LIT,CHAR_LIT, DEC, HEX, T, F} UnaryType;

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

extern struct ASTNode *getASTNodePentnaryNode(struct ASTNode *first,
									struct ASTNode *second,
									struct ASTNode *third,
									struct ASTNode *fourth,
									struct ASTNode *fifth,
									PentnaryNodeType type);


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

		struct ASTPentnaryNode {
			PentnaryNodeType type;
			struct ASTNode *first;
			struct ASTNode *second;
			struct ASTNode *third; 
			struct ASTNode *fourth; 
			struct ASTNode *fifth; 
		} pentnarynodetype;

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