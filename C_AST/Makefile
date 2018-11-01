decaf: parser.y scanner.l ast.c ast.h
		bison -dv parser.y
		flex scanner.l
		gcc -o parser parser.tab.c lex.yy.c ast.c -lfl
calc: calc.y calc.l ast_calc.c ast_calc.h
		bison -dv calc.y
		flex calc.l
		gcc -o calc calc.tab.c lex.yy.c ast.c -lfl
clean:
	rm -rf lex.yy.c calc.tab.c calc *.output calc.tab.h parser parser.tab.*
