INC_PATH := -I../inc

CFLAGS := -Wall -Werror 
DEBUG_FLAGS := -g 

server: rpcs.o rpcs_net.o rpcs_fop.o
	gcc $(DEBUG_FLAGS) rpcs.o rpcs_net.o rpcs_fop.o -o server

rpcs.o: rpcs.c
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) rpcs.c -c

rpcs_net.o: rpcs_net.c
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) rpcs_net.c -c

rpcs_fop.o: rpcs_fop.c
	gcc $(CFLAGS) $(DEBUG_FLAGS) $(INC_PATH) rpcs_fop.c -c
	
clean:
	rm -rf *.o
	rm -rf server
