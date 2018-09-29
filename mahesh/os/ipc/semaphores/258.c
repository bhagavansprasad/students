#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
main()
{
	int semid,nsemset,nsem,flag,key;
	nsem = 1;
	flag = 0666|IPC_CREAT;
	for(nsemset=0;;nsemset++)
	{
		key = (key_t)nsemset;
		semid = semget(nsemset,nsem,flag);
		if(semid > 0)
			printf("\ncreated semaphore eith id : %d\n",semid);
		else
		{
			printf("max num of semaphores set are : %d\n",nsemset);
			exit(0);
		}
	}
}
