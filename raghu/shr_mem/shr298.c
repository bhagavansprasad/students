#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

main()
{
	int shmid;
	long i;
	for(i = 1024;;i+=1024)
	{
		shmid = shmget(1,i,IPC_CREAT|0666);
		if(shmid<0)
		{
			i = i-1024;
			i = i/1024;
			printf("max shared memory size in kb is %d\n",i);
			printf("%d\n",shmid);
			shmctl(shmid,IPC_RMID,0);
		}
	}

}
