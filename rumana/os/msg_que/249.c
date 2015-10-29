#include<stdio.h>
#include<sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <stdlib.h>
#include<string.h>
main()
{
	int qid,len;
	struct
	{
		long mtype;
		int pid;
		char mtext[100];

	}send;
	struct
	{
		long mtype;
		char mtext[100];
	}recv;
	qid=msgget((key_t)10,IPC_CREAT|0666);
	printf("qid is %d \n",qid);
	if(qid==-1)
	{
		perror("msgget failes");
		exit(1);
	}

	strcpy(send.mtext,"hello how are you");
	recv.mtype = send.pid;
	len=strlen(send.mtext);
	if(msgsnd(qid,&send,len,0)==-1)
	{
		perror("msgsnd failed");
		exit(1);
	}
	if(msgrcv(qid,&recv,100,1,0)==-1)
	{
		perror("msgrcv failed");
		exit(1);
	}
	printf("%s\n",recv.mtext);


}
