#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SIZE 5*1024
main()
{
	char *ptr;
	int len,ret;
	int shmid,pid;
	shmid = shmget((key_t)1,20,IPC_CREAT|0666);
	ptr = shmat(shmid,0,0);
	pid = fork();
	strcpy(ptr," how are you");
		printf("the 1st data in the prt is %s\n",ptr);
	len = strlen(ptr);
	printf("the length of the string %d\n",len);
	if(pid == 0)
	{
		ret = read(0,ptr,SIZE);
		printf("the data in the prt is %s\n",ptr);
		printf("the ret value of the string %d\n",ret);
	}
	else
	{
		wait(0);
		printf("parent reading from the shared memory and out putting to screen \n");
		write(1,ptr,len+1);
		printf("\n");
	}
}
