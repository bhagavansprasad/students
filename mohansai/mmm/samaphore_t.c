void acquire_semaphore(int semid)
{ 
	sop.sem_num = 0;
	sop.sem_op  = -1;
	sop.sem_flg = 0 ;
	semop(semid, &sop, 1);

}


void release_semaphore(int semid)
{
	semctl(semid, 0, SETVAL, 1);
}




