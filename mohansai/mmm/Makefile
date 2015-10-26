
mmm:doc.o get_hash_key.o thread_fun.o samaphore_t.o
	gcc -lpthread -g doc.o get_hash_key.o thread_fun.o samaphore_t.o -o mmm  

doc.o:doc.c
	gcc doc.c -g -c

get_hash_key.o:get_hash_key.c
	gcc get_hash_key.c -g -c


thread_fun.o:thread_fun.c
	gcc thread_fun.c -g -c

samaphore_t.o:samaphore_t.c
	gcc samaphore_t.c -g -c

clean:
	rm -rf mmm
	rm -rf *.o
