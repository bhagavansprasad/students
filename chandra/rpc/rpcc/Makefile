CFLAGS := -g
#CFLAGS += -Wall
#CFLAGS += Werror

rpc_client : client.o fop.o rpcc_fop.o rpc_send_req.o tcp_client.o debug_before_write.o
	gcc $(CFLAGS) client.o fop.o rpcc_fop.o rpc_send_req.o tcp_client.o debug_before_write.o -o rpc_client

client.o : client.c fop.h 
	gcc $(CFLAGS) -c client.c 

fop.o : fop.c rpcc_fop.h
	gcc $(CFLAGS) -c fop.c 

rpcc_fop.o : rpcc_fop.c req_struct.h reply_struct.h rpc_send_req.h
	gcc $(CFLAGS) -c rpcc_fop.c 

rpc_send_req.o : rpc_send_req.c 
	gcc $(CFLAGS) -c rpc_send_req.c 

tcp_client.o : tcp_client.c
	gcc  $(CFLAGS) -c tcp_client.c 

debug_before_write.o : debug_before_write.c req_struct.h
	gcc $(CFLAGS) -c debug_before_write.c 

clean :
	
	rm -rf *.o
	rm -rf rpc_client

