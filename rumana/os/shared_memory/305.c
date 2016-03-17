#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SIZE 5*1024
main()
{
	char *ptr;
	int shmid,pid,nread;
	shmid=shmget((key_t)12,SIZE,IPC_CREAT|0666);
	printf("shmid is %d\n",shmid);
	ptr=(char *)shmat(shmid,(char *)0,0);
	printf("ptr is %u\n",ptr);
	pid=fork();
	if(pid==0)
	{
		nread=read(0,ptr,SIZE);
		ptr[nread]='\0';
	}
	else
	{
		wait(0);
		write(1,ptr,strlen(ptr));
	}
}
