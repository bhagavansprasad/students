s: main.o  mainfirst.o rpcs_fop.o
	gcc main.o mainfirst.o rpcs_fop.o -o s

main.o:main.c structc.h structs.h
	gcc main.c -c

mainfirst.o:mainfirst.c structc.h structs.h
	gcc mainfirst.c -c

rpcs_fop.o:rpcs_fop.c structc.h enume.h
	gcc rpcs_fop.c -c

fact.o:fact.c
	gcc fact.c -c
clean:
	rm *.o
	rm s
