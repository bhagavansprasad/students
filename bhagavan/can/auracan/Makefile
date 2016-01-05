cangen: cangen.o lib.o
	gcc cangen.o lib.o -o cangen

cangen.o: cangen.c  lib.h
	gcc cangen.c -c

lib.o: lib.c  lib.h
	gcc lib.c -c

clean:
	rm -rf *.o
	rm -rf cangen 


