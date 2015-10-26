#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define PERMS 0666
main()
{
	int msqid;
	key_t i;
	for(i = 0;i < 50; i++)
	{
		msqid = msgget(key,IPC_CREAT|0);
		if(msqid < 0)
		{
			perror("msgget failed");
			exit(1);
		}
		printf("the msg queue is created with key %d\n",msqid);
	}
}
