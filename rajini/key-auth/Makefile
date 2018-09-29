s : lib.o sender.o receiver.o dump.o
	gcc -g lib.o sender.o -o s
	gcc -g lib.o receiver.o -o r
	gcc -g lib.o dump.o -o d

lib.o: lib.c terminal.h
	gcc -g -c lib.c

sender.o: sender.c terminal.h
	gcc -g -c sender.c

receiver.o: receiver.c terminal.h
	gcc -g -c receiver.c

dump.o: dump.c terminal.h
	gcc -g -c dump.c
clean:
	rm -rf s r d *.o
