a.out : main.o ovd.o ovc.o
	gcc main.o ovd.o ovc.o -o a.out

m.o : main.c
	gcc main.c -c

ovd.o : ovd.c
	gcc ovd.c -c

ovc.o : ovc.c
	gcc ovc.c -c

clean:
	rm -rf *.o
	rm -rf a.out
