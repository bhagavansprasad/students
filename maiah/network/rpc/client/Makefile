INC_PATH := -I../inc

CFLAGS := -Wall -Werror 
DEBUG_FLAGS := -g 

client: main.o fop.o rpcc.o rpcc_fop.o rpcc_net.o 
	gcc $(CFLAGS) main.o fop.o rpcc.o rpcc_fop.o rpcc_net.o -o client

main.o:main.c fop.h 
	gcc $(CFLAGS) $(DEBUG_FLAGS) -Wall -Werror $(INC_PATH) main.c -c

fop.o:fop.c rpcc.h
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) fop.c -c

rpcc.o:rpcc.c  rpcc_fop.h 
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) rpcc.c -c

rpcc_fop.o:rpcc_fop.c 
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) rpcc_fop.c -c

rpcc_net.o:rpcc_net.c
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) rpcc_net.c -c

clean:
	rm -rf *.o
	rm -rf client
