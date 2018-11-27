decaf: parser.y scanner.l ast.h codegen.h
		bison -dv parser.y
		flex scanner.l
		g++ -o parser parser.tab.c lex.yy.c -std=c++11 `llvm-config --cppflags --libs all --ldflags --system-libs`

clean :
	rm -f parser lex.yy.c parser.tab.c parser.tab.h *.o