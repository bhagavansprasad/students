#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>

main()
{
	int semid;
	semid = semget(0x20,25,0666|IPC_CREAT);
	if(semid>0)
	{
		printf("1st semapore success\n");
	}
	else
	{
		perror("1st semapore failed");
		exit(1);
	}
	semid = semget(0x30,35,0666|IPC_CREAT);
	if(semid>0)
	{
		printf("2st semapore success\n");
	}
	else
	{
		perror("2st semapore failed");
		exit(1);
	}

	semid = semget(0x40,45,0666|IPC_CREAT);
	if(semid>0)
	{
		printf("3st semapore success\n");
	}
	else
	{
		perror("3st semapore failed");
		exit(1);
	}

	semid = semget(0x50,55,0666|IPC_CREAT);
	if(semid>0)
	{
		printf("4st semapore success\n");
	}
	else
	{
		perror("4st semapore failed");
		exit(1);
	}

}
