#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
main()
{
	int shmid;
	key_t i;
	for(i=1;;i++)
	{
		if(shmid=shmget(i,1,IPC_CREAT|0666)<0)
		{
			printf("maxium number of sm segments%d\n",i);
			break;
		}
		shmctl(shmid,IPC_RMID,0);
	}
}
