#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#define SIZE 5*1024

main()
{
	char *ptr;
	int shmid,pid,nread;

	shmid = shmget((key_t)3,SIZE,IPC_CREAT|0666);
	ptr = (char *)shmat(shmid,(char *)0,0);
	strcpy(ptr, "hi buddy");
	printf("the 1st ptr value is %s\n", ptr);

	sleep(10);
}

