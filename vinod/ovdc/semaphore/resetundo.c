#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>

int main()
{
	int semid, val, pid;
	struct sembuf sop;
	semid = semget(0x15, 1, 0666 | IPC_CREAT);
	semctl(semid, 0 , SETVAL , 1);
	sop.sem_num = 0;
	sop.sem_op = -1;
	sop.sem_flg = SEM_UNDO;

	pid = fork();

	if(pid == 0)
	{
		printf("Child before semop\n");
		semop(semid, &sop , 1);
		printf("child in critical section\n");
		sleep(1);
		printf("Child coming out of critical section\n");
	}
	else
	{
		printf("parent before semop\n");
		semop(semid, &sop , 1);
		printf("parent in critical section\n");
		sleep(1);
		printf("PARENT coming out of critical section\n");
	}
	return 0;

}
