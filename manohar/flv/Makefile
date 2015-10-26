Debug:= -g
Warnings:= -Wall -Werror
Remove:= rm -rf
flv: copy.o 
	gcc $(Debug) $(Warings) copy.o -o flv
copy.o: copy.c 
	gcc $(Debug) $(Warings) copy.c -c -o copy.o
clean: 
	$(Remove) *.o
	$(Remove) flv
