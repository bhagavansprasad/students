#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define MY_KEY  19920809
#define SHM_SIZE 0x1000

void toggleCase(char *buf,int cnt);

void toggleCase(char *buf,int cnt)
{
	int i;
	for(i=0;i<cnt;i++)
	{
		if((buf[i] >= 'A') && (buf[i] <= 'Z'))
		buf[i]=0x20;
		
		if((buf[i] >='a' ) && (buf[i] <= 'z'))
		buf[i] -= 0x20;
	}
}

int main()
{
	int semId,shmId;
	char *pShm;
	struct sembuf smop;

	/** Create a Semaphore set ,Containig two semaphores **/
	semId = semget(MY_KEY,2,0660| IPC_CREAT);
	if(semId < 0)
	{
		printf("Could not Create Semaphore\n");
		return (1);
	}
	else
		printf("Opened a Semaphore Id is %d\n",semId);

	/** set initial token count of both semaphores to zeros **/
	semctl(semId,0,SETVAL,0);
	semctl(semId,1,SETVAL,0);

	/** Create Shared Memory Segment **/

	shmId = shmget(MY_KEY,SHM_SIZE, 0660 | IPC_CREAT);
	if(shmId < 0)
	{
		printf("Could Not Create Shared Memory Segment\n");
		return (2);
	}

	/*** ATTACH Shared Memory Segment to Processaddress space **/
	pShm = shmat(shmId,NULL,0);
	if(!pShm)
	{
		printf("Could not attach Shared Memory Segment\n");
		return 1;
	}

	while(1)
	{
		/** Wait For a token from semaphore 0 **/
		smop.sem_num = 0;
		smop.sem_op = -1;
		smop.sem_flg = 0;
		semop(semId,&smop,1);

		/** Process the Message available in Shared Memory **/
		printf("Got the semaphore \n");
		strcpy(pShm+256,pShm);
		toggleCase(pShm+256,strlen(pShm+256));
		printf("processed the request message and placed response\n");

		/** send token to semaphore 1 **/

		smop.sem_num = 1;
		smop.sem_op =  1;
		smop.sem_flg = 0;
		semop(semId,&smop,1);

	}
}

