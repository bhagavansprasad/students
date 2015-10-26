#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <sys/sem.h>



main()
{
	int semid, retval;

	semid = semget(0x20 , 1,0666 |IPC_CREAT);
	retval = semctl(semid , 0 , GETPID,0);

	printf("PID returned by semctl is->%d and actual PID is->%d\n",retval,getpid());

	retval = semctl(semid , 0 , SETVAL,1);
}

