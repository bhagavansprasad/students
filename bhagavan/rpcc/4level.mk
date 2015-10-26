rpcc:client3.o afop3.o rpcc.o rpcc_send_req.o rpcs_recv_req.o rpc_reciv_open.o
	gcc -g client3.o afop3.o rpcc.o rpcc_send_req.o rpcs_recv_req.o rpc_reciv_open.o -o rpcc

client3.o: client3.c afop2.h
	gcc -g -c client3.c 

afop3.o: afop3.c rpcc.h
	gcc -g -c afop3.c

rpcc.o: rpcc.c  req_defs.h
	gcc -g -c rpcc.c

rpcc_send_req.o: rpcc_send_req.c rep_defs.h req_defs.h
	gcc -g -c rpcc_send_req.c

rpcs_recv_req.o:rpcs_recv_req.c req_defs.h rep_defs.h rpcs.h
	gcc -g -c rpcs_recv_req.c

rpc_reciv_open.o:rpc_reciv_open.c
	gcc -g -c rpc_reciv_open.c

clean:
	rm -rf rpcc
	rm -rf *.o
