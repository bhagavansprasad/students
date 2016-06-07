#gcc main.c aopen.c rpc_op.c rpc_op.h client.c

CFLAGS:= -c
DEBUG_FLAGS := -g
INC_PATH := -I/home/bhagavan/students/hema/rpc_proj/inc

crpc:main.o aopen.o rpc_op.o client.o
	gcc $(DEBUG_FLAGS) main.o aopen.o rpc_op.o client.o -o crpc

main.o :main.c
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) main.c

aopen.o :aopen.c
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) aopen.c

rpc_op.o :rpc_op.c
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) rpc_op.c

client.o :client.c
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) client.c

clean:
	rm -rf *.o crpc


