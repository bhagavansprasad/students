Warnings:= -Wall -Werror
Debug:=  -g
Remove:= rm -rf
ovdc:	main.o ovc.o ovd.o 
		gcc $(Debug) $(Warnings) main.o ovc.o ovd.o -o ovdc
main.o: main.c define.h
		gcc $(Debug) $(Warnings) -c main.c
ovc.o:  ovc.c define.h
		gcc $(Debug) $(Warnings) -c ovc.c
ovd.o:  ovd.c define.h
		gcc $(Debug) $(Warnings) -c ovd.c
clean: 
		$(Remove) *.o
		$(Remove) ovdc 

