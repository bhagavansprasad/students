Warnings:= -Wall -Werror
Debug:= -g
Remove:= -rf rm
VPATH = /home/bhagavan/students/sudharshan/nrpc/inc/

rpc: switchs.o comm_init.o rs.o afop.o 
	 gcc $(Debug) $(Warnings) switchs.o comm_init.o rs.o afop.o -o rpc

switchs.o: switchs.c define.h switchs.h 
	 gcc $(Debug) $(Warnings)  -c switchs.c 

comm_init.o: comm_init.c
	 gcc $(Debug) $(Warnings) -c comm_init.c

rs.o: rs.c comm_init.h define.h 
	 gcc $(Debug) $(Warnings) -c rs.c 

afop.o: afop.c
	gcc $(Debug) $(Warnings) -c afop.c

clean:
	rm -rf  *.o
	rm -rf  rpc
