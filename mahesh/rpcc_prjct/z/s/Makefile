s:  main.o server_read_req.o fop.o tcpserver.o debug.o
	gcc -g main.o server_read_req.o fop.o tcpserver.o debug.o -o s

main.o: main.c struct.h
	gcc -g -c main.c

server_read_req.o:server_read_req.c struct.h rpcs.h structrep.h
	gcc -g -c server_read_req.c

fop.o:fop.c struct.h rpcs.h
	gcc -g -c fop.c

tcpserver.o: tcpserver.c struct.h structrep.h
	gcc -g -c tcpserver.c

debug.o: debug.c struct.h structrep.h
	gcc -g -c debug.c

clean:
	rm -rf s
	rm -rf *.o
