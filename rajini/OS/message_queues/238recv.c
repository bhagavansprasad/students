#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
main(int argc, char **argv)
{
	int qid,i;
	struct
	{
		long mtype;
		char mtext[25];
	}buff;
	printf("--->in recv fun<---\n");
	qid = msgget(10,IPC_CREAT|0666);
	if(qid == -1)
	{
		perror("msgget failed");
		exit(1);
	}
	for(;;)
	{
		if(msgrcv(qid,&buff,21,atoi(argv[1]),IPC_NOWAIT|MSG_NOERROR)==-1)
		{
			perror("msgrcv failed");
			exit(1);
		}
		printf("message is : %s\n",buff.mtext);
	}
}
