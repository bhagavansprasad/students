#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>


main()
{
	int semid;

	semid = semget( 0x20, 25 , 0666|IPC_CREAT);

	if( semid > 0)
		printf(" 1st semget suceeded \n");
	else
	{
		perror("1st semgget failed :");
		exit(0);
	}

	semid = semget( 0x30, 25 , 0666|IPC_CREAT);

	if( semid > 0)
		printf(" 2nd semget suceeded \n");
	else
	{
		perror("2nd semgget failed :");
		exit(0);
	}
	semid = semget( 0x40, 25 , 0666|IPC_CREAT);

	if( semid > 0)
		printf(" 3rd semget suceeded \n");
	else
	{
		perror("3rd semgget failed :");
		exit(0);
	}
	semid = semget( 0x50, 25 , 0666|IPC_CREAT);

	if( semid > 0)
		printf(" 4th semget suceeded \n");
	else
	{
		perror("4th semgget failed :");
		exit(0);
	}

}
