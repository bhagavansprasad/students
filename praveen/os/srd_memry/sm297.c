#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
main()
{
	int shmid;
	key_t i;
	for(i = 1;;i++)
	{
		shmid = shmget(i,1,IPC_CREAT|0666);
		if(shmid <0)
		{
			printf("max no of sm segments %d\n",i);
			break;
			
		}
		//shmctl(shmid,IPC_RMID,0);
	}
}
		
