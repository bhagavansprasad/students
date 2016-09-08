
CFLAGS:= -c
DEBUG_FLAGS := -g
INC_PATH := -I/home/bhagavan/students/hema/rpc_proj/inc

srpc:server.o rpcfop.o
	gcc $(DEBUG_FLAGS) server.o rpcfop.o -o srpc

server.o :server.c
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) server.c

rpcfop.o :rpcfop.c
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) rpcfop.c

clean:
	rm -rf *.o srpc


