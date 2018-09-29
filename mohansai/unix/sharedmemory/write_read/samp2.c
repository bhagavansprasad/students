#include "stdio.h"
#include "sys/ipc.h"
#include "sys/types.h"
#include "sys/shm.h"
#include "stdlib.h"
#define SIZE 1024
main()
{
	char *ptr;
	int shmid,pid;

	shmid = shmget((key_t)1,SIZE,IPC_CREAT|0666);
	if(shmid<0)
	{
		perror("error in open a file");
		exit(1);
	}
	ptr=(char*)shmat(shmid,(char*)0,0);

	pid = fork();
	if (pid == 0)
	{
		read(0 ,ptr,SIZE);
	}
	else
	{
		wait(0);
		
			printf("parent starts reading from shared memory and out putting to	screen \n");
			write(1,ptr,SIZE);
		
	}
}









