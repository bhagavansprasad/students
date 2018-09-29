freebuffer:freebuffer5.o add_free_pool.o mem_alloc_free.o thread.o
	gcc -lpthread -g freebuffer5.o add_free_pool.o mem_alloc_free.o thread.o -o freebuffer

freebuffer5.o :freebuffer5.c
	gcc freebuffer5.c -c  -g

add_free_pool.o:add_free_pool.c
	gcc add_free_pool.c -c -g

mem_alloc_free.o:mem_alloc_free.c
	gcc mem_alloc_free.c -c -g

thread.o:thread.c
	gcc thread.c -c -g

clean:
	rm -rf freebuffer
	rm -rf *.o
