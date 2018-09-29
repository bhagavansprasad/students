#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

main()
{
	int semcpy, semcon, pid, val, i ;
	struct sembuf sop[2];

	semcpy = semget( 0x20 , 1 , IPC_CREAT|0666);
	semcon= semget( 0x30 , 1 , IPC_CREAT|0666);
	sop[0].sem_num = 0;
	sop[0].sem_op = 0;
	sop[0].sem_flg = SEM_UNDO;

	sop[1].sem_num = 0;
	sop[1].sem_op = 1;
	sop[1].sem_flg = SEM_UNDO;
	semop(semcon ,&sop[0],2);


	val = semctl(semcpy , 0, GETVAL , 0);
	printf(" value of semaphore 1st time ->%d \n",val);

	if(val > 2)
	{


		printf("sorry only three copies created \n");
		exit(0);
	}
	else
	{
		sop[0].sem_num = 0;
		sop[0].sem_op = 1;
		sop[0].sem_flg = SEM_UNDO;
		semop(semcpy ,&sop[0],1);



		sop[0].sem_num = 0;
		sop[0].sem_op = -1;
		sop[0].sem_flg = SEM_UNDO;
		semop(semcon ,&sop[0],1);


		printf(" Application program start \n");
		sleep(5);
		printf(" Application program finishes \n");

	}
}
