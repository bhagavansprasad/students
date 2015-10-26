c: client.o afop.o rpcc.o rpcc_send_req.o tcpclient.o debug.o
	gcc -g client.o afop.o rpcc.o rpcc_send_req.o tcpclient.o debug.o -o c

client.o: client.c afop_defs.h
	gcc -g -c client.c 

afop.o: afop.c rpcc.h
	gcc -g -c afop.c

rpcc.o: rpcc.c  struct.h rpcc_send_req.h structrep.h
	gcc -g -c rpcc.c

rpcc_send_req.o: rpcc_send_req.c struct.h
	gcc -g -c rpcc_send_req.c

tcpclient.o: tcpclient.c struct.h structrep.h
	gcc -g -c tcpclient.c

debug.o: debug.c struct.h
	gcc -g -c debug.c

clean:
	rm -rf c
	rm -rf *.o
