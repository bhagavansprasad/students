client: main.o crpc.o ctxrx_rpc_data.o
	gcc main.o crpc.o ctxrx_rpc_data.o -o client

main.o: main.c 
	gcc main.c -c

crpc.o: crpc.c 
	gcc crpc.c -c

ctxrx_rpc_data.o: ctxrx_rpc_data.c 
	gcc ctxrx_rpc_data.c -c

clean:
	rm -rf *.o
	rm -rf a.out
	rm -rf client
 
