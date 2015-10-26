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

	semid = semget(k, 3, flag);
	
	semctl(semid, 2, SETVAL, 1);

	retval = semctl(semid, 2, GETVAL, 0);

	printf("Value returned : %d\n", retval);

	return 0;
}
