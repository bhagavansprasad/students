ovdc : m.o ovd.o ovc.o
	gcc m.o ovd.o ovc.o -o ovdc

m.o : m.c
	gcc -g m.c -c

ovd.o : ovd.c
	gcc -g ovd.c - c

ovc.o : ovc.c
	gcc -g ovc.c - c

clean :
	rm -rf  *.o
	rm -rf ovdc
