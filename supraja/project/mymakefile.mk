a.out:main.o fop.o rpc_fop.o
	gcc main.o fop.o rpc_fop.o 
main.o:main.c
	gcc main.c -c
fop.o:fop.c
	gcc fop.c -c
rpc_fop.o:rpc_fop.c
	gcc rpc_fop.c -c
