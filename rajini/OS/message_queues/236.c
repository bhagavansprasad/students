#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int qid,len ;
	struct 
	{
		long mtype;
		char mtext[15];
	}message,buff;
	qid = msgget(11,IPC_CREAT|0666);
	if(qid == -1)
	{
		perror("msgget failed");
		exit(1);
	}
	strncpy(message.mtext,"hello world\n",15);
	message.mtype = 1;
	len = strlen(message.mtext);
	if(msgsnd(qid,&message,len,0)==-1)
	{
		perror("msgsnd failed");
		exit(1);
	}
	if(msgrcv(qid,&buff,len,0,0)==-1)
	{
		perror("msgrcv failed");
		exit(1);
	}
	printf("message is : %s\n",buff.mtext);
}
