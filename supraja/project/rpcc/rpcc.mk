a.out:m.o fop.o rpc_fp.o rpcc_fp.o
	gcc m.o fop.o rpc_fp.o rpcc_fp.o
m.o:m.c
	gcc -c m.c
fop.o:fop.c
	gcc -c fop.c
rpc_fp.o:rpc_fp.c
	gcc -c rpc_fp.c
rpcc_fp.o:rpcc_fp.c
	gcc -c rpcc_fp.c
	
