a.out:main.o fop.o rpccfop.o rpccfope.o
	gcc main.o fop.o rpccfop.o rpccfope.o

main.o:main.c fop.h
	gcc main.c -c

fop.o:fop.c rpccfop.h
	gcc fop.c -c

rpccfop.o:rpccfop.c rpccfope.h
	gcc rpccfop.c -c

rpccfope.o:rpccfope.c
	gcc rpccfope.c -c

clean:
	rm -rf a.out
	rm -rf *.o

