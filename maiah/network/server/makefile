a.out:main.o server_comm.o
	gcc main.o server_comm.o
main.o:main.c server_client.h
	gcc main.c -c
server_comm.o:server_comm.c
	gcc server_comm.c -c
clean:
	rm *.o
	rm a.out
