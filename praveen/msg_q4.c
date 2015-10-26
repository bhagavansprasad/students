#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define PERMS 0666
main()
{
	key_t key = 100;
	int i,msqid;
	
	for(i=0;i<50;i++)
	{
		msqid = msgget(i,PERMS | IPC_CREAT);
		if(msqid<0)
		{
			perror("msgget failed");
			exit(1);
		}
		printf("msqid = %d\n",msqid);
	}
}
