#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>

int main()
{
	char *ptr;
	int id,pid;
	id = shmget((key_t)1,20,IPC_CREAT);
	ptr =(char *)shmat(id,0,0);
	pid = fork();
	printf("%d\n",pid);
	if(pid == 0)
	{
		strcpy(ptr,"hello world");
	}
	else
	{
		printf("parent reads   :%s\n",ptr);
		sleep(2);

	}
}
