as: as.c lexer.c encoder.c
	gcc -o as as.c lexer.c encoder.c

loader: loader.c
	gcc -o loader loader.c