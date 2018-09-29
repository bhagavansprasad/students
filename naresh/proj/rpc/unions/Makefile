a.out:m.o fop.o rpccfop.o rpccfope.o
	gcc  m.o fop.o rpccfop.o rpccfope.o

m.o:m.c defs.h fop.h
	gcc  m.c -c

fop.o:fop.c rpccfop.h
	gcc  fop.c -c

rpccfop.o:rpccfop.c rpccfop.h rpccfope.h
	gcc  rpccfop.c -c

rpccfope.o:rpccfope.c
	gcc  rpccfope.c -c

clean:
	rm -rf *.o
	rm -rf a.out

