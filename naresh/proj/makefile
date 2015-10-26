CFLAGS := -Wall
#CFLAGS += -Werror
CFLAGS += -c
DEBUG_FLAGS := -g

a.out: ms.o fop1.o rpccfop.o fope.o
	gcc ms.o fop1.o rpccfop.o fope.o $(DEBUG_FLAGS)

ms.o: ms.c fop.h
	gcc ms.c  $(CFLAGS) $(DEBUG_FLAGS)

fop1.o: fop1.c rpcc.h
	gcc fop1.c $(CFLAGS) $(DEBUG_FLAGS)

rpccfop.o: rpccfop.c rpcc_fope.h
	gcc rpccfop.c  $(CFLAGS) $(DEBUG_FLAGS)

rpcc_fope.o: rpcc_fope.c 
	gcc rpcc_fope.c  $(CFLAGS) $(DEBUG_FLAGS)

clean:
	rm -rf *.o
	rm -rf a.out
