a.out : main.o fop.o rpccfop.o rpcc_fop.o
	gcc main.o fop.o rpccfop.o rpcc_fop.o
main.o : main.c fop.h
	gcc main.c -c
fop.o : fop.c fop.h
	gcc fop.c -c
rpccfop.o : rpccfop.c fop.h struct.h union.h
	gcc rpccfop.c -c
rpcc_fop.o : rpcc_fop.c fop.h
	gcc rpcc_fop.c -c
