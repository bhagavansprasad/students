upnp: uconfig.o udp_client.o connection.o  
	gcc uconfig.o udp_client.o connection.o -o upnp

udp_client.o: udp_client.c udp.h
	gcc -c udp_client.c -g

uconfig.o: uconfig.c uconfig.h
	gcc -c uconfig.c -g

connection.o: connection.c
	gcc -c connection.c -g 


clean:
	rm -rf *.o
	rm -rf cxmpp
