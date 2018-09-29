#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
	int semid,key,flag,nsem,j,i;
	semid=semget(0x20,25,0666|IPC_CREAT);
	if(semid>0)
		printf("1st segment success\n");
	else
	{
		perror("1st semget");
		exit(0);
	}
	semid=semget(0x30,25,0666|IPC_CREAT);
	if(semget>0)
		printf("2nd segment success\n");
	else
	{
		perror("2nd semget");
		exit(0);
	}
	semid=semget(0x40,10,0666|IPC_CREAT);
	if(semget>0)
		printf("3rd segment success\n");
	else
	{
		perror("3rd semget");
		exit(0);
	}
	semid=semget(0x50,1,0666|IPC_CREAT);
	if(semget>0)
		printf("4th segment success\n");
	else
	{
		perror("4th semget");
		exit(0);
	}

}

