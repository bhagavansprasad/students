#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

main()
{
	int semid , pid,val ;
	struct sembuf sop;

	semid = semget( 0x20 , 1 , IPC_CREAT|0666);
	semctl(semid , 0, SETVAL , 3);
	val = semctl(semid , 0, GETVAL , 0);
	printf(" value of semaphore 1st time ->%d \n",val);
	pid  = fork();

	if(pid == 0)
	{

		printf(" child before semop with -2 \n");
		sop.sem_num = 0;
		sop.sem_op = 2;
		sop.sem_flg = SEM_UNDO;
		semop( semid , &sop , 1);
		printf("child  in critical section\n");
		sleep(2);
		printf("child  coming out of critical section\n");
	}
	else
	{
		sleep(1);
		val = semctl(semid , 0, GETVAL , 0);
		printf(" value of semaphore 2nd time ->%d \n",val);
		sleep(5);
		val = semctl(semid , 0, GETVAL , 0);
		printf(" value of semaphore 3rd time ->%d \n",val);

	}
}
