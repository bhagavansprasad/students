#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>

int main()
{
	int semid;
	int retval=0;
	struct sembuf sop;

	sop.sem_num = 0;
	sop.sem_op = 0;
	sop.sem_flg = 0;

	semid = semget(0x15, 1, 0600 | IPC_CREAT);
	printf("semid : %d \n", semid);
	printf("Before semop\n");

	retval = semop(semid, &sop, 1);

	printf("semop returned %d\n", retval);

	return 0;

}
