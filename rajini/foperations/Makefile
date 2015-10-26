a.out:b.o rpccfop1.o rpcc1.o rpcc_fope.o
	gcc b.o rpccfop1.o rpcc1.o rpcc_fope.o
b.o:b.c fop.h
	gcc b.c -c
rpccfop1.o:rpccfop1.c rpccfop.h
	gcc rpccfop1.c -c
rpcc1.o:rpcc1.c rpccfop1.h
	gcc rpcc1.c -c
rpccfope.o:rpcc_fope.c
	gcc rpcc_fope.c -c
