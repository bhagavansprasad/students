#gcc main.c aopen.c rpc_op.c rpc_op.h rpcfop.c

CFLAGS:= -c
DEBUG_FLAGS := -g

myrpc:main.o aopen.o rpc_op.o rpcfop.o
	gcc $(DEBUG_FLAGS) main.o aopen.o rpc_op.o rpcfop.o -o myrpc

main.o :main.c
	gcc $(CFLAGS) $(DEBUG_FLAGS) main.c

aopen.o :aopen.c
	gcc $(CFLAGS) $(DEBUG_FLAGS) aopen.c

rpc_op.o :rpc_op.c
	gcc $(CFLAGS) $(DEBUG_FLAGS) rpc_op.c

rpcfop.o :rpcfop.c
	gcc $(CFLAGS) $(DEBUG_FLAGS) rpcfop.c

clean:
	rm -rf *.o
	rm -rf myrpc


