Warnings:= -Wall -Werror
Debug:= -g
Remove:= rm -rf
mmm: mmm.o test.o 
	gcc $(Debug) $(Warnings) mmm.o test.o -pthread  -o mmm 
mmm.o: mmm.c 
	gcc -c $(Debug) $(Warnings) mmm.c 
test.o: test.c
	gcc -c $(Debug) $(Warnings) test.c
clean:
	$(Remove) *.o
	$(Remove) mmm
