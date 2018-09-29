c : main.o afop.o rpcc.o rpcc_send.o tcp_client.o  
	gcc -g  main.o afop.o rpcc.o rpcc_send.o tcp_client.o -o c

main.o : main.c afop.h
	gcc -g -c main.c

afop.o : afop.c rpcc.h
	gcc -g -c afop.c

rpcc.o : rpcc.c struct_req.h struct_rply.h rpcc_send_req.h
	gcc -g -c rpcc.c
	
rpcc_send.o : rpcc_send.c struct_req.h struct_rply.h
	gcc -g -c rpcc_send.c

tcp_client.o: tcp_client.c struct_rply.h rpcc_send_req.h
	gcc -g -c tcp_client.c

clean : 
	rm -rf c
	rm -rf *.o
