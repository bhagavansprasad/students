a.out:	m.c libmystr.a
	gcc m.c -L. -lmystr 

libmystr.a: a.o b.o c.o d.o
	ar rcs libmystr.a a.o b.o c.o d.o

m.o: m.c
	gcc -c m.c

a.o: a.c
	gcc -c a.c

