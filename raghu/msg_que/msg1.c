#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

main()
{
	int i,ret,qid,len,len1,len2;

	struct
	{
		long mtype;
		char text[15];
	}send,recv;

	qid = msgget((key_t)12,IPC_CREAT|0666);
	
	if(qid == -1)
	{
		perror("msgget failed");
		exit(1);
	}

	strncpy(send.text,"hello world",15);
	send.mtype = 1;
	len = strlen(send.text);
	
	if(msgsnd(qid,&send,len,0) == -1)
	{
		perror("msgsnd failed");
		exit(1);
	}

	strncpy(send.text,"hi world",15);
	send.mtype = 2;
	len1 = strlen(send.text);
	
	if(msgsnd(qid,&send,len1,0) == -1)
	{
		perror("msgsnd failed");
		exit(1);
	}

	strncpy(send.text,"hi",15);
	send.mtype = 3;
	len2 = strlen(send.text);
	if(msgsnd(qid,&send,len2,0)== -1)
	{
		perror("msgsnd failed");
		exit(1);
	}

	for(i=1;i<=3;i++)
	{
		ret = msgrcv(qid,&recv,8,i,IPC_NOWAIT|MSG_NOERROR);
		printf("ret value is %d\n",ret);

		if(ret == -1)
		{
			perror("msgrcv failed");
			exit(1);
		}

		recv.text[ret]='\0';
		printf("the message received %s\n",recv.text);
	}

	if(msgctl(qid,IPC_RMID,0) == -1)
	{
		perror("msgctl failed");
		exit(1);
	}
}
