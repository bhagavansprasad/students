#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main()
{
	int qid,i;
	struct
	{
		long mtype;
		char mtext[25];
	}message;
	qid = msgget((key_t)10,IPC_CREAT|0666);
	if(qid == -1)
	{
		perror("msgget failed\n");
		exit(1);
	}
	strcpy(message.mtext,"good morning world\n");
	message.mtype = 1;
	if(msgsnd(qid,&message,21,0) == -1)
	{
		perror("msgsnd failed\n");
		exit(1);
	}
	printf("the msg is :%s\n",message.mtext);
	strcpy(message.mtext,"good morning world\n");
	strcpy(message.mtext,"good afternoon world\n");
	message.mtype = 1;
	if(msgsnd(qid,&message,21,0) == -1)
	{
		perror("msgsnd failed\n");
		exit(1);
	}
	printf("the msg is :%s\n",message.mtext);
	strcpy(message.mtext,"good evening world\n");
	message.mtype = 1;
	if(msgsnd(qid,&message,21,0) == -1)
	{
		perror("msgsnd failed\n");
		exit(1);
	}

		printf("the msg is :%s\n",message.mtext);
}

