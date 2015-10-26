#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <sys/sem.h>



main()
{
	int semid, retval;

	semid = semget(0x10 , 1,0666 |IPC_CREAT);
	semctl(semid , 0 , SETVAL,1);
	retval = semctl(semid , 0 , GETVAL,0);

	printf("value returned :retval :->%d\n", retval);

	semctl(semid , 0 , SETVAL,2);
	retval = semctl(semid , 0 , GETVAL,0);
	printf("value returned :retval :->%d\n", retval);
}

