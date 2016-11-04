#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define PERMS 0666
main()
{
	int key = 10;
	int i ,msqid;
	for(i=0;i<2;i++)
	{
		msqid = msgget(key,PERMS|IPC_CREAT);
		if(msqid<0)
			perror("msgget failed");
		printf("msqid : %d\n",msqid);
	}
}
