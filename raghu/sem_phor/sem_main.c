#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

main()
{
	int shmid1,shmid2;
	char *ptr1;
	char *ptr2;
	int semid,retval;
	int i;
	
	shmid1 = shmget((key_t)10,50,IPC_CREAT|0666);
	ptr1 = shmat(shmid1,0,0);

	semid = semget(0x20,1,IPC_CREAT|0666);

	semctl(semid,0,SETVAL,1);
	while(1)
	{
		printf("checking resource availability\n");
		retval = semctl(semid,0,GETVAL,0);
		if(retval == 1)
		{
			printf("resource is available \n");
			semctl(semid,0,SETVAL,0);
			printf("process in critical\n");
			
			
			for(i=0;i<50;i++)
			{
				printf("%d.message from the 2nd process %s \n",i+1,ptr1);
				sleep(1);
			}

			strcpy(ptr1,"A");	
			
			printf("process out of critical \n");
			semctl(semid,0,SETVAL,1);
			printf("resource is released\n");
			printf("\n");
			sleep(2);
		}
		else
		{
			printf("resource is not available \n");
			sleep(2);
		}
	}
	shctl(shmid1,IPC_RMID,0);
	shctl(shmid2,IPC_RMID,0);
}
