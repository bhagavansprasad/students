#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
	int semid,key,flag,nsem,j,i;
	key=(key_t)0x40;
	flag=IPC_CREAT|0666;
	nsem=1;
	semid=semget(key,nsem,flag);
	if(semid>0)
		printf("created semaphore with id:%d\n",semid);
	else
		perror("1st segment");
	flag=IPC_CREAT|0644;
	semid=semget(key,nsem,flag);
	if(semid>0)
		printf("created semaphore with id:%d\n",semid);
	else
		perror("2nd segment");
}
