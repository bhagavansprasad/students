#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main()
{
	int semid=0;
	key_t k=0x85;
	int nsems=200;
	int flag = IPC_CREAT | 0666;

	if((semid = semget(k, nsems, flag)) < 0)
	{
		perror("--> Error in creating semaphore : ");
		exit(1);
	}

	printf(" semid : %d\n", semid);

//	semctl(semid, 0, IPC_RMID);

	return 0;
}
