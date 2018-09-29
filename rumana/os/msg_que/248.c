#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include<sys/msg.h>
main()
{

	int qid,len;
	struct
	{
		long mtype;
		int pid;
		char mtext[100];

	}recv;
	struct
	{
		long mtype;
		char mtext[100];

	}send;
	qid=msgget((key_t)10,IPC_CREAT|0666);
	printf("qid is %d\n",qid);
	if(qid==-1)
	{
		perror("msgget failed");
		exit(1);

	}
	if(msgrcv(qid,&recv,100,1,0)==-1)
	{
		perror("msgrcv failes");
		exit(1);
	}

	printf("msge rcv is %s\n",recv.mtext);
	strcpy(send.mtext,"am ok what about you");
	send.mtype=recv.pid;
	len=strlen(send.mtext);
	if(msgsnd(qid,&send,len,0)==-1)
	{
		perror("msgsnd failes");
		exit(1);

	}

}
