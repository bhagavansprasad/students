INC := -I../inc
CFLAGS := -g -Wall -Werror

client : rpcc.o rpcc1.o rpcc2.o rpcc3.o netc.o
	gcc rpcc.o rpcc1.o rpcc2.o rpcc3.o netc.o -o client

rpcc.o : rpcc.c fop.h
	gcc $(INC) $(CFLAGS) rpcc.c -c

rpcc1.o : rpcc1.c fop.h
	gcc  $(INC) $(CFLAGS) rpcc1.c -c

rpcc2.o : rpcc2.c fop.h fop1.h 
	gcc  $(INC) $(CFLAGS) rpcc2.c -c

rpcc3.o : rpcc3.c fop.h fop1.h
	gcc  $(INC) $(CFLAGS) rpcc3.c -c

netc.o : netc.c 
	gcc  $(INC) $(CFLAGS) netc.c -c

clean : 
	rm -rf *.o
	rm -rf a.out
	rm -rf client
