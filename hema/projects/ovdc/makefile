
CFLAGS:= -c
DEBUG_FLAGS := -g


ovdc:main.o getgiffs.o getfd.o wread.o nthword.o store.o
	gcc $(DEBUG_FLAGS) main.o getgiffs.o getfd.o wread.o nthword.o store.o -o ovdc 


main.o :main.c defs.h
	gcc $(CFLAGS) $(DEBUG_FLAGS) main.c

getgiffs.o :getgiffs.c defs.h
	gcc $(CFLAGS) $(DEBUG_FLAGS)  getgiffs.c

getfd.o :getfd.c defs.h
	gcc $(CFLAGS) $(DEBUG_FLAGS) getfd.c

wread.o :wread.c defs.h
	gcc $(CFLAGS) $(DEBUG_FLAGS) wread.c

nthword.o : nthword.c defs.h
	gcc $(CFLAGS) $(DEBUG_FLAGS) nthword.c

store.o : store.c defs.h
	gcc $(CFLAGS) $(DEBUG_FLAGS) store.c

clean:
	rm -rf *.o 
	rm -rf ovdc





