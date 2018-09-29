#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
	int qid,len,i;
	//struct msqid_ds qstatus;
	struct
	{
		long mtype;
		char mtext[15];
	}message;
	//printf("my process id is %d\n",getpid());
	qid=msgget((key_t)10,IPC_CREAT|0666);
	if(qid==-1)
	{
		perror("msgget failed");
		exit(1);
	}
	strncpy(message.mtext,"hello world\n",15);
	message.mtype=1;
	len=strlen(message.mtext);
	for(i=0;i<1000;i++)
	{
		printf("i is %d\n",i);
		if(msgsnd(qid,&message,len,IPC_NOWAIT)==-1)
		{
			perror("msgsnd failed");
			exit(1);
		}
	}
}

