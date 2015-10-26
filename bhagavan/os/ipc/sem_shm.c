#include <sys/ipc.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <stdio.h>
#include <string.h>

int create_semaphore(int key,int nsem)
{
	int flag = IPC_CREAT|0666;
	int semid = semget(key, nsem, flag);

	if(semid == -1)
	{
		perror("semaphore is not created\n");
		exit(0);
	}

	printf("Success: Semaphore created key :%d, num_sems :%d, semid :%d\n", key, nsem, semid);

	return semid;
}

void * create_sharedmemory(int key, int size)
{
	int shmid = shmget(key, size, IPC_CREAT|0666);
	void *shmptr = NULL;

	if(shmid<0)
	{
		perror("Error in creating shared memory");
		exit(0);
	}

	printf("Success: Shared memory is created key :%d, size :%d, shmid :%d\n", key, size, shmid);

	shmptr = (char *)shmat(shmid, NULL, 0);

	if (shmptr == (void *)-1)
	{
		perror("Error in attaching shared memory");
		exit(0);
	}

	printf("Success: Attaching memory ptr :%p\n", shmptr);

	return shmptr;
}

void acquire_semaphore(int semid)
{
	struct sembuf sop;
	int retval=0;

	sop.sem_num=0;
	sop.sem_op=1;
	sop.sem_flg=0;

	retval = semop(semid, &sop, 1);
}

int release_semaphore(int semid)
{
	struct sembuf sop;
	int retval = 0;

	sop.sem_num = 0;
	sop.sem_op  = 1;
	sop.sem_flg = 0;

	retval = semop(semid, &sop, 1);

	return 0;
}

main(int argc, char *argv[])
{
	int shm_key = 333, sem_key = 222, size = 100, nsem = 1, retval = 0;
	char msg[] = "aura networks";
	int shmid, sem_id = 0;
	char *shmptr = NULL;
	int nsec = 0;

	if (argv < 2)
	{
		printf("In sufficient arguments\n");
		printf("Usage : ./a.out <sec>\n");
		exit(1);
	}

	nsec = atoi(argv[1]);

	shmptr = create_sharedmemory(shm_key, size);
	sem_id = create_semaphore(sem_key, nsem);

	printf("\n");
	for(;;)
	{
		printf("-->process :%d, entering to critical section\n", getpid());
		acquire_semaphore(sem_id);

		printf("-->process :%d, IN CRITICAL SECTION\n", getpid());

		sleep(nsec);

		printf("-->process :%d, FNINISHED CRITICAL SECTION\n", getpid());
		printf("-->process :%d, RELEASING SEMAPHORE\n", getpid());
		retval = release_semaphore(sem_id);

		printf("-->process :%d, RELEASED SEMAPHORE\n\n", getpid());

		sleep(nsec);
	}

}
