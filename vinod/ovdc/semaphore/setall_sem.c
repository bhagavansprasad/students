#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>

int main()
{
	int semid;
	key_t k = 0x22;
	int flag = IPC_CREAT | 0666 ;
	int retval;
	ushort val[5] = {10,20,30,40,50};

	semid = semget(k, 5, flag);

	printf("semid : %d\n", semid);
	
	semctl(semid, 0, SETALL, val);
	
	semctl(semid, 0, GETALL, val);

	printf("val0 : %d\nval1 : %d\nval2 : %d\nval3 : %d\nval4 : %d\n", val[0], val[1], val[2], val[3], val[4]);

	return 0;
}
