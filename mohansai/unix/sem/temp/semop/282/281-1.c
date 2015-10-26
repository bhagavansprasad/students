#include "stdio.h"
#include "stdlib.h"
#include "sys/ipc.h"
#include "sys/sem.h"
#include "sys/types.h"

struct sembuf sop;

main()
{
	int semid, i, retval; 

	semid = semget((key_t)0x25, 1, IPC_CREAT | 0666);

	semctl(semid,0,SETVAL,1);
	
	retval=semctl(semid,0,GETVAL,0);	
	while(1)
	{
		
		printf("P1 : Checking Resouce availability\r\n" );

		sop.sem_num=0;
		sop.sem_op=-2;
		sop.sem_flg=SEM_UNDO;
		semop(semid, &sop, 1);
		
		printf("P1 : resource is available\r\n");
		printf("P1 : Locking the resouce\r\n");
		printf("P1 : Locking success\r\n");
		printf("P1 : Entering into critical section\r\n");
		for(i = 0; i < 10; i++)
		{
			printf("P1: In critical section\r\n");
			sleep(1);
		}
		printf("P1 : Out of critical section\r\n");
		printf("P1 : Releasing resource\r\n");

		printf("P1 : Released resource\r\n");
		printf("P1: Going for sleep for 1 sec\r\n");
		
		sleep(1);
	}
}
