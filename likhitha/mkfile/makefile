a.out : m.o defs.o
	gcc m.o -o  a.out

m.o : m.c
	gcc m.c -c

defs.o : defs.h
	gcc defs.h

clean:
	rm -rf *.o
