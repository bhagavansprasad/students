#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int semid;
	key_t k = 0x25;
	int flag = IPC_CREAT | 0666 ;
	int retval;

	semid = semget(k, 1, flag);

	printf("semid : %d\n", semid);
	
	retval = semctl(semid, 0, GETPID, 0);

	printf("PID returned by semctl is : %d and actual pid is : %d\n", retval,
	getpid());
	
	semctl(semid, 0, SETVAL, 1);

	return 0;
}
