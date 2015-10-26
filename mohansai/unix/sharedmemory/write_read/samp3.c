#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "sys/ipc.h"
#include "sys/shm.h"
#include "struct.h"
#define MAX 1024
main()
{
	struct databuff *ptr;

	int shmid,pid;

	shmid = semget((key_t)10124,MAX , IPC_CREAT|0666);
	if(shmid<0)
	{
		perror("error in creating the shared memory");
		exit(1);
	}
	
	ptr=(struct databuff*) shmat(shmid,(char*)0,0);
	
	pid=fork();
	if(pid==0)
		ptr->read=read(0,ptr->buff,MAX);
	else
	{

		wait(0);
		write(1,ptr->buff,ptr->read);
	}
}

