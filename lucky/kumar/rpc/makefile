a.out: main.o fop.o rpcc.o rpcc_fop.o
	gcc main.o fop.o rpcc.o rpcc_fop.o
main.o:main.c fop.h
	gcc main.c -c
fop.o:fop.c rpcc.h	
	gcc fop.c -c
rpcc.o:rpcc.c rpcc_fop.h
	gcc rpcc.c -c
rpcc_fop.o:rpcc_fop.c  structure.h comm_defs.h
	gcc rpcc_fop.c -c

clean:
	rm -rf a.out
	rm -rf *.o
