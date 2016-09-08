#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
main()
{
	int semid,pid,val;
	struct sembuf sop;
	semid = semget(0x20,1,IPC_CREAT|0666);
	pid = fork();
	if(pid == 0)
	{
		sleep(2);
		printf("child before semop\n");
		sop.sem_num =0;
		sop.sem_op =3;
		sop.sem_flg =0;
		semop(semid,&sop,1);
		printf("child over\n");
	}
	else
	{
		printf("parent before 1st semctl\n");
		semctl(semid,0,SETVAL,2);
		printf("parent sleeping\n");
		sleep(5);
		printf("parent before 2nd semctl\n");
		val = semctl(semid,0,GETVAL,0);
		printf("semaphore value is : %d\n",val);
		printf("parent over\n");
	}
}
