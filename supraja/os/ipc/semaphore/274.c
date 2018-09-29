#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
//int a=10;
//int b=20;
main()
{
int a=10;
int b=20;
	int semid,pid,i;
	struct sembuf sop;
	semid=semget(0x20,1,IPC_CREAT|0666);
	pid=fork();
	if(pid==0)
	{
		sleep(5);
		printf("child before semop\n");
		sop.sem_num=0;
		sop.sem_op=0;
		sop.sem_flg=0;
		semop(semid,&sop,1);
		for(i=0;i<10;i++)
		{
			printf("%d\n",a);
		}
		printf("child over\n");
	}
	else
	{
		printf("parent before 1st semctl\n");
		semctl(semid,0,SETVAL,1);
		printf("parent sleeping\n");
		sleep(3);
		printf("parent before 2nd semctl\n");
		semctl(semid,0,SETVAL,0);
		for(i=0;i<10;i++)
		{
			printf("%d\n",b);
		}
		printf("parent over\n");
	}
}
