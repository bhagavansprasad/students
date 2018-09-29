ovdc.out: ovdc.o ovd.o ovc.o funs.o defs.h
	gcc ovdc.c ovd.c ovc.c funs.c -o ovdc.out -g
ovdc.o:	ovd.c ovc.c defs.h
	gcc -c ovd.c ovc.c
ovd.o:	ovd.c funs.c defs.h
	gcc -c ovdc.c funs.c
ovc.o:	ovc.c funs.c defs.h
	gcc -c ovc.c funs.c
funs.o:	funs.c defs.h
	gcc -c funs.c
