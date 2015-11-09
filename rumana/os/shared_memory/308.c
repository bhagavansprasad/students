#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
main(int argc,char *argv[])
{
	char *ptr;
	int pid,shmid,i;
	shmid=shmget((key_t)1,1,IPC_CREAT|0666);
	printf("shmid is %d\n",shmid);
	ptr=(char *)shmat(shmid,0,0);
	printf("ptr is %u\n",ptr);
	pid=fork();
	if(pid==0)
	{
		for(i=0;i<atoi(argv[1]);i++)
		ptr[i]='A';
	}
	else
	{
		wait(0);
		i=write(1,ptr,atoi(argv[1]));
		printf("\twrite ret val is %d\n",i);
		printf("no of a: %s\n",ptr);
		
		
	}

}
