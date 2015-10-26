#include "stdio.h"
#include "sys/types.h"
#include "sys/ipc.h"
#include "sys/sem.h"
#include "stdlib.h"
main()
{
	int semid,get_semctl;
	semid = semget((key_t)0x20, 1, IPC_CREAT|0666);
	while(1)	
	{
		get_semctl = semctl(semid, 0 ,GETVAL, 0);
		printf("get_semctl--> %d\r\n",get_semctl);

		if(get_semctl==5)
		{	
			semctl(semid, 0, SETVAL, 10);
			break;
		}
		sleep(10);
	}

	get_semctl = semctl(semid, 0 ,GETVAL, 0);
	printf("get_semctl--> %d\r\n",get_semctl);
}

