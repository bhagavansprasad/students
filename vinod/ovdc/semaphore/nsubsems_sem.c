#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main()
{
	int semid=0;
	int i=0;
	key_t k=0x15;
	int nsems=0;
	int flag = IPC_CREAT | 0666;

	for(i=0 ;; i++)
	{
		nsems = i+1;
		if((semid = semget(k, nsems, flag)) > 0)
			printf("Created semaphore with ID : %d\n", semid);
		else
		{
			perror("--> Error in creating semaphore : ");
			printf("Maximum no of semaphores in one(1) set : %d\n", i);
			exit(1);
		}
		
		semctl(semid, 0, IPC_RMID, 0);
	}
	return 0;
}
