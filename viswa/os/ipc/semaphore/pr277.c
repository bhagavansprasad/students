#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

main()
{
	int semid , pid , val ;
	struct sembuf sop;

	semid = semget( 0x20 , 1 , IPC_CREAT);
	semctl(semid , 0, SETVAL , 5);
	printf(" the value of semaphore value is 5\n");
	printf(" before semop going with -3\n");

	sop.sem_num = 0;
	sop.sem_op = -3;
	sop.sem_flg = 0;
	semop( semid , &sop , 1);
	val = semctl(semid , 0 ,GETVAL , 0);
	printf("semctl returned val->%d\n",val);

}
