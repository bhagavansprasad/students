a.out: main.o  rpcs_fop.o server_accept.o
	gcc main.o  rpcs_fop.o server_accept.o 

main.o: main.c server_accept.h server_structer.h structer.h
	gcc main.c -c

rpcs_fop.o: rpcs_fop.c server_structer.h structer.h
	gcc rpcs_fop.c -c

server_accept.o: server_accept.c structer.h server_structer.h
	gcc server_accept.c -c

clean:
	rm -rf *.o
	rm -rf a.out


