#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SIZE  5*1024
main()
{
	char *ptr;
	int shmid,pid;
	shmid=shmget((key_t)12,SIZE,IPC_CREAT|0666);
	printf("shmid is %d\n",shmid);
	ptr=(char *)(shmid,0,0);
	printf("ptr is %u\n",ptr);
	pid=fork();
	if(pid==0)
	{
		read(0,ptr,SIZE);
		//printf("read is %s\n",ptr);
	}	
	else
	{   
	    wait(0);
		printf("parent starts from reading from share memory and outputting toscreen \n");
		write(1,ptr,SIZE);
	}
}
