client:m.o fop.o rpccfop.o client.o rpcfope.o
	gcc  m.o fop.o rpccfop.o client.o rpcfope.o -o client

m.o:m.c defs.h fop.h
	gcc  m.c -c

fop.o:fop.c rpccfop.h
	gcc  fop.c -c

rpccfop.o:rpccfop.c rpccfop.h rpccfope.h
	gcc  rpccfop.c -c

client.o:client.c rpccfope.h
	gcc client.c -c

rpcfope.o:rpcfope.c 
	gcc rpcfope.c -c

clean:
	rm -rf a.out
	rm -rf client 
	rm -rf *.o

