#include <sys/sem.h>

struct sembuf sop;

void sem_acquire(int semid)
{
	sop.sem_num = 0;
	sop.sem_op = 0;
	sop.sem_flg = 0;
	semop(semid, &sop, 1);
	semctl(semid, 0, SETVAL, 1);
}

void sem_release(int semid)
{
	semctl(semid, 0, SETVAL, 0);
}
