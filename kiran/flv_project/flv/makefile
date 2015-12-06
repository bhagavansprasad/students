flv: flv.o flv_parse.o offset.o
	gcc flv.o flv_parse.o offset.o -o flv

flv.o: flv.c flv.h
	gcc flv.c -c

flv_parse.o: flv_parse.c 
	gcc flv_parse.c -c

offset.o: offset.c
	gcc offset.c -c
clean:
	rm *.o
	rm flv
