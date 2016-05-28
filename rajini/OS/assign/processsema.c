#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int semid, val, set_semctl, get_semctl, i=0,j=0;

int acquire_sem()
{
	semid = semget((key_t)0x23, 1,IPC_CREAT|0666);
	if(semid<0)
	{
		perror("error in creating semget\r\n");
		exit(1);
	}

	set_semctl = semctl(semid, 0, SETVAL, 1 );
    
	while(1)
	{
		printf("I am parent trying to get the resource\r\n");
		get_semctl = semctl(semid, 0, GETVAL, 0);
		if(get_semctl == 1)
		{
			set_semctl = semctl(semid, 0, SETVAL, 0 );
			printf("I am parent got the resource\r\n");
			return 0;
		}
		printf("I am parent resource not available\r\n");
		sleep(1);
	}

}

int release_sem()
{
	semid = semget((key_t)0x23, 1,IPC_CREAT|0666);
	if(semid<0)
	{
		perror("error in creating semget\r\n");
		exit(1);
	}


    while(1)
	{
		printf("I am child trying to get the resource\r\n");
		get_semctl = semctl(semid, 0, GETVAL, 0);
		if(get_semctl == 1)
		{
			set_semctl = semctl(semid, 0, SETVAL, 0 );
			printf("I am child got the resource\r\n");
			return 0;
		}
		printf("I am child resource not available\r\n");
		sleep(1);
	}

}
int parent(void)
{
	acquire_sem();
	for (i = 0; i <= 10; i++)
	{  
		printf("Parent: %d\n", i);
		fflush(stdout);
		sleep(1);
	}
	printf("i am parent releasing the resource\r\n");
	get_semctl = semctl(semid, 0, SETVAL, 1);

	release_sem();
}

int child(void)
{
	acquire_sem();
	for (j = 0; j <= 10; j++)
	{  
		printf("Child: %d\n", j);
		fflush(stdout);
		sleep(1);
	}
	
	printf("i am child releasing the resource\r\n");
	get_semctl = semctl(semid, 0, SETVAL, 1);

	release_sem();
}

int main()
{
	int pid;
	pid = fork();

	if(pid == 0)
	{  
		while(1)
		{
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
