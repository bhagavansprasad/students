a.out:main.o aopen.o rpcc_open.o rpcc_fope.o
	gcc main.o aopen.o rpcc_open.o rpcc_fope.o
main.o:main.c fop.h
	gcc main.c -c
aopen.o:aopen.c rpccfop.h
	gcc aopen.c -c
rpcc_open.o:rpcc_open.c rpccfop1.h struct.h
	gcc rpcc_open.c -c
rpcc_fope.o:rpcc_fope.c 
	gcc rpcc_fope.c -c
clean:
	rm -rf a.out
	rm -rf *.o

