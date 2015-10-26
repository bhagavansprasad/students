a.out : ms.o fop1.o rpccfop.o
	gcc ms.o fop1.o rpccfop.o
ms.o : ms.c
	gcc ms.c -c
fop1.o : fop1.c
	gcc ms.c -c
rpccfop.o : rpccfop.c
	gcc rpccfop.c -c
