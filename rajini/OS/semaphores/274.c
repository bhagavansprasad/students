#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
main()
{
	int semid,pid;
	struct sembuf sop;
	semid = semget(0x20,1,IPC_CREAT|0666);
	pid = fork();
	if(pid == 0)
	{
		sleep(2);
		printf("child before semop\n");
		sop.sem_num = 0;
		sop.sem_op = 0;
		sop.sem_flg = 0;
		printf("child over\n");
	}
	else
	{
		printf("parent before 1st semctl\n");
		semctl(semid,0,SETVAL,1);
		printf("parent sleeping\n");
		sleep(5);
		printf("parent before 2nd semctl\n");
		semctl(semid,0,SETVAL,0);
		printf("parent process over\n");
	}
}
