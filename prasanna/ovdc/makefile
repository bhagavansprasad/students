Ovdc:ovdc_main.o ovd.o ovc.o
	gcc -o Ovdc ovd.o ovc.o ovdc_main.o
ovd.o:ovd.c
	gcc -c ovd.c
ovc.o:ovc.c
	gcc -c ovc.c
ovdc_main.o:ovdc_main.c
	gcc -c ovdc_main.c
clean:
	rm -rf *.o
	rm -rf Ovdc


