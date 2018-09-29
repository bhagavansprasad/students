server:m.o  librpcs.a
	gcc m.o  -L. -lrpcs -o server

librpcs.a: recv_rpc_req.o rpcs_fp.o tcp_server.o debug_af.o
	ar rcs librpcs.a recv_rpc_req.o rpcs_fp.o tcp_server.o debug_af.o

m.o:m.c
	gcc m.c -c

recv_rpc_req.o:recv_rpc_req.c rpc_req.h
	gcc recv_rpc_req.c -c

rpcs_fp.o:rpcs_fp.c rpc_req.h
	gcc rpcs_fp.c -c

tcp_server.o:tcp_server.c rpc_fp.h
	gcc tcp_server.c -c

debug_af.o:debug_af.c rpc_fp.h
	gcc debug_af.c -c

clean:
	rm -rf *.o
	rm -rf server
	rm -rf *.a
