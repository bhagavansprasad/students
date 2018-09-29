#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
main()
{
	int semid,retval;
	semid = semget(0x20,1,0666|IPC_CREAT);
	retval = semctl(semid,0,GETPID,0);
	printf("returned pid is : %d\t actual pid is : %d\n",retval,getpid());
	retval = semctl(semid,0,SETVAL,1);
}
