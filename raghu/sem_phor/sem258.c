#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>

main()
{
	int semid,nsemset,nsem,flag,key;
	nsem = 1;
	flag = 0666|IPC_CREAT;
	for(nsemset = 0;;nsemset++)
	{
		key = (key_t)nsemset;
		semid = semget(nsemset,nsem,flag);
		if(semid>0)
			printf("created semaphore with id : %d\n",semid);
		else
		{
			printf("max no of semaphore set are %d\n",nsemset);
			exit(0);
		}
	}
}
