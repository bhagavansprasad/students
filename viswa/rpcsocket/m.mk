a.out : main.o fun.o rpc_fun.o rpc_fop.c send.o socket_init.o
		gcc -g  main.o fun.o rpc_fun.o rpc_fop.c send.o socket_init.o 

main.o : main.c afun.h 
		gcc -g main.c -c

socket_init.o : socket_init.c struct.h second_struct.h
		gcc -g socket_init.c -c

fun.o : fun.c rpc_fun.h
		gcc -g fun.c -c

rpc_fun.o : rpc_fun.c rpc_fop.h struct.h
		gcc -g rpc_fun.c -c

rpc_fop.o : rpc_fop.c struct.h second_struct.h
		gcc -g rpc_fop.c -c

send.o : send.c struct.h second_struct.h 
		gcc -g send.c -c

clean : 
		rm -rf *.o
		rm -rf a.out


