#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#define PERMS 0666
main()
{
	int msqid;
	key_t i;
	for(i=0;i<50;i++)
	{
		msqid=msgget(i,PERMS |IPC_CREAT);
		if(msqid<0)
		{
			perror("msgget failed\n");
			exit(1);
		}
		printf("message queue successfully created with key %d\n",msqid);
		if(msgctl(msqid,IPC_RMID,0)<0)
		{
			perror("msgctl failed\n");
			exit(1);
		}
	}
}
