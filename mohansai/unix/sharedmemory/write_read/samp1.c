#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "sys/types.h"
#include "sys/ipc.h"
#include "sys/shm.h"

main()
{
	char *ptr;
	int shmid,pid;

	shmid = shmget((key_t)1,20,IPC_CREAT|0666);
	if (shmid<0)
	{
		perror("error in creating the file");
		exit(1);
	}

	ptr = (char*)shmat(shmid,(char*)0,0);

	pid=fork();

	if(pid==0)
		strcpy(ptr,"hellow aura");
	else
	{
		wait(0);
		printf("parent reads --> %s \n ",ptr);
	}
}

