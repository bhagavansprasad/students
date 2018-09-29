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
	semctl(semid, 0 , SETVAL , 3);
	val = semctl(semid, 0 , GETVAL , 0);
	printf("value of semaphore 1st time is %d : \n", val );
	
	pid = fork();

	if(pid == 0)
	{
		printf("Child doing semop with 2\n");
		sop.sem_num = 0;
		sop.sem_op = 2;
		sop.sem_flg = SEM_UNDO;
		semop(semid, &sop , 1);
		printf("child in critical section\n");
		sleep(5);
		printf("Child coming out of critical section\n");
	}
	else
	{
		sleep(1);
		val = semctl(semid, 0 , GETVAL , 0);
		printf("value of semaphore 2nd time is %d : \n", val);
		sleep(5);
		val = semctl(semid, 0 , GETVAL, 0);
		printf("value of semaphore 3 rd time is : %d\n", val);
	}
	return 0;

}
