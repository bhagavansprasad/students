#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

main()
{
	int i,shmid;
	for(i=1;;i++)
	{
		shmid = shmget((key_t)i+1,524288,IPC_CREAT|0666);
		if(shmid>0)
		{
			printf("max no of blocks : %d\n",i);
			exit(1);
		}
	}
}
