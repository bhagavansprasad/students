a.out : main.o  afun.o recv.o rpcfop.c rpcfun.o send.o 
		gcc main.o  afun.o recv.o rpcfop.o rpcfun.o send.o  

<<<<<<< m.mk
main.o : main.c afun.h
	gcc -c main.c -o main.o
=======
main.o : main.c  afun.h
		gcc -c main.c -o main.o
>>>>>>> 1.2

<<<<<<< m.mk
afun.o : afun.c rpcfun.h
	gcc -c afun.c -o afun.o
=======
afun.o : afun.c rpcfun.h
		gcc -c afun.c -o afun.o
>>>>>>> 1.2

<<<<<<< m.mk
rpcfun.o : rpcfun.c rpcfop.h
	gcc -c rpcfun.c -o rpcfun.o

rpcfop.o : rpcfop.c sendreq.h
	gcc -c rpcfop.c -o rpcfop.o
=======
rpcfun.o : rpcfun.c rpcfop.h
		gcc -c rpcfun.c -o rpcfun.o

rpcfop.o : rpcfop.c send.h
		gcc -c rpcfop.c -o rpcfop.o

send.o : send.c recv.h
		gcc -c send.c -o send.o
	
recv.o : recv.c
		gcc -c recv.c -o recv.o
>>>>>>> 1.2

<<<<<<< m.mk
send.o : send.c recvreq.h
	gcc -c send.c -o send.o
=======

>>>>>>> 1.2

recv.o : recv.c
	gcc -c recv.c -o recv.o

