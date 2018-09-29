ovdc : ovdc.o ovd.o ovc.o
	gcc ovdc.o ovd.o ovc.o  -o ovdc
ovdc.o:ovdc.c
	gcc ovdc.c -c -g
ovd.o:ovd.c ovdc.h
	gcc ovd.c -c -g
ovc.o:ovc.c ovdc.h
	gcc ovc.c -c
clean:
	rm -rf ovdc
	rm -rf *.o

