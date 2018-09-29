INC := -I../inc
CFLAGS := -g -Wall -Werror

client : rpc_main.o fop.o rpcc.o rpcc_fop.o rpc_netc.o
	gcc  rpc_main.o fop.o rpcc.o rpcc_fop.o rpc_netc.o -o client

rpc_main.o : rpc_main.c rpc_netc.h fop.h
	gcc $(INC) $(CFLAGS) rpc_main.c -c

fop.o : fop.c rpcc.h
	gcc  $(INC) $(CFLAGS) fop.c -c

rpcc.o : rpcc.c rpcc_fop.h
	gcc  $(INC) $(CFLAGS) rpcc.c -c

rpcc_fop.o : rpcc_fop.c  
	gcc  $(INC) $(CFLAGS) rpcc_fop.c -c

rpc_netc.o : rpc_netc.c 
	gcc  $(INC) $(CFLAGS) rpc_netc.c -c

clean : 
	rm -rf *.o
	rm -rf client
