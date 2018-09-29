INC_PATH := -I../inc

CFLAGS := -Wall -Werror

server: rpcs.o nets.o rpccfope.o
	gcc $(INC_PATH) $(CFLAGS) rpcs.o nets.o rpccfope.o -o server

rpcs.o: rpcs.c
	gcc $(INC_PATH) $(CFLAGS) rpcs.c -c

nets.o: nets.c
	gcc $(INC_PATH) $(CFLAGS) nets.c -c

rpccfope.o: rpccfope.c
	gcc $(INC_PATH) $(CFLAGS) rpccfope.c -c

clean:
	rm -rf a.out
	rm -rf *.o
	rm -rf server
