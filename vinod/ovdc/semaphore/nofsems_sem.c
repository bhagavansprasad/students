#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main()
{
	int semid=0;
	int i=0;
	key_t k;
	int nsems=1;
	int flag = IPC_CREAT | 0666;

	for(i=0 ;; i++)
	{
		k = i;
		if((semid = semget(k, nsems, flag)) > 0)
			printf("Created semaphore with ID : %d\n", semid);
		else
		{
			perror("--> Error in creating semaphore : ");
			printf("Maximum no of semaphores set : %d\n", i);
			exit(1);
		}

	}
	return 0;
}
