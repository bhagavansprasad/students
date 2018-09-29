#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int qid,len;
	struct
	{
		long mtype;
		char mtext[100];
	}send,recv;
	qid = msgget(10,IPC_CREAT|0666);
	if(qid == -1)
	{
		perror("msgget failed\n");
		exit(1);
	}
	if(msgrcv(qid,&recv,100,1,0)==-1)
	{
		perror("msgrcv fialed\n");
		exit(1);
	}
	printf("%s\n",recv.mtext);
	strcpy(send.mtext,"i am ok what about you\n");
	send.mtype = 2;
	len = strlen(send.mtext);
	if(msgsnd(qid,&send,len,0)==-1)
	{
		perror("msgsnd failed\n");
		exit(1);
	}
}
