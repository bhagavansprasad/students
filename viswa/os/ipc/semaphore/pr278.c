#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

main()
{
	int semid , pid , val ;
	struct sembuf sop;

	semid = semget( 0x20 , 1 , IPC_CREAT|0666);
	semctl(semid , 0, SETVAL , 0);
	printf(" the value of semaphore value is 0\n");
	printf(" before semop going with -3\n");

	sop.sem_num = 0;
	sop.sem_op = -3;
	sop.sem_flg = IPC_NOWAIT;
	semop( semid , &sop , 1);
	printf("process exiting\n");

}
