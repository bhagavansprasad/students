s : main.o rpcs_recv.o rpcs_fop.o tcp_server.o single_linked_list.o 
	gcc -g main.o rpcs_recv.o rpcs_fop.o tcp_server.o single_linked_list.o -o s

main.o : main.c struct_req.h struct_rply.h
	gcc -g -c main.c

rpcs_recv.o : rpcs_recv.c struct_req.h struct_rply.h
	gcc -g -c rpcs_recv.c

rpcs_fop.o : rpcs_fop.c struct_req.h struct_rply.h
	gcc -g -c rpcs_fop.c

single_linked_list.o : single_linked_list.c 
	gcc -g -c single_linked_list.c

tcp_server.o:tcp_server.c struct_req.h struct_rply.h
	gcc -g -c tcp_server.c

clean : 
	rm -rf s 
	rm -rf *.o
