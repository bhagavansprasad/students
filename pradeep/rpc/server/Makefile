INC := -I../inc
CFLAGS := -g -Wall -Werror

server: rpcs.o nets.o rpcs1.o
	gcc $(INC) $(CFLAGS) rpcs.o nets.o rpcs1.o -o server

rpcs.o: rpcs.c
	gcc $(INC) $(CFLAGS) -c rpcs.c

nets.o: nets.c
	gcc $(INC) $(CFLAGS) -c nets.c

rpcs1.o: rpcs1.c
	gcc $(INC) $(CFLAGS) -c rpcs1.c

clean:
	rm -rf a.out
	rm -rf *.o
	rm -rf server
	rm -rf b.txt e.txt
