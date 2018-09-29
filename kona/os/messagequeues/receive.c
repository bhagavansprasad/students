#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
	int qid,i;
	struct
	{
		long mtype;
		char atext[25];
	}buff;
	qid=msgget((key_t)11,IPC_CREAT|0666);
	if(qid==-1)
	{
		perror("msgget failed");
		exit(1);
	}
	for(i=0;i<3;i++)
	{
		if(msgrcv(qid,&buff,15,0,IPC_NOWAIT|MSG_NOERROR)==-1)
		{
			perror("msgrcv failed");
			exit(1);
		}
		printf("message is %s\n",buff.atext);
	}
}
	
