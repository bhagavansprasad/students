#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
main()
{
	struct 
	{
		long mtype;
		int pid;
		int sum;
	}send;
	int qid,len,i;
	qid = msgget((key_t)20,IPC_CREAT|0666);
	//char s[][10]={"hai","hello","hw r u","fine"};
	if(qid == -1)
	{
		perror("msgget failed");
		exit(1);
	}
	for(i=0;i<4;i++)
	{

		send.mtype = i+1;
	//	strcpy(send.mtext,s[i]);
	//	len = strlen(send.mtext);
	//	send.mtext[len] = '\0';
		send.pid = 100;
		send.sum = 200;
		if(msgsnd(qid,&send,100,0)== -1)
		{
			perror("msgsnd failed");
			exit(1);
		}
	}
}
