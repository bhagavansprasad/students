#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
	if(qid==-1)
	{
		perror("msgget failed\n");
		exit(1);
	}
	strcpy(send.mtext,"hello how are you\n");
	send.mtype = 1;
	len=strlen(send.mtext);
	if(msgsnd(qid,&send,len,0)==-1)
	{
		perror("msgsnd failed\n");
		exit(1);
	}
	if(msgrcv(qid,&recv,100,2,0)==-1)
	{
		perror("msgrcv failed\n");
		exit(1);
	}
	printf("%s\n",recv.mtext);
}
