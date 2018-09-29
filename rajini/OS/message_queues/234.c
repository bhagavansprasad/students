#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main()
{
	int qid,len,i;
	struct 
	{
		long mtype;
		char mtext[15];
	}message;
	qid = msgget(10,IPC_CREAT|0666);
	if(qid ==-1)
	{
		perror("msgget failed");
		exit(1);
	}
		strncpy(message.mtext,"hello world\n",15);
		message.mtype = 1;
		len = strlen(message.mtext);
		for(i=0;i<10000;i++)
		{
			printf("i is %d\n",i);
			if(msgsnd(qid,&message,len,0)==-1)
			{
				perror("msgsnd failed");
				exit(1);
		}
	}
}
