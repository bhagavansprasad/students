#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define PERMS 0666
main()
{
	int  i;
	int msqid;
	for(i=0;i<50;i++)
	{
		msqid=msgget(i,PERMS|IPC_CREAT);
		if(msqid<0)
		{
			perror("msgget failed\n");
			exit(1);
		}
		printf("msqid = %d\n",msqid);
	}

}
