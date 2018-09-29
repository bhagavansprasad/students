my.out:addmulsub.o add.o mul.o sub.o
	gcc addmulsub.o add.o mul.o sub.o -o my.out
addmulsub.o: addmulsub.c
	gcc -c addmulsub.c
add.o: add.c
	gcc -c add.c
mul.o: mul.c
	gcc -c mul.c
sub.o: sub.c
	gcc -c sub.c

clean: 
	rm my.out
	rm *.o
