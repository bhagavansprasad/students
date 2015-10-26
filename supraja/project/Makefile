DEBUG_FLAGS:= -g 
CFLAGS:= -Wall -Werror

myproj : main.o fop.o rpc_fop.o
	gcc $(DEBUG_FLAGS)  main.o fop.o rpc_fop.o -o myproj

main.o: main.c
	gcc -c $(DEBUG_FLAGS) $(CFLAGS) main.c

fop.o: fop.c
	gcc -c $(DEBUG_FLAGS) $(CFLAGS) fop.c

rpc_fop.o: rpc_fop.c
	gcc -c $(DEBUG_FLAGS) $(CFLAGS) rpc_fop.c

clean:
	rm -rf *.o
	rm -rf myproj
