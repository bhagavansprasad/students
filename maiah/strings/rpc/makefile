a.out:rpcc_fopprog.o fop.o rpcc1.o rpcc_fop.o
	gcc rpcc_fopprog.o fop.o rpcc1.o rpcc_fop.o

rpcc_fopprog.o:rpcc_fopprog.c fop.h
	gcc rpcc_fopprog.c -c

fop.o:fop.c rpcc1.h
	gcc fop.c -c

rpcc1.o:rpcc1.c rpcc_fop.h
	gcc rpcc1.c -c

rpcc_fop.o:rpcc_fop.c
	gcc rpcc_fop.c -c

clean:
	rm -rf a.out
	rm -rf *.o
