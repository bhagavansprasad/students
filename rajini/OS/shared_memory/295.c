#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
main()
{
	int shmid,flag;
	key_t key = 0x1000;
	shmid = shmget(key,10,IPC_CREAT|0666);
	if(shmid < 0)
	{
		perror("shmid failed");
		exit(1);
	}
	printf("success shmid is : %d\n",shmid);
}
