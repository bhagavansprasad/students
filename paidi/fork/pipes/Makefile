2pipe : main.o server.o client.o 
	gcc  main.o server.o client.o -o 2pipe
main.o: main.c 
	gcc  main.c  -c
server.o: server.c  header.h
	gcc server.c  -c
client.o: client.c  header.h
	gcc client.c   -c



remove :
	rm -rf 2pipe
	rm -rf *.o

