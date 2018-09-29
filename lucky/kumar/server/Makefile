INC := -I../inc
CFLAGS := -g -Wall -Werror

server: rpcs.o nets.o rpcs3.o
	gcc $(INC) $(CFLAGS) rpcs.o nets.o rpcs3.o -o server

rpcs.o: rpcs.c
	gcc $(INC) $(CFLAGS) -c rpcs.c

nets.o: nets.c
	gcc $(INC) $(CFLAGS) -c nets.c

rpcs3.o: rpcs3.c
	gcc $(INC) $(CFLAGS) -c rpcs3.c

clean:
	rm -rf a.out
	rm -rf *.o
	rm -rf server
