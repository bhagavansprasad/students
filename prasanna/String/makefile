str: str_lib.o str_test.o
	gcc -o str str_lib.o str_test.o
str_lib.o:str_lib.c
	gcc -c str_lib.c
str_test.o:str_test.c
	gcc -c str_test.c
clean:
	rm -rf *.o
	rm -rf str
