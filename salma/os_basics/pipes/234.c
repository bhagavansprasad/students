#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
main()
{
	int qid,len,i;
	struct{
		long mtype;
		char mtext[15];
	}message;
	qid = msgget((key_t)12,IPC_CREAT|0666);
	if(qid==-1)
	{
		perror("msgget failed \n");
		exit(1);
	}
	strncpy(message.mtext,"how r u \n",10);
	message.mtype=1;
	len=strlen(message.mtext);
	for(i=0;i<1000;i++)
	{
		printf("i is %d \n",i);
		if(msgsnd(qid,&message,len,0)==-1)
		{
			perror("msgsnd failed \n");
			exit(1);
		}
	}
}
