INC_PATH := -I../inc

CFLAGS := -Wall -Werror 
DEBUG_FLAGS := -g 

client:m.o fop.o rpccfop.o client.o rpcfope.o
	gcc $(CFLAGS) m.o fop.o rpccfop.o client.o rpcfope.o -o client

m.o:m.c defs.h fop.h
	gcc $(CFLAGS) $(DEBUG_FLAGS) -Wall -Werror $(INC_PATH) m.c -c

fop.o:fop.c rpcc.h
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) fop.c -c

rpccfop.o:rpccfop.c rpccfope.h
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) rpccfop.c -c

client.o:client.c 
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) client.c -c

rpcfope.o:rpcfope.c 
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) rpcfope.c -c

clean:
	rm -rf a.out
	rm -rf client 
	rm -rf *.o

