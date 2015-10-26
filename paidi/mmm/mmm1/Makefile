mmm : malloc.o my.o 
	gcc -lpthread malloc.o my.o -o mmm
malloc.o: malloc.c  mem_req.h
	gcc malloc.c -g -c
my.o: my.c  mem_req.h
	gcc my.c -g  -c



clean :
	rm -rf mmm
	rm -rf *.o

