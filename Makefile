all:
	gcc AD7147.c test.c -o test.elf -DOFFLINE_TEST

clean:
	rm -f test.elf

run:
	./test.elf

runtest: clean all run
