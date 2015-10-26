c1:main.o fop.o rpcc.o  rpc_fop.o rpc_send_req.o mainfirst.o 
	gcc main.o fop.o rpcc.o rpc_fop.o rpc_send_req.o mainfirst.o -o c1

main.o:main.c fop.h 
	gcc main.c -c

afop.o:fop.c rpcc.h
	gcc fop.c -c

rpcc.o:rpcc.c strc.h struct.h enum.h
	gcc rpcc.c -c

rpc_fop.o:rpc_fop.c strc.h
	gcc rpc_fop.c -c

rpc_send_req.o:rpc_send_req.c strc.h
	gcc rpc_send_req.c -c

mainfirst.o:mainfirst.c
	gcc mainfirst.c -c

clean:
	rm *.o
	rm c1
