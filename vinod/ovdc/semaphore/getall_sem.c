#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int semid;
	key_t k = 0x22;
	int flag = IPC_CREAT | 0666 ;
	int retval;
	ushort val[5];

	semid = semget(k, 5, flag);

	printf("semid : %d\n", semid);
	
	semctl(semid, 0, SETVAL, 1);
	semctl(semid, 1, SETVAL, 2);
	semctl(semid, 2, SETVAL, 3);
	semctl(semid, 3, SETVAL, 4);
	semctl(semid, 4, SETVAL, 5);
	
	retval = semctl(semid, 0, GETALL, val);

	printf("PID returned by semctl is : %d and actual pid is : %d\n", retval,
	getpid());
	
	printf("val0 : %d\nval1 : %d\nval2 : %d\nval3 : %d\nval4 : %d\n", val[0], val[1], val[2], val[3], val[4]);

	return 0;
}
