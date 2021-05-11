test:
	gcc AD7147.c test.c test/Wire.c -o test.elf -Itest/

all:
	gcc AD7147.c test.c -o test.elf -Iimpl/

clean:
	rm -f test.elf

run:
	./test.elf

runtest: clean test run
runtests: clean test run

.PHONY: all test clean
