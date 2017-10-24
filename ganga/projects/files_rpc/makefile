rpc : main.o arpc.o crpc.o rpc_fop.o
	gcc	main.o arpc.o crpc.o rpc_fop.o -o rpc

main.o : main.c
	gcc main.c -c

arpc.o : arpc.c
	gcc arpc.c -c

crpc.o : crpc.c
	gcc crpc.c -c

rpc_fop.o : rpc_fop.c
	gcc rpc_fop.c -c

clean :
	rm -rf *.o
	rm -rf rpc
