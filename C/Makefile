parser: parser.y scanner.l
		bison -dv parser.y
		flex scanner.l
		gcc -o parser parser.tab.c lex.yy.c -lfl
