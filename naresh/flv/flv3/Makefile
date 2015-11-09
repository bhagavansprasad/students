a.out:flv.o flv_head.o
	gcc flv.o flv_head.o

flv.o:flv.c flv.h
	gcc -c flv.c

flv_head.o:flv_head.c flv.h
	gcc -c flv_head.c

flv_tag.o:flv_tag.c flv.h
	gcc -c flv_tag.c

clean:
	rm -rf *.o
	rm -rf a.out
