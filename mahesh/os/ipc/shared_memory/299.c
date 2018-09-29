#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
main()
{
	int i,shmid;
	for(i=0;;i++)
	{
		shmid = shmget((key_t)i+1,32768,IPC_CREAT|0666);
		if(shmid < 0)
		{
			printf("maximum no of blocks : %d\n",i);
			exit(0);
		}
	}
}
