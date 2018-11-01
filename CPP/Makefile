parser: parser.y scanner.l ast.cpp
		bison -dv parser.y
		flex scanner.l
		g++ -o parser parser.tab.c lex.yy.c ast.c -lfl
clean:
	rm -rf *.tab.h *.c parser *.output
