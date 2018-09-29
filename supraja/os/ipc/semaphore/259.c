#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
main()
{
	int semid,key,nsem,flag,i;
	key=(key_t)0x30;
	flag=IPC_CREAT|0666;
	for(i=0;;i++)
	{
	    nsem=i+1;
		semid=semget(key,nsem,flag);
		if(semid>0)
			printf("\ncreated semaphore with ID:%d\n",semid);
		else
		{
			printf("maximum number of semaphore set are %d\n",i);
			exit(0);
		}
		semctl(semid,0,IPC_RMID,0);
	}
}
