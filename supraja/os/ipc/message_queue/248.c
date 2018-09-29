#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main()
{
	int qid,len;
	struct{
		long mtype;
		int pid;
		char mtext[100];
	}recv;
	struct {
		long mtype;
		char mtext[100];
	}send;
	qid = msgget((key_t)10,IPC_CREAT | 0666);
	if(qid == -1)
	{
		perror("msgget failed");
		exit(1);
	}
	if(msgrcv(qid,&recv,100,1,0)==-1)
	{
		perror("msgsnd failed");
		exit(1);
	}
	printf("%s\n",recv.mtext);
	strcpy(send.mtext,"i am ok what about you\n");
	send.mtype=recv.pid;
	len=strlen(send.mtext);
	if(msgsnd(qid,&send,len,0)==-1)
	{
		perror("msgsnd failed");
		exit(1);
	}
}

