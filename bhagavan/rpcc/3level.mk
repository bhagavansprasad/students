rpcc:client3.o afop3.o rpcc.o rpcc_request.o
	gcc -g client3.o afop3.o rpcc.o rpcc_request.o -o rpcc

client3.o: client3.c afop3.h struct.h
	gcc -g -c client3.c 

afop3.o: afop3.c afop3.h struct.h
	gcc -g -c afop3.c

rpcc.o: rpcc.c afop3.h struct.h
	gcc -g -c rpcc.c

rpcc_request.o: rpcc_request.c afop3.h struct.h
	gcc -g -c rpcc_request.c

clean:
	rm -rf rpcc
	rm -rf *.o
