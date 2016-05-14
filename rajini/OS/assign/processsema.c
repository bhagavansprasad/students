#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int i,j;
struct sembuf sop;
int acquire_sem()
{
    int semid;
	semid = semget(0x20, 1, IPC_CREAT|0666);
	semctl(semid, 0,SETVAL,1);
	sleep(5);
}

int release_sem()
{
    int semid;
	sop.sem_num=0;
	sop.sem_op=0;
	sop.sem_flg=0;
	semop(semid,&sop,1);
}

int parent(void)
{
	acquire_sem();
	for (i = 0; i <= 10; i++)
	{  
		printf("Parent: %d\n", i);
	}
	release_sem();
}


int child(void)
{
	acquire_sem();
	for (j = 0; j <= 10; j++)
	{  
		printf("Child: %d\n", j);
	}
	release_sem();
}


main()
{
	int pid;
	pid = fork();

	if(pid == 0)
	{  
		while(1)
		{
		    sleep(2);
			child();
     		sleep(2);
		}
	}
	else
	{
		while(1)
		{
			parent();
			sleep(2);
		}
	}
}
