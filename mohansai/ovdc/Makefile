ovdc:main.o ovc.o ovd.o
	gcc main.o ovc.o ovd.o  -o ovdc

main.o:main.c
	gcc main.c -c

ovc.o:ovc.c
	gcc ovc.c -c

ovd.o:ovd.c
	gcc ovd.c -c

clean:
	rm -rf ovdc
	rm -rf *.o
