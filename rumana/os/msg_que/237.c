#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

main()
{
	int qid;
	struct 
	{
		long mtype;
		char mtext[25];
	}message;
	qid=msgget((key_t)11,IPC_CREAT|0666);
	printf("qid is %d\n",qid);
	if(qid==-1)
	{
   		perror("msgget failed");
		exit(1);

	}
	strcpy(message.mtext,"good morning world\n");
	message.mtype=1;
	if(msgsnd(qid,&message,21,IPC_NOWAIT)==-1)
	{
    	perror("mesgsnd1 is failed");
		exit(1);
	}

    strcpy(message.mtext,"good afternoon world\n");
	message.mtype=2;
	if(msgsnd(qid,&message,21,IPC_NOWAIT)==-1)
	{
    	perror("mesgsnd2 is failed");
		exit(1);
	}
    strcpy(message.mtext,"good evening world\n");
	message.mtype=3;
	if(msgsnd(qid,&message,21,IPC_NOWAIT)==-1)
	{
    	perror("mesgsnd3 is failed");
		exit(1);
	}



}
