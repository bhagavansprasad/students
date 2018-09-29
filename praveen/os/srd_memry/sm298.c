#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
main()
{
	int shmid;
	long i;
	for(i = 1024;;i += 1024)
	{
		shmid = shmget(1,i,IPC_CREAT|0666);
		if(shmid < 0)
		{
			i = i-1024;
			i = i/1024;
			printf("max sm's size is in kb is %d\n ",i);
			exit(0);
		}
			printf("shmid is %d\n",shmid);
			shmctl(shmid,IPC_RMID,0);

		
	}
}
