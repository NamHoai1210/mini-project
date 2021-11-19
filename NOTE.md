# Some notes

## Basic Idea of each file
- dict-main.c				: main function of the project
- dict-header.h				: definition of functions using in the project
- dict-function.c			: source code for functions in dict-header.h
- dict-test.c				: test file for inserting and inserting 1 million words
- dict-soundex-test.c		: test file for soundex library (used for auto-suggestion)
- dict-soundex.h			: definition of soundex functions
- dict-soundex-lib.c		: source code of soundex library
- dict-test-database.txt	: text file for testing the reading-from-file function
- dict-million-database.txt	: text file containing 1 million lines

## Prerequisites
- First, clone the directory to your local machine, then put all the file into the B-tree library 
(put it into the same directory with inc, src-lib, src-main, Makefile,...)

- If you want to run the main project, then run:
	gcc -c dict-main.c
	gcc -c dict-function.c
	gcc -c dict-soundex-lib.c
	gcc -o dict-main dict-main.o dict-function.o dict-soundex-lib.o -Iinc -Llib -lbt

- If you want to run the test file, then replace:
	gcc -c dict-main.c
with:
	gcc -c dict-test.c

