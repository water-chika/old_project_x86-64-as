all:
	make -C utils

.PHONY: test clean

test:
	make -C test test
clean:
	rm -f as
	make -C utils clean
