#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SIZE (5*1024)
main()
{
	char *ptr;
	int shmid,pid;
	shmid = shmget((key_t)1,SIZE,IPC_CREAT|0666);
	ptr = (char *)shmat(shmid,(char *)0,0);
	pid = fork();
	if(pid == 0)
		read(0,ptr,SIZE);
	else
	{
		wait(0);
		printf("parent starts reading from shard memory and out putting toscreen\n");
		write(1,ptr,SIZE);
	}
}
