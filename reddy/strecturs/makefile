a.out:r.o fop.o rpccfop.o rpccfope.o
	gcc r.o fop.o rpccfop.o rpccfope.o

r.o:r.c fop.h
	gcc r.c -c

fop.o:fop.c rpccfop.h
	gcc fop.c -c

rpccfop.o:rpccfop.c rpccfope.h
	gcc rpccfop.c -c

rpccfope.o:rpccfope.c
	gcc rpccfope.c -c

clean:
	rm -rf a.out
	rm -rf *.o

