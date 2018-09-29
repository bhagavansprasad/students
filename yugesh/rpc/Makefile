a.out: afop.o filecpy.o
	gcc afop.o filecpy.o -o a.out
afop.o: afop.c fop.h
	gcc -c afop.c
filecpy.o: filecpy.c
	gcc -c filecpy.c

clean:
	rm -rf a.out
	rm -rf *.o
