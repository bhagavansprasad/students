#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <string.h>
#define SIZE 5*1024

main(argc, argv)
int argc;
char *argv[];
{
		char *ptr;
	int shmid,pid,i;

	shmid = shmget((key_t)20000,1,IPC_CREAT|0666);
	printf("shmid->%d\n",shmid);
	ptr = (char *)shmat(shmid, 0, 0);

	pid = fork();

	if(pid == 0)
	{
	for(i = 0; i<atoi(argv[1]); i++)
		ptr[i]='A';
	}
	else
	{
		wait(0);
		i = write(1,ptr, atoi(argv[1]));
		printf("write ret->%d\n",i);
	}
}
