#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>

main()
{
	int semid , pid ,retval;

	struct sembuf sop;

	semid = semget( 0x20 , 1 , 0600|IPC_CREAT);
	printf("the semid %d\n",semid);

	pid = fork();
	if(pid == 0)
	{
		sleep(2);
		printf("child before semop \n");
		sop.sem_num = 0;
		sop.sem_op = 0;
		sop.sem_flg = 0;
		retval = semop(semid , &sop , 1);
		printf("semop returned ->%d\n", retval);
		printf("child over \n");
	}
	else
	{
		printf(" parents before 1st semctl \n");
		semctl(semid , 0 , SETVAL ,1);
		printf("parent  sleepng \n");
		sleep(5);
		printf("parent before 2nd semctl \n");
		semctl(semid , 0 , SETVAL ,0);
		printf("parent  over \n");

	}
}
