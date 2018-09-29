#include "stdio.h"
#include "sys/ipc.h"
#include "sys/shm.h"
#include "stdlib.h"

main()
{
	int shmid,i;
	key_t key = i;

	for(i=0; ;i++)
	{	
		shmid = shmget( i, 100 ,IPC_CREAT | 0666);
		
		if(shmid<0)
		{
			perror("error in creating 1st semaphore");
			exit(1);
		}
		
		else
		printf("sucess shmid is 1st %d %d \n", shmid , i);
	}

}
