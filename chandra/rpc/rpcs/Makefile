rpc_server : server.o rpc_recv_req.o rpcs_fop.o tcp_server.o debug_after_read.o
	gcc -g server.o rpc_recv_req.o rpcs_fop.o tcp_server.o debug_after_read.o -o rpc_server

server.o : server.c req_struct.h reply_struct.h rpc_recv_req.h 
	gcc -g -c server.c 

rpc_recv_req.o : rpc_recv_req.c rpcs_fop.h 
	gcc -g -c rpc_recv_req.c 

rpcs_fop.o : rpcs_fop.c  req_struct.h reply_struct.h
	gcc -g -c rpcs_fop.c 

tcp_server.o : tcp_server.c req_struct.h reply_struct.h
	gcc -g -c tcp_server.c 

debug_after_read.o : debug_after_read.c
	gcc -g -c debug_after_read.c

clean : 
	
	rm -rf *.o
	rm -rf rpc_server
