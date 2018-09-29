a.out: version.o
	gcc version.o -lsqlite3 -std=c99

version.o: version.c
	gcc -c version.c

clean:
	rm -rf a.out
	rm -rf *.o
	rm -rf version



