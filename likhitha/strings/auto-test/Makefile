mystr :1-main.o astrlen.o astrcmp.o 
	gcc 1-main.o astrlen.o astrcmp.o -o mystr

1-main.o : 1-main.c 
	gcc 1-main.c -c

astrlen.o : astrlen.c
	gcc astrlen.c -c

astrcmp.o : astrcmp.c
	gcc astrcmp.c -c

clean :
	rm -rf *.o
	rm -rf a.out
	rm -rf mystr.out
	rm -rf mystr
