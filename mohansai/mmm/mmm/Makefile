#CFLAGS:=-Wall -Werror
CFLAGS:=
mmm:doc.o  thread_fun.o  
	gcc $(CFLAGS) -lpthread -g doc.o thread_fun.o -o mmm  

doc.o:doc.c
	gcc $(CFLAGS) doc.c -g -c


thread_fun.o:thread_fun.c
	gcc $(CFLAGS) thread_fun.c -g -c

clean:
	rm -rf mmm
	rm -rf *.o
