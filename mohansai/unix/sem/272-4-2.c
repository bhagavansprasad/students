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

	while(1)
	{
		printf("I am p2 trying to get the resource\r\n");
		get_semctl = semctl(semid, 0, GETVAL, 0);
		if(get_semctl == 1)
		{
			set_semctl = semctl(semid, 0, SETVAL, 0 );
			printf("I am p2 got the resource\r\n");

			for(i=0; i<15; i++)
			{
				printf("i am p2 process using resource\r\n");
				fflush(stdout);
				sleep(1);
			}

			printf("i am p2 releasing the resource\r\n");
			get_semctl = semctl(semid, 0, SETVAL, 1);
		}
		printf("I am p2 resource not available \r\n");
		sleep(1);
	}
}



