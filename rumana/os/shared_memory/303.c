#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
main()
{
	char *ptr;
	int shmid,pid;
	shmid=shmget((key_t)11,20,IPC_CREAT|0666);
	printf("shmid is %d\n",shmid);
	ptr=(char *)shmat(shmid,(char *)0,0);
	printf("ptr is %u\n",ptr);
	pid=fork();
	if(pid==0)
	strcpy(ptr,"hello world");
	else
	{
		wait(0);
		printf("parent reads is %s\n",ptr);
	}
}
