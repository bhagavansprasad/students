s: main.o  mainfirst.o rpcs_fop.o
	gcc main.o mainfirst.o rpcs_fop.o -o s

main.o:main.c strc.h struct.h
	gcc main.c -c

mainfirst.o:mainfirst.c strc.h struct.h 
	gcc mainfirst.c -c

rpcs_fop.o:rpcs_fop.c strc.h enum.h
	gcc rpcs_fop.c -c

clean:
	rm *.o
	rm s
