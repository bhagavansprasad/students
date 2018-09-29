#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>

main()
{
	int shmid,flag;
	key_t key = 0x1000;
	shmid = shmget(key,10,IPC_CREAT|0666);
	if(shmid<0)
	{
		perror("shmget failed");
		exit(1);
	}
	printf("success shmid :%d\n",shmid);
}
