#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
main()
{
	int semid,key,nsem,flag,nsemset;
	flag=0666|IPC_CREAT;
	nsem=1;
	for(nsemset=0;;nsemset++)
	{
		key=(key_t)nsemset;
		semid=semget(nsemset,nsem,flag);
		if(semid>0)
			printf("\ncreated semaphore with ID:%d\n",semid);
		else
		{
			printf("maximum number of semaphore set are %d\n",nsemset);
			exit(0);
		}
	}
}
