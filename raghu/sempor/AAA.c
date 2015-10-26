#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

main()
{
	int shmid1,shmid2,i;
	int semid;
	char *ptr1,*ptr2;
	struct sembuf sop;

	shmid1 = shmget((key_t)10,60,IPC_CREAT|0666);
	shmid2 = shmget((key_t)11,60,IPC_CREAT|0666);
	if(shmid1 < 0 || shmid2 < 0)
	{
		perror("shmget failed");
		exit(0);
	}
	
	ptr1 = shmat(shmid1,0,0);
	ptr2 = shmat(shmid2,0,0);
	
	semid= semget((key_t)10,1,IPC_CREAT|0666);
	if(semid < 0)
	{
		printf("semget failed");
		exit(0);
	}
	
	if(semctl(semid,1,SETALL,0)== -1)
	{
		perror("semctl failed");
		exit(0);
	}
	
	sop = 
	


	strcpy(ptr1,"A");
	
	for(i=0;i<10;i++)	
	printf("%d.%s\t",i+1,ptr2);
	printf("\n");
}
