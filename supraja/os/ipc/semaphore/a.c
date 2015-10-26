#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/sem.h>
#include <errno.h>
int a=10;
int b=20;
main()
{
	int semid,key,flag,nsem,pid,i,retval;
	key=(key_t)0x20;
	//semid=semget(key,nsem,IPC_CREAT|0666);
	//printf("created semaphore with ID:%d\n",semid);
	pid=fork();
	if(pid==0)
	{
	semid=semget(key,1,0666|IPC_CREAT);
     retval=semctl(semid,0,GETVAL,0);
	// semctl(semid,0,SETVAL,1);
	// retval=semctl(semid,0,GETVAL,0);
		printf("iam in child");
		for(i=0;i<10;i++)
		{
			printf("%d\n",a);
			sleep(1);
	 semctl(semid,0,SETVAL,1);
	 retval=semctl(semid,0,GETVAL,0);
		}
	 //semctl(semid,0,SETVAL,1);
	 //retval=semctl(semid,0,GETVAL,0);
			//sleep(1);
	}
	else
	{
		printf("iam in parent");
		for(i=0;i<10;i++)
		{
			printf("%d\n",b);
			sleep(1);
	 semctl(semid,0,SETVAL,1);
	 retval=semctl(semid,0,GETVAL,0);
		}
	 //semctl(semid,0,SETVAL,1);
	 //retval=semctl(semid,0,GETVAL,0);
			//sleep(1);
	}
}

