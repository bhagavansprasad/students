a.out : m.o ovd.o ovc.o
	gcc m.o ovd.o ovc.o -o a.out

m.o :m.c
	gcc m.c -c

ovd.o :ovd.c
	gcc ovd.c -c

ovc.o :ovc.c
	gcc ovc.c -c

clean:
	rm -rf *.o
	rm -rf a.out
