#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
main()
{
	int shmid;
	long i;
	for(i=1024;;i+=1024)
	{
		shmid=shmget(1,i,IPC_CREAT|0666);
			if(shmid < 0)
			{
				i=i-1024;
				i=i/1024;
				printf("maxium shm size is in kb is %ld\n",i);
				exit(0);
			}
				printf("shmidis :%d\n",shmid);
				shmctl(shmid,IPC_RMID,0);
	}
}
