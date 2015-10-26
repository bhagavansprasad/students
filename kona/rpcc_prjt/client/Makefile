c:main.o afop.o rpcc.o  rpc_fop.o rpc_send_req.o client_connection.o 
	gcc main.o afop.o rpcc.o rpc_fop.o rpc_send_req.o client_connection.o -o c

main.o:main.c afop.h 
	gcc main.c -c

afop.o:afop.c rpcc.h
	gcc afop.c -c

rpcc.o:rpcc.c struct_client.h struct_server.h enume.h 
	gcc rpcc.c -c

rpc_fop.o:rpc_fop.c struct_client.h
	gcc rpc_fop.c -c

rpc_send_req.o:rpc_send_req.c struct_client.h
	gcc rpc_send_req.c -c

client_connection.o:client_connection.c
	gcc client_connection.c -c

clean:
	rm *.o
	rm c
