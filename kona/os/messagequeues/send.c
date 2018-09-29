#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
	int qid;
	struct
	{
		long mtype;
		char atext[25];
	}message;
	qid=msgget((key_t)11,IPC_CREAT|0666);
	if(qid==-1)
	{
		perror("msgget failed");
		exit(1);
	}
	strcpy(message.atext,"good morning world\n");
	message.mtype=1;
	if(msgsnd(qid,&message,21,IPC_NOWAIT)==-1)
	{
		perror("msgsnd failed");
		exit(1);
	}
	strcpy(message.atext,"good afternoon world\n");
	message.mtype=2;
	if(msgsnd(qid,&message,21,IPC_NOWAIT)==-1)
	{
		perror("msgsnd failed");
		exit(1);
	}
	strcpy(message.atext,"good evening world\n");
	message.mtype=3;
	if(msgsnd(qid,&message,21,IPC_NOWAIT)==-1)
	{
		perror("msgsnd failed");
		exit(1);
	}
}
