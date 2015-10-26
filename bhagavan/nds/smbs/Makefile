CFLAGS := -g -Wall -Werror
INC_PATH := -I../include

smbs : listener.o sys_fop.o
	gcc $(INC_PATH) $(CFLAGS) listener.o sys_fop.o -o smbs

sys_fop.o: sys_fop.c
	gcc $(INC_PATH) $(CFLAGS) -c sys_fop.c

listener.o: listener.c
	gcc $(INC_PATH) $(CFLAGS) -c listener.c

clean:
	rm -rf *.o
	rm -rf smbs
