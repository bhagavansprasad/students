a.out : la.o ks.o hm.o an.o
	gcc la.o ks.o hm.o an.o
la.o : la.c op.h
	gcc la.c -c
ks.o : ks.c op.h
	gcc ks.c -c
hm.o : hm.c op.h structdefs.h union.h
	gcc hm.c -C
an.o : an.c op.h structdefs.h union.h
	gcc an.c -c
clean : 
	rm -rf a.out
	rm -rf *.o
