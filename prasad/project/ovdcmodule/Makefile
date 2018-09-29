#FLAGS=-DDEBUG
ovdc:main.o ovd.o ovc.o war_sus_kill.o 
	gcc $(FLAGS) main.o ovd.o ovc.o war_sus_kill.o -o ovdc

main.o:main.c
	gcc $(FLAGS) -c main.c

ovd.o:ovd.c
	gcc $(FLAGS) -c ovd.c

ovc.o:ovc.c
	gcc $(FLAGS) -c ovc.c

war_sus_kill.o:war_sus_kill.c
	gcc $(FLAGS) -c war_sus_kill.c

clean:
	rm -rf *.o
	rm -rf ovdc
