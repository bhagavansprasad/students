#include "sem.h"
main()
{
	int semid,key,flag,nsem;
	key = (key_t)0x30;
	flag = IPC_CREAT | 06600;
	nsem = 2;
	semid = semget(key,nsem,flag);
	if(semid > 0)
		printf("Created Semaphore With ID : %d\n",semid);
	else
		perror("1st Semget:\nm");
	
	nsem = 1;
	semid = semget(key,nsem,flag);
	printf("Created Semaphore With ID : %d\n",semid);
	if(semid > 0)
		printf("Created Semaphore With ID : %d\n",semid);
	else
		perror("2nd Semget:\nm");
	
	nsem = 4;
	semid = semget(key,nsem,flag);
	printf("Created Semaphore With ID : %d\n",semid);
	if(semid > 0)
		printf("Created Semaphore With ID : %d\n",semid);
	else
		perror("3rd Semget:\nm");
		
}
