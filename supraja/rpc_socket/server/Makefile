s : srvr.o rpcs_rec_req.o rpcs_fop.o tcp_server.o debug_after_read.o
	gcc -g  srvr.o  rpcs_rec_req.o rpcs_fop.o tcp_server.o debug_after_read.o -o s

srvr.o : srvr.c struct_replay.h struct_req.h rpcs_send_req.h srvr.h 
	gcc -g -c srvr.c

rpcs_rec_req.o : rpcs_rec_req.c
	gcc -g -c rpcs_rec_req.c

rpcs_fop.o : rpcs_fop.c struct_req.h struct_replay.h
	gcc -g -c rpcs_fop.c

tcp_server.o:tcp_server.c  struct_req.h struct_replay.h
	gcc -g -c tcp_server.c

debug_after_read.o:debug_after_read.c
	gcc -g -c debug_after_read.c

clean : 
	rm -rf s
	rm -rf *.o
