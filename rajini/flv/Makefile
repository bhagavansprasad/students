a.out:flv.o flv_par.o flv_tag.o
	gcc flv.o flv_par.o flv_tag.o

flv.o:flv.c defs.h
	gcc flv.c -c

flv_par.o:flv_par.c
	gcc flv_par.c -c

flv_tag.o:flv_tag.c
	gcc flv_tag.c -c

clean:
	rm -rf *.o
	rm -rf a.out
