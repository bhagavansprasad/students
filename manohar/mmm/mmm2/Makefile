Warnings:= -Wall -Werror
Debug:= -g
Heads:= -lrt 
Heads+= -lpthread 
Remove:= rm -rf
mmm: mmm.o test.o 
	gcc $(Debug) $(Warnings) mmm.o test.o $(Heads) -o mmm
mmm.o:	mmm.c mmm.h mem_req.h
	gcc $(Debug) $(Warnings) -c mmm.c
test.o:	test.c mmm.h mem_req.h
	gcc $(Debug) $(Warnings) -c test.c
clean:
	$(Remove) *.o
	$(Remove) mmm

