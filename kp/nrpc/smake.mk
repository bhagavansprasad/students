Warnings:= -Wall -Werror
Debug:= -g
remove:= rm -rf

rpc: aura_openc.o comm_oper.o crpc.o comm_init.o 
	 gcc $(Debug) $(Warnings) aura_openc.o comm_oper.o crpc.o comm_init.o -o rpc

aura_openc.o:  aura_openc.c define.h 
	 gcc $(Debug) $(Warnings) -c aura_openc.c 

comm_oper.o: comm_oper.c
	 gcc $(Debug) $(Warnings) -c comm_oper.c

crpc.o: crpc.c comm_init.h aura_openc.h define.h comm_oper.h
	 gcc $(Debug) $(Warnings) -c crpc.c 

comm_init.o: comm_init.c    
	gcc $(Debug) $(Warnings) -c comm_init.c

clean:
	rm -rf  *.o
	rm -rf rpc
