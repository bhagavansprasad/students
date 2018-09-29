#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "sys/ipc.h"
#include "sys/sem.h"

main()
{
	int semid, val, set_semctl, get_semctl, i=0;
	
	semid = semget((key_t)0x23, 1,IPC_CREAT|0666);
	if(semid<0)
	{
		perror("error in creating semget\r\n");
		exit(1);
	}

	set_semctl = semctl(semid, 0, SETVAL, 1 );

	while(1)
	{
		printf("I am p1 trying to get the resource\r\n");
		get_semctl = semctl(semid, 0, GETVAL, 0);
		if(get_semctl == 1)
		{
			set_semctl = semctl(semid, 0, SETVAL, 0 );
			printf("I am p1 got the resource\r\n");
			for(i=0; i<10; i++)
			{
				printf("i am p1 process using resource\r\n");
				sleep(1);
			}
			printf("i am p1 releasing the resource\r\n");
			get_semctl = semctl(semid, 0, SETVAL, 1);
		}
		printf("I am p1 resource not available\r\n");
		sleep(1);
	}
}



