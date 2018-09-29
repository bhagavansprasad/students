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
	printf("pid returned by semctl is %d and actual pid is :%d\n",retval,getpid());
}
