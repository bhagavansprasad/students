cli_ser:  server.o file_print.o sys_fop.o file_db.o
	gcc server.o file_print.o sys_fop.o file_db.o -o  cli_ser

server.o:server.c
	gcc server.c -c

file_print.o :file_print.c 
	gcc file_print.c -c

sys_fop.o:sys_fop.c
	gcc sys_fop.c -c

file_db.o:file_db.c
	gcc file_db.c -c
clean:
	rm -rf cli_ser
	rm -rf *.o


