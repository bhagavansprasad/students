a.out: 3-main.o mystr-bb.a
	gcc 3-main.c -L. -lmystr-bb

mystr-bb.a: astrcasecmp.o astrcat.o astrcmp.o astrcpy.o astrncmp.o astrncpy.o astrlen.o astrncat.o astrncasecmp.o
	ar rcs libmystr-bb.a astrcasecmp.o astrcat.o astrcmp.o astrcpy.o astrncmp.o astrncpy.o astrlen.o astrncat.o astrncasecmp.o

main.o: 3-main.c
	gcc 3-main.c -c

astrcasecmp.o: astrcasecmp.c
	gcc astrcasecmp.c -c

astrcat.o:astrcat.c
	gcc astrcat.c -c

astrcmp.o:astrcmp.c
	gcc astrcmp.c -c

astrcpy.o:astrcpy.c
	gcc astrcpy.c -c

astrncmp.o:astrncmp.c
	gcc astrncmp.c -c

astrncpy.o:astrncpy.c
	gcc astrncpy.c -c

astrlen.o:astrlen.c
	gcc astrlen.c -c

astrncat.o:astrncat.c
	gcc astrncat.c -c

astrncasecmp.o:astrncasecmp.c
	gcc astrncasecmp.c -c

clean:
	rm -rf *.o
	rm -rf a.out
