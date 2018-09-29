#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

main()
{
	int semid , pid ;
	struct sembuf sop;

	semid = semget( 0x20 , 1 , IPC_CREAT|0666);
	semctl(semid , 0, SETVAL , 1);
	sop.sem_num = 0;
	sop.sem_op = -1;
	sop.sem_flg = SEM_UNDO;

	pid  = fork();

	if(pid == 0)
	{

		printf(" child before semop \n");

		semop( semid , &sop , 1);
		printf("child  in critical section\n");
		sleep(2);
		printf("child  coming out of critical section\n");
	}
	else
	{
		printf(" parent before semop \n");

		semop( semid , &sop , 1);
		printf("parent in critical section\n");
		sleep(2);
		printf("parent coming out of critical section \n");

	}
}
