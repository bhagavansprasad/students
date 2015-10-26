#include "stdio.h"
#include "stdlib.h"
#include "sys/ipc.h"
#include "sys/sem.h"
#include "sys/types.h"

int acquire(int semid)
{
	int retval;
	retval = semctl(semid, 0, GETVAL, 0 );
	if(retval == 1)
	{
		semctl(semid, 0, SETVAL, 0 );
		return 0;
	}
	sleep(1);
}

int release(int semid)
{
	semctl(semid, 0, SETVAL, 1 );
}

main()
{
	int semid, i, set_semctl, get_semctl;
	int retval;

	semid = semget((key_t)0x25, 1, IPC_CREAT | 0666);

	while(1)
	{
		acquire(semid);

		printf("P2 : Checking Resouce availability\r\n" );
		printf("P2 : Resource avialability value :%d\r\n", retval);
		printf("P2 : resource is available\r\n");
		printf("P2 : Locking the resouce\r\n");

		//set_semctl = semctl(semid,0 , SETVAL,0);	


		printf("P2 : Locking success\r\n");
		printf("P2 : Entering into critical section\r\n");
		for(i = 0; i < 10; i++)
		{
			printf("P2: In critical section\r\n");
			sleep(1);
		}
		printf("P2 : Out of critical section\r\n");
		printf("P2 : Releasing resource\r\n");

		release(semid);
		//set_semctl = semctl(semid,0,SETVAL,1);	

		printf("P2 : Released resource\r\n");
		printf("P2: Going for sleep for 1 sec\r\n");
		sleep(1);
	}

}
