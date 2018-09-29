a.out:m.o fop.o rpc_fp.o rpcc_fp.o send_rpc_req.o rec_rpc_req.o rpcs_fp.o
	gcc m.o fop.o rpc_fp.o rpcc_fp.o send_rpc_req.o rec_rpc_req.o rpcs_fp.o

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

rec_rpc_req.o:rec_rpc_req.c rpc_req.h rpc_fp.h
	gcc rec_rpc_req.c -c

rpcs_fp.o:rpcs_fp.c rpc_req.h rpc_fp.h
	gcc rpcs_fp.c -c

clean:
	rm -rf *.o
	rm -rf a.out
