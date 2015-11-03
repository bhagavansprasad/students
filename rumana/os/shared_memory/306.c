#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#define SIZE 5*1024
main()
{
	struct databuf
	{
		int nread;
		char buff[SIZE];
	};
	struct databuf *ptr;
	int shmid,pid;
	shmid=shmget((key_t)12,SIZE,IPC_CREAT|0666);
	printf("shmid is %d\n",shmid);
	ptr=(struct databuf*)shmat(shmid,(char *)0,0);
	printf("ptr is %u\n",ptr);
	pid=fork();
	if(pid==0)
	{
		ptr->nread=read(0,ptr->buff,SIZE);
	}
	else
	{
		wait(0);
		write(1,ptr->buff,ptr->nread);
		printf("write is %s\n",ptr->buff);
	}
	
}
