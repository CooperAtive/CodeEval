CFLAGS = -Wall -g

errors:
	rm -f strrev
	make strrev
	valgrind -v ./strrev

leaks:
	rm -f strrev
	make strrev
	valgrind --leak-check=full --show-leak-kinds=all ./strrev
gdb:
	rm -f strrev
	make strrev
	gdb ./strrev
