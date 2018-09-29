#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
main()
{
	struct 
	{
		long mtype;
		int pid;
		int sum;
	}recv;
	int qid,len,pid,i;
	qid = msgget((key_t)20,IPC_CREAT|0666);
	if(qid == -1)
	{
		perror("msgget failed");
		exit(1);
	}
	for(i=0;i<4;i++)
	{
		if(msgrcv(qid,&recv,100,0,IPC_NOWAIT)==-1)
		{
			perror("msgrcv failed");
			exit(1);
		}
		printf("--->pid : %d \n",recv.pid);
		printf("--->sum : %d \n",recv.sum);
	}
}
