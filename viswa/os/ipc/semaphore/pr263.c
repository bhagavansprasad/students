#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>


main()
{
	int semid, nsem , key , flag;

	flag = IPC_CREAT |0600 ;
	nsem = 1;

	key = (key_t)0x120;
	nsem = 2;

	semid = semget(key , nsem, flag);

	if( semid > 0)
		printf("created semaphore with ID :%d\n", semid);
	else
		perror(" 1st semget:");

	nsem  = 1;
	semid = semget(key , nsem, flag);

	if( semid > 0)
		printf("created semaphore with ID :%d\n", semid);
	else
		perror(" 2nd semget:");


	nsem  = 4;
	semid = semget(key , nsem, flag);

	if( semid > 0)
		printf("created semaphore with ID :%d\n", semid);
	else
		perror(" 3rd semget:");




}

