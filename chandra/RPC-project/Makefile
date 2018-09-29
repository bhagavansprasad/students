a.out          : main.o fop.o rpc_fop.o rpcc_fop.o rpc_send_req.o rpc_recv_req.o rpcs_fop.o
		         gcc main.o fop.o rpc_fop.o rpcc_fop.o rpc_send_req.o rpc_recv_req.o rpcs_fop.o

main.o         : main.c fop.h
		         gcc main.c -c

fop.o          : fop.c rpc_fop.h
		         gcc fop.c -c

rpc_fop.o      : rpc_fop.c rpc_fop.h rpcc_fop.h rpc_send_req.h
		         gcc rpc_fop.c -c

rpcc_fop.o     : rpcc_fop.c rpc_send_req.h
			     gcc rpcc_fop.c -c

rpc_send_req.o : rpc_send_req.c rpc_recv_req.h
				 gcc rpc_send_req.c -c

rpc_recv_req.o : rpc_recv_req.c rpcs_fop.h
				 gcc rpc_recv_req.c -c

rpcs_fop.o     : rpcs_fop.c  rpcc_fop.h rpc_send_req.h
			     gcc rpcs_fop.c -c

