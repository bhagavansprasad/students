s:main.o server_connection.o rpcs_fop.o fact.o linkedlist.o
	gcc main.o server_connection.o rpcs_fop.o fact.o linkedlist.o -o s

main.o:main.c struct_client.h struct_server.h
	gcc main.c -c

server_connection.o:server_connection.c struct_client.h struct_server.h
	gcc server_connection.c -c

rpcs_fop.o: rpcs_fop.c struct_client.h enume.h
	gcc  rpcs_fop.c -c

fact.o:fact.c
	gcc fact.c -c

linkedlist.o:linkedlist.c
	gcc linkedlist.c -c

clean:
	rm *.o
	rm s
