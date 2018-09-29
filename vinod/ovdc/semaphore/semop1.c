#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>

int main()
{
	int semid;
	int val=1;

	semid = semget(0x15, 1, 0666 | IPC_CREAT);
	printf("semid : %d \n", semid);

	semctl(semid, 0, SETVAL, val);

	return 0;

}
