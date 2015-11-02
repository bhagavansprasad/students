a.out:flv.o flv_par.o
	gcc flv.o flv_par.o

flv.o:flv.c flv.h
	gcc -c flv.c

flv_par.o:flv_par.c flv.h
	gcc -c flv_par.c

clean:
	rm -rf *.o
	rm -rf a.out
