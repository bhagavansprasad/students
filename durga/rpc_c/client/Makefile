a.out:main.o fop.o rpc_fun.o rpcs_fop.o rpc_send_req.o client_reqst.o
	gcc main.o fop.o rpc_fun.o rpcs_fop.o rpc_send_req.o client_reqst.o -o a.out

main.o:main.c fop.h rpc_c.h structer.h server_structer.h
	gcc main.c -c

fop.o:fop.c rpc_c.h structer.h server_structer.h
	gcc fop.c -c

rpc_fun.o:rpc_fun.c  structer.h server_structer.h
	gcc rpc_fun.c -c

rpcs_fop.o: rpcs_fop.c structer.h server_structer.h
	gcc rpcs_fop.c -c

rpc_send_req.o: rpc_send_req.c client_reqst.h structer.h server_structer.h
	gcc rpc_send_req.c -c

client_reqst.o:client_reqst.c structer.h server_structer.h
	gcc client_reqst.c -c

clean:
	rm -rf *.o
	rm -rf a.out
