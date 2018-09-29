INC := -I../inc
CFLAGS := -g -Wall -Werror

client:rpcc.o rpcc1.o rpcc2.o rpcc3.o netc.o 
	gcc  $(INC) $(CFLAGS) rpcc.o rpcc1.o rpcc2.o rpcc3.o netc.o -o client

rpcc.o:rpcc.c defs.h fop.h
	gcc  $(INC) $(CFLAGS) rpcc.c -c

rpcc1.o:rpcc1.c rpccfop.h
	gcc  $(INC) $(CFLAGS) rpcc1.c -c

rpcc2.o:rpcc2.c rpccfop.h rpccfope.h
	gcc  $(INC) $(CFLAGS) rpcc2.c -c

rpcc3.o:rpcc3.c rpccfop.h
	gcc  $(INC) $(CFLAGS) rpcc3.c -c

netc.o:netc.c 
	gcc  $(INC) $(CFLAGS) netc.c -c

clean:
	rm -rf a.out
	rm -rf *.o
	rm -rf client

