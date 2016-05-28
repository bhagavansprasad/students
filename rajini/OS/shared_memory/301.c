#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
main()
{
	int i,shmid;
	char *ptr;
	for(i=0;i<50;i++)
	{
		shmid = shmget((key_t)i+1,32768,IPC_CREAT|0666);
		if(shmid < 0)
		{
			printf("maximum no of blocks : %d\n",i);
			exit(0);
		}
		ptr = (char *)shmat(shmid,0,0);
		printf("ptr is : %u\n",ptr);
		shmctl(shmid,IPC_RMID,0);
	}
}
