INC := -I../inc
CFLAGS := -g -Wall -Werror

server: rpc_server.o rpc_nets.o rpc_process.o
	gcc $(INC) $(CFLAGS) rpc_server.o rpc_nets.o rpc_process.o -o server

rpc_server.o: rpc_server.c 
	gcc $(INC) $(CFLAGS) -c rpc_server.c

rpc_nets.o: rpc_nets.c 
	gcc $(INC) $(CFLAGS) -c rpc_nets.c

rpc_process.o: rpc_process.c
	gcc $(INC) $(CFLAGS) -c rpc_process.c

clean:
	rm -rf *.o
	rm -rf server
	rm -rf b.txt
	rm -rf c.txt
