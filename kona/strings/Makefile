a.out: mainstring.o astrcpy.o astrncpy.o astrcmp.o astrncmp.o astrlen.o astrcasecmp.o astrncasecmp.o astrcat.o astrncat.o astrlwr.o astrupr.o
	
	gcc  mainstring.o astrcpy.o astrncpy.o astrcmp.o astrncmp.o astrlen.o astrcasecmp.o astrncasecmp.o astrcat.o astrncat.o astrlwr.o astrupr.o -o a.out

mainstring.o: mainstring.c defh.h
	
	gcc -c mainstring.c

astrcpy.o: astrcpy.c
	
	gcc -c astrcpy.c

astrncpy.o: astrncpy.c
	
	gcc -c astrncpy.c

astrcmp.o: astrcmp.c
	
	gcc -c astrcmp.c

astrncmp.o: astrncmp.c
	
	gcc -c astrncmp.c

astrlen.o: astrlen.c
	
	gcc -c astrlen.c

astrcasecmp.o: astrcasecmp.c
	
	gcc -c astrcasecmp.c

astrncasecmp.o: astrncasecmp.c 
	
	gcc -c astrncasecmp.c

astrcat.o: astrcat.c
	
	gcc -c astrcat.c

astrncat.o: astrncat.c
	
	gcc -c astrncat.c

astrlwr.o: astrlwr.c
	
	gcc -c astrlwr.c

astrupr.o: astrupr.c
	
	gcc -c astrupr.c

clean:
	
	rm -rf a.out
	
	rm -rf *.o

