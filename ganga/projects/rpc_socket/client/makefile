client : main.o crpc.o ctxrx_rpc_data.o rpc_fop.o
	gcc main.o crpc.o ctxrx_rpc_data.o rpc_fop.o -o client

main.o : main.c
	gcc main.c -c

crpc.o : crpc.c
	gcc crpc.c -c

ctxrx_rpc_data.o : ctxrx_rpc_data.c
	gcc ctxrx_rpc_data.c -c

rpc_fop.o : rpc_fop.c
	gcc rpc_fop.c -c

clean :
	rm -rf *.o
	rm -rf client
