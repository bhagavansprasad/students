a.out : main.o afop.o rpcc.o rpcc_send.o rpcs_recv.o rpcs_fop.o 
	gcc -g  main.o afop.o rpcc.o rpcc_send.o rpcs_recv.o rpcs_fop.o -o a.out
main.o : main.c afop.h
	gcc -g  main.c -c
afop.o : afop.c rpcc.h
	gcc -g  afop.c -c
rpcc.o : rpcc.c struct_req.h struct_rply.h rpcc_send_req.h
	gcc -g  rpcc.c -c
rpcc_send.o : rpcc_send.c struct_req.h struct_rply.h
	gcc -g  rpcc_send.c -c
rpcs_recv.o : rpcs_recv.c struct_req.h struct_rply.h
	gcc -g  rpcs_recv.c -c
rpcs_fop.o : rpcs_fop.c struct_req.h struct_rply.h
	gcc -g  rpcs_fop.c -c

