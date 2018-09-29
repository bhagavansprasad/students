server : stxrx_rpc_data.o rpc_fop.o
	gcc stxrx_rpc_data.o rpc_fop.o -o server

stxrx_rpc_data.o : stxrx_rpc_data.c
	gcc stxrx_rpc_data.c -c

rpc_fop.o : rpc_fop.c
	gcc rpc_fop.c -c

clean :
	rm -rf *.o
	rm -rf server
