a.out: main.o ins-ele.o del-ele.o ordr-inst.o
	gcc main.o ins-ele.o del-ele.o ordr-inst.o

main.o: main.c
	gcc main.c -c

ins-ele.o: ins-ele.c
	gcc ins_ele.c -c

del-ele.o: del-ele.c
	gcc del-ele.c -c

ordr-inst.o: ordr-inst.c
	gcc ordr-inst.c -c

clean:
	rm -rf *.o
	rm -rf a.out

