#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SIZE 5*1024
main()
{
	struct databuf
	{
		int nread;
		char buf[SIZE];
	};
	struct databuf *ptr;
	int shmid,pid;
	shmid=shmget((key_t)1,SIZE,IPC_CREAT|0222);
	printf("shmid is %d\n",shmid);
	ptr=(struct databuf *)shmat(shmid,(char *)0,0);
	printf("ptr is %u\n",ptr);
	pid=fork();
	if(pid==0)
	{
		ptr->nread=read(0,ptr->buf,SIZE);

	}
	else
	{
		wait(0);
		write(1,ptr->buf,ptr->nread);
	}
}
