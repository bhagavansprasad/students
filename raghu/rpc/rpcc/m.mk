client: m.o fop.o rpc_fp.o rpcc_fp.o send_rpc_req.o client_rpc.o debug.o
	gcc m.o fop.o rpc_fp.o rpcc_fp.o send_rpc_req.o client_rpc.o debug.o -o client
 
m.o:m.c fop.h
	gcc m.c -c

fop.o:fop.c rpc_fp.h
	gcc fop.c -c

rpc_fp.o:rpc_fp.c rpcc_fp.h
	gcc rpc_fp.c -c

rpcc_fp.o:rpcc_fp.c rpc_req.h rpc_fp.h
	gcc rpcc_fp.c -c

send_rpc_req.o:send_rpc_req.c rpc_fp.h rpc_req.h
	gcc send_rpc_req.c -c

client_rpc.o:client_rpc.c rpc_req.h rpcc_fp.h
	gcc client_rpc.c -c

debug.o:debug.c rpc_fp.h
	gcc debug.c -c
clean:
	rm -rf *.o
	rm -rf a.out
	rm -rf client
