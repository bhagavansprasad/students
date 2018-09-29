#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

main()
{
	int shmid;
	char *p1;
	char *p2;
	shmid = shmget((key_t)1,20,IPC_CREAT|0666);
	if(shmid == -1)
	{
		perror("shmget failed");
		exit(1);
	}
	p1 = shmat(shmid,0,0);
	p2 = shmat(p1,0,0);
	strcpy(p2,"hello");
	sleep(10);
	printf("the data from the server %s\n",p1);
}
