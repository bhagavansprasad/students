client: main.o fop.o rpcc.o rpcc_fop.o rpcc_net_comm.o 
	gcc main.o fop.o rpcc.o rpcc_fop.o rpcc_net_comm.o -o c

main.o:main.c fop.h 
	gcc main.c -c

fop.o:fop.c rpcc.h
	gcc fop.c -c

rpcc.o:rpcc.c struct_client.h rpcc_fop.h 
	gcc rpcc.c -c

rpcc_fop.o:rpcc_fop.c struct_client.h
	gcc rpcc_fop.c -c

rpcc_net_comm.o:rpcc_net_comm.c
	gcc rpcc_net_comm.c -c

clean:
	rm -rf *.o
	rm -rf client
