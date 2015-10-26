c:main.o afop.o rpcc.o  rpc_fop.o rpc_send_req.o mainfirst.o 
	gcc main.o afop.o rpcc.o rpc_fop.o rpc_send_req.o mainfirst.o -o c

main.o:main.c afop.h 
	gcc main.c -c

afop.o:afop.c rpcc.h
	gcc afop.c -c

rpcc.o:rpcc.c structc.h structs.h enume.h 
	gcc rpcc.c -c

rpc_fop.o:rpc_fop.c structc.h
	gcc rpc_fop.c -c

rpc_send_req.o:rpc_send_req.c structc.h
	gcc rpc_send_req.c -c

mainfirst.o:mainfirst.c
	gcc mainfirst.c -c

clean:
	rm *.o
	rm c
