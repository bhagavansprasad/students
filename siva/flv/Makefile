flv:flv_parser.o fun.o
	gcc flv_parser.o fun.o -o flv

flv_parser.o:flv_parser.c
	gcc flv_parser.c -c 

fun.o:fun.c
	gcc fun.c -c

clean:
	rm -rf flv
	rm -rf *.o
