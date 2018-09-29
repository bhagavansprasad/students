#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

main()
{
	int semid , pid,val ;
	struct sembuf sop;

	semid = semget( 0x20 , 1 , IPC_CREAT|0666);
		sop.sem_num = 0;
		sop.sem_op = 1;
		sop.sem_flg = SEM_UNDO;

	val = semctl(semid , 0, GETVAL , 0);
	printf(" value of semaphore 1st time ->%d \n",val);

	if(val > 2)
	{

		printf("sorry only three copies created \n");
		exit(0);
	}
	else
	{
		 semop(semid ,&sop,1);
		printf(" Application program start \n");
		sleep(5);
		printf(" Application program finishes \n");

	}
}
