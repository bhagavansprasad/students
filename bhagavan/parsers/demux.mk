mux: flvdemux.o
	gcc -g flvdemux.o -o mux

flvdemux.o: flvdemux.c flvdemux.h types.h
	gcc -g -c flvdemux.c

clean: 
	rm -rf mux a.out
	rm -rf flvdemux.o
	rm -rf *.h264
	rm -rf *.aac
	rm -rf dts.txt

