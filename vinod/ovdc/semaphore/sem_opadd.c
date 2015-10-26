#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>

int main()
{
	int semid, pid, val;
	struct sembuf sop;
	semid = semget(0x15, 1, 0600 | IPC_CREAT);

	pid = fork();

	if(pid == 0)
	{
		sleep(2);
		printf("Child before semop\n");
		sop.sem_num = 0;
		sop.sem_op = 3;
		sop.sem_flg = 0;
		semop(semid, &sop, 1);
		printf("Child over\n");
	}
	else
	{
		printf("parent before 1st semctl\n");
		semctl(semid, 0, SETVAL	,2);
		printf("parent sleeping\n");
		sleep(5);
		printf("parent before 2nd semctl\n");
		val = semctl(semid, 0, GETVAL , 0);
		printf("semaphore val is %d \n", val);
		printf("PARENT OVER\n");

	}
	return 0;

	}
