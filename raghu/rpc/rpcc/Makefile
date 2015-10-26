client: m.o librpcc.a
	gcc m.o -L. -lrpcc -o client

librpcc.a: fop.o rpc_fp.o rpcc_fp.o send_rpc_req.o client_rpc.o debug.o
	ar rcs librpcc.a fop.o rpc_fp.o rpcc_fp.o send_rpc_req.o client_rpc.o debug.o
 
m.o:m.c fop.h
	gcc -g m.c -c

fop.o:fop.c rpc_fp.h
	gcc -g fop.c -c

rpc_fp.o:rpc_fp.c rpcc_fp.h
	gcc -g rpc_fp.c -c

rpcc_fp.o:rpcc_fp.c rpc_req.h rpc_fp.h
	gcc -g rpcc_fp.c -c

send_rpc_req.o:send_rpc_req.c rpc_fp.h rpc_req.h
	gcc -g send_rpc_req.c -c

client_rpc.o:client_rpc.c rpc_req.h rpcc_fp.h
	gcc -g client_rpc.c -c

debug.o:debug.c rpc_fp.h
	gcc -g debug.c -c

clean:
	rm -rf *.o
	rm -rf client
	rm -rf *.a
