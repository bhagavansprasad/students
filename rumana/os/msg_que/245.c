#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
main()
{
	int qid,len;
	struct
	{
		long mtype;
		char mtext[100];

	}send,recv;
	qid=msgget((key_t)10,IPC_CREAT|0666);
	printf("qid is %d\n",qid);
	if(qid==-1)
	{
		perror("messget failed");
		exit(1);
	
	}
		
	if(msgrcv(qid,&recv,100,1,0)==-1)
	{
		perror("msgrcv is failed");
		exit(1);
	}
	printf("msg rcv is %s\n",recv.mtext);

      strcpy(send.mtext,"am ok what about you");
	  send.mtype=2;
	  len=strlen(send.mtext);
	if(msgsnd(qid,&send,len,0)==-1)
	{
		perror("msgsnd failed");
		exit(1);

	}
	

}
