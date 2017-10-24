a.out :main.o astrlen.o astrcpy.o astrncpy.o astrcmp.o astrncmp.o astrrev.o astrcat.o astrcasecmp.o
	gcc main.o astrlen.o astrcpy.o astrncpy.o astrcmp.o astrncmp.o astrrev.o astrcat.o astrcasecmp.o -o a.out

main.o : main.c 
	gcc main.c -c

astrlen.o : astrlen.c
	gcc astrlen.c -c


astrcpy.o : astrcpy.c
	gcc astrcpy.c -c

astrncpy.o : astrncpy.c
	gcc astrncpy.c -c


astrcmp.o : astrcmp.c
	gcc astrcmp.c -c

astrncmp.o : astrncmp.c
	gcc astrncmp.c -c

astrrev.o : astrrev.c
	gcc astrrev.c -c

astrcat.o : astrcat.c
	gcc astrcat.c -c

astrcasecmp.o : astrcasecmp.c
	gcc astrcasecmp.c -c

clean :
	rm -rf *.o
	rm -rf a.out
