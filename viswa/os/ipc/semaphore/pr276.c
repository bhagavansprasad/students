#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

main()
{
	int semid , pid , val, ctr ;
	struct sembuf sop;

	semid = semget( 0x20 , 1 , IPC_CREAT|0666);
	semctl(semid , 0, SETVAL , 0);

	pid = fork();

	if(pid == 0)
	{
		sleep(2);
		printf(" child before semop ;\n");
		sop.sem_num = 0;
		sop.sem_op = -3;
		sop.sem_flg = 0;
		semop( semid , &sop , 4);
		printf("child over;\n");
	}
	else
	{
		for( ctr = 1 ; ; ctr++)
		{
			printf("ctr is-> %d\n", ctr);
			semctl(semid , 0 , SETVAL , ctr);
			printf("parent sleeping \n");
			sleep(5);
			val = semctl(semid , 0 ,GETVAL , 0);
			printf("semctl returned val->%d\n",val);
			if( val == 0)
				break;
		}
		printf("parent over \n");
	}

}
