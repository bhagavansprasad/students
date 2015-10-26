a.out:m.o fop.o rpc_fp.o
	gcc m.o fop.o rpc_fp.o
m.o:m.c
	gcc m.c -c
fop.o:fop.c
	gcc fop.c -c
rpc_fp.o:rpc_fp.c
	gcc rpc_fp.c -c
