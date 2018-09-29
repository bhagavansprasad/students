#include "stdio.h"
#include "sys/ipc.h"
#include "sys/shm.h"
#include "sys/types.h"
#include "stdlib.h"
main()
{
	int shmid,i;
	char *ptr;
	for(i=0 ; ; i++)
	{
		shmid=shmget( (key_t)i+1 , 524588 , IPC_CREAT | 0666);
		if(shmid<0)
		{
			perror("error in creating the shared memory");
			exit(1);
		}
	
		ptr = (char*)shmat(shmid,0,0);
		printf("ptr  %u\n",ptr);
	}

}

