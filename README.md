DECAF COMPILER
--------------

+ The repository has been version tagged for ease of understanding

1. Directory structure
  + SampleCodes: Contains sample decaf files to test on
  + SCANNER-PARSER: Contains parser for semnatic analysis
  + AST-CONSTRUCTION: Contains AST generation/Postfix notation in C
  + IR-GENERATOR: Contains IR Generation in CPP using  C++ API

2. How to run it
  + make
  + redirect input to the generated executable file(parser)
  + To run main code refer to test.sh(flow can be seen there)

3. Description
  + The scanner is made using flex. All tokens are put as regular expressions.
  + The parser is made using bison. The tokens are passed to it and it looks up the given CFG syntax
  + classes are made for taking nodes and making a parse tree
  + IR is generated using CPP Api of llvm

4. To implement
  + Pointers
  + scanf

WHY C and CPP
-------------
+ I later on found out that C-Api with only structs is very hard to implement.
+ Hence I kept the same scanner and parser rules and changed AST to one similar to visitor-cpp

LINKS Referred to
-----------------
+ https://gist.github.com/alloy/d86b007b1b14607a112f
+ http://peeterjoot.com/tag/llvm-c-api/
+ https://llvm.org/docs/tutorial/LangImpl03.html
+ LLVM-documentation for various class methods and datatypes
