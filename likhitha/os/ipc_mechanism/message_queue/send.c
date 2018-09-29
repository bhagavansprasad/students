#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct {
	long mtype;       //msg type
	char mtext[25];  // msg text length
}message;

main()
{
	int qid;      //msg queue id

	qid=msgget((key_t)10,IPC_CREAT |0666);

	if(qid==-1)
	{
		perror("msgget failed");
		exit(1);
	}

	strcpy(message.mtext,"good morning world\n");
	message.mtype=1;

	if(msgsnd (qid,&message,21,0)==-1)
	{
		perror("msgsnd failed");
		exit(1);
	}

	strcpy(message.mtext,"good afternoon world\n");
	message.mtype=2;

	if(msgsnd(qid,&message,21,0)==-1)
	{
		perror("msgsnd failed");
		exit(1);
	}

	strcpy(message.mtext,"good evening world\n");
	message.mtype=3;

	if(msgsnd(qid,&message,21,0)==-1)
	{
		perror("msgsnd failed");
		exit(1);
	}

	if (strcmp("",message.mtext)!=0)
	{
		printf("sending...\n");
		exit(0);
	}
}
