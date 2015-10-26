#include "stdio.h"
#include "sys/types.h"
#include "sys/ipc.h"
#include "sys/sem.h"
main()
{
	int pid,semid;
	struct sembuf sop;
	semid = semget((key_t)20,1,IPC_CREAT|0666);
	pid=fork();
	if(pid==0)
	{
		sleep(2);
		printf("child before semop\n");
		
		sop.sem_num=0;
		sop.sem_op=0;
		sop.sem_flg=0;

		semop(semid,&sop,1);
		printf("child over\n");
	}
	else
	{
		printf("parent before 1st semctl\n");
		semctl(semid,0,SETVAL,1);
		printf("parretn sleeping\n");
		sleep(2);
		printf("parent before 2nd semctl \n");
		semctl(semid,0,SETVAL,1);
		printf("parent over\n");
	}
}

