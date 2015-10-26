#include "stdio.h"
#include "stdlib.h"
#include "sys/ipc.h"
#include "sys/types.h"
#include "sys/sem.h"
main()
{
	int semid,retval;
	struct sembuf sop;
	sop.sem_num  = 0;
	sop.sem_op   = 0;
	sop.sem_flg = 0;
	
	semid=semget((key_t)0x20,1,IPC_CREAT|0666);
	
	retval=semctl(semid,0,GETVAL,0);
	printf("semval  %d \n", retval);
	printf("before semop\n");
	retval =  semop(semid, &sop, 0);
	printf("semop returned %d \n", retval);
	retval=semctl(semid,0,GETVAL,0);
	printf("semval  %d \n", retval);
}

