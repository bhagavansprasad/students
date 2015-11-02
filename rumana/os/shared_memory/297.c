#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
main()
{
	int shmid;
	key_t i;
	for(i=1;;i++)
	{
		if((shmid=shmget(i,1,IPC_CREAT|0666))<0)
		{
			printf("maximum number of sm segment %d\n",i);
			break;
		}
	}

}
