#include <sys/types.h>
#include <sys/ipc.h>
main()
{
	int semid,key,flag,nsem,j,i;
	flag=IPC_CREAT|0666;
	nsem=25;
	for(j=0;j<10;j++)
	{
		key=(key_t)(j+1);
		semid=semget(key,nsem,flag);
		if(semid>0)
			printf("created semaphore with id:%d\n",semid);
		else
		{
			for(i=0;;i++)
			{
				nsem=i+1;
				semid=semget(key,nsem,flag);
				if(semid>0)
					printf("created semaphore with id:%d\n",semid);
				else
				{
					printf("max no of semaphore in UNIX system are %d\n",(i+j*25));
					exit(0);
				}
				semctl(semid,0,IPC_RMID,0);
			}
		}
	}
}
