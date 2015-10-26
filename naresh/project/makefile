a.out : ms.o fop1.o rpccfop.o
	gcc ms.o fop1.o rpccfop.o
ms.o : ms.c fop.h
	gcc ms.c -c
fop1.o : fop1.c rpcc.h
	gcc fop1.c -c
rpccfop.o : rpccfop.c
	gcc rpccfop.c -c
