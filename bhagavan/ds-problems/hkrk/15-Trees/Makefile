CFLAGS := -Wall -Werror -g
btree: btree.o tree_traversal.o  stack.o
	gcc -o btree $(CFLAGS) btree.o tree_traversal.o stack.o

btree.o:  btree.c defs.h
	gcc -c $(CFLAGS) btree.c

tree_traversal.o: tree_traversal.c defs.h
	gcc -c $(CFLAGS) tree_traversal.c 

stack.o: stack.c defs.h
	gcc -c $(CFLAGS) stack.c

clean:
	rm -rf btree
	rm -rf *.o
