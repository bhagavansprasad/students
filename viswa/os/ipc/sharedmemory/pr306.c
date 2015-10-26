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
	struct databuff
	{
		int nread;
		char buff[SIZE];
	};
	struct databuff *ptr;

	int shmid,pid;

	shmid = shmget((key_t)20000,SIZE,IPC_CREAT|0666);
	printf("shmid->%d\n",shmid);
	ptr = (struct databuff *)shmat(shmid, (char *)0, 0);

	pid = fork();

	if(pid == 0)
	{
		ptr->nread = read(0, ptr->buff, SIZE);
		ptr->buff[ptr->nread] = '\0';
		printf("ptr->%s\n",ptr->buff);
	}
	else
	{
		wait(0);
		write(1,ptr->buff, ptr->nread);
		printf("ptr->%s\n",ptr->buff);
	}
}
