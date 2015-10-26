a.out:astrncat.o len_s.o
	gcc astrncat.o len_s.o
astrncat.o:astrncat.c
	gcc astrncat.c -c
len_s.o:len_s.c
	gcc len_s.c -c
