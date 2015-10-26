#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>

main()
{
	int semid , retval;

	struct sembuf sop;
	sop.sem_num = 0;
	sop.sem_op = 0;
	sop.sem_flg = 0;
	
	semid = semget( 0x20 , 1 , 0600|IPC_CREAT);
	printf("the semid %d\n",semid);
	printf("before semop \n");

	retval = semop(semid , &sop , 1);

	printf("semop returned ->%d\n", retval);
}
