a.out:m.o ovc.o ovd.o
	gcc m.o ovc.o ovd.o
m.o: m.c
	gcc -c m.c
ovd.o:ovd.c
	gcc -c ovd.c
ovc.o:ovc.c
	gcc -c ovc.c
clean:
	rm -rf a.out
	rm -rf *.o
