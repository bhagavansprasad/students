#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <string.h>
#define SIZE 5*1024

main()
{
	char *ptr;
	int shmid,pid,nread;

	shmid = shmget((key_t)20000,SIZE,IPC_CREAT|0666);
	printf("shmid->%d\n",shmid);
	ptr = (char *)shmat(shmid, (char *)0, 0);

	pid = fork();

	if(pid == 0)
	{
		nread = read(0, ptr, SIZE);
		ptr[nread] = '\0';
		printf("ptr->%s\n",ptr);
	}
	else
	{
		wait(0);
		write(1,ptr, strlen(ptr));
		printf("ptr->%s\n",ptr);
	}
}
