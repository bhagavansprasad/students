#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
main()
{
	int semid,retval;
	semid = semget(0x21,1,0666|IPC_CREAT);
	semctl(semid,0,SETVAL,1);
	retval = semctl(semid,0,GETVAL,0);
	printf("value of the semaphore after setting is : %d\n",retval);
	semctl(semid,0,SETVAL,2);
	retval = semctl(semid,0,GETVAL,0);
	printf("value of the semaphore after setting is : %d\n",retval);
}
