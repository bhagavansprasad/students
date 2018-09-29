hashlist: main.o addnode.o genkey.o
	gcc main.o addnode.o genkey.o -o hashlist

main.o: main.c structure.h
	gcc  main.c -c

addnode.o: addnode.c
	gcc addnode.c -c

genkey.o: genkey.c
	gcc genkey.c -c

clean:
	rm hashlist
	rm *.o
