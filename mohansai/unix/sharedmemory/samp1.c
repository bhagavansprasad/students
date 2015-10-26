#include "stdio.h"
#include "sys/ipc.h"
#include "sys/shm.h"
#include "stdlib.h"

main()
{
	int shmid,flag;
	key_t key = 0x10;

	shmid = shmget( key , 100 ,IPC_CREAT | 0666);
	if(shmid<0)
	{
		perror("error in creating 1st semaphore");
		exit(1);
	}
	else
		printf("sucess shmid is 1st %d \n", shmid);

	shmid = shmget( key , 101 ,IPC_CREAT | 0666);
	if(shmid<0)
	{
		perror("error in creating 2nd  semaphore");
		exit(1);
	}
	else
		printf("sucess shmid 2ndis  %d \n", shmid);

	shmid = shmget( key , 102 , IPC_CREAT | 0666);
	
	if(shmid<0)
	{
		perror("error in creating 3rd  semaphore");
		exit(1);
	}
	else 
		printf("sucess shmid 3rd is  %d \n", shmid);

}

