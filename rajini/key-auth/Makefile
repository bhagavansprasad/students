s : lib.o sender.o receiver.o
	gcc -g lib.o sender.o -o s
	gcc -g lib.o receiver.o -o r

lib.o: lib.c terminal.h
	gcc -g -c lib.c

sender.o: sender.c terminal.h
	gcc -g -c sender.c

receiver.o: receiver.c terminal.h
	gcc -g -c receiver.c

clean:
	rm -rf s r *.o
