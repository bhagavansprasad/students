#include <stdio.h>
#include<sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#define PERMS 0666
main()
{
	key_t key=100;
	int i,msqid,rm;
	for(i=0;i<=50;i++)
	{
		msqid=msgget(key,PERMS|IPC_CREAT);
		if(msqid<0)
		{
			perror("message get failed");
			exit(1);
		}
		printf("message queue is created and key is %d %d\n",msqid,key);
		if(rm=msgctl(msqid,IPC_RMID,0)<0)
		{
			perror("messagectl get failed");
			exit(1);
		}
		printf("message is remved %d\n",rm);
	}


}
