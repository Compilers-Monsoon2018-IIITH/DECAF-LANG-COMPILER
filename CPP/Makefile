parser: parser.y scanner.l ast.cpp
		bison -dv parser.y
		flex scanner.l
		gcc -o parser parser.tab.c lex.yy.c ast.cpp -lfl
clean:
	rm -rf *.tab.h *.c parser *.output
