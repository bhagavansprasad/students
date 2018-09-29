#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/sem.h>
main()
{
	int semid,key,flag,nsem,j,i;
	for(i=0;i<2;i++)
	{
		key=(key_t)0x30;
		flag=IPC_CREAT|0666|IPC_EXCL;
		nsem=1;
		semid=semget(key,nsem,flag);
		if(semid>0)
			printf("created semaphore with id :%d\n",semid);
		else
			perror("semget");
	}
}

