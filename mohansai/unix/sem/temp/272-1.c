#include "stdio.h"
#include "stdlib.h"
#include "sys/ipc.h"
#include "sys/sem.h"
#include "sys/types.h"

int nsec;
int acquire_sem(int semid)
{
	int retval;
	while(1)
	{
		printf("-->%d: Checking Resouce availability\r\n", getpid() );
		retval = semctl(semid, 0, GETVAL, 0);
		printf("-->%d : Resource avialability value :%d\r\n", getpid(), retval);
		if (retval == 1)
		{
			semctl(semid, 0, SETVAL, 0);	
			return 0;
		}
		printf("-->%d: Resource is not available going for sleep for %d seconds\r\n", getpid(),nsec);
		sleep(1);
	}
}

int release_sem(int semid)
{
	semctl(semid, 0, SETVAL, 1);	
}

main(int argc, char *argv[])
{
	int semid, i; 
	nsec = atoi(argv[1]);

	semid = semget((key_t)0x25, 1, IPC_CREAT | 0666);
	
    semctl(semid, 0, SETVAL, 1);
	while(1)
	{
		printf("-->%d : Checking Resouce availability\r\n", getpid());

		acquire_sem(semid);

		printf("-->%d: resource is available\r\n", getpid());
		printf("-->%d: Locking the resouce\r\n", getpid());
		printf("-->%d: Locking success\r\n", getpid());
		printf("-->%d: Entering into critical section\r\n", getpid());
		for(i = 0; i < 10; i++)
		{
			printf("-->%d: In critical section\r\n", getpid());
			sleep(nsec);
		}
		printf("-->%d: Out of critical section\r\n", getpid());
		printf("-->%d: Releasing resource\r\n", getpid());

		release_sem(semid);

		printf("-->%d: Released resource\r\n", getpid());
		printf("-->%d: Going for sleep for 1 sec\r\n", getpid());
		sleep(nsec);
	}

}

