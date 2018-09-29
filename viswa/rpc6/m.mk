
a.out : main.o afun.o rpc_fun.o  rpc_fop.o send.o recv.o 
	gcc -g  main.o afun.o rpc_fun.o rpc_fop.o send.o  recv.o 

main.o : main.c afun.h
		gcc -g main.c -c

afun.o : afun.c afun1.h
		gcc -g afun.c -c

rpc_fun.o : rpc_fun.c afun2.h
		gcc -g rpc_fun.c -c

rpc_fop.o : rpc_fop.c afun3.h
		gcc -g rpc_fop.c -c
send.o : send.c afun4.h
		gcc -g send.c -c

recv.o : recv.c 
		gcc -g recv.c -c

