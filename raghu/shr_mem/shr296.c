#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

main()
{
	int shmid,flag;
	key_t key = 0x11;
	shmid = shmget(key,200,IPC_CREAT|0666);
	
	if(shmid<0)
	perror("1st shmid failed");
	else
	printf("1st shmid success\n");
	
	shmid = shmget(key,100,IPC_CREAT|0666);

	if(shmid<0)
	perror("2nd shmid failed");
	else
	printf("2nd shmid success\n");
	
	shmid = shmget(key,90,IPC_CREAT|0666);

	
	if(shmid<0)
	perror("3rd shmid failed");
	else
	printf("3rd shmid success\n");
}
