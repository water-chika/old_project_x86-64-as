as: as.c lexer.c encoder.c
	gcc -Iinclude -o as as.c lexer.c encoder.c

loader: loader.c
	gcc -Iinclude -o loader loader.c

clean:
	rm -f as loader
