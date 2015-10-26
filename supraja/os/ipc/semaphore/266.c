#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <errno.h>
main()
{
	int semid,retval;
	semid=semget(0x20,1,0666|IPC_CREAT);
	retval=semctl(semid,0,GETVAL,0);
	printf("value returned is %d\n",retval);
}

