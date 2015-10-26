#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>

main()
{
	int qid,len;
	struct
	{
		long mtype;
		char mtext[100];
	}message,buff;

	qid = msgget((key_t)11,IPC_CREAT|0666);

	strncpy(message.mtext,"good morning",30);
	message.mtype = 1;
	len1 = strlen(message.mtext);
	
	strncpy(message.mtext,"good afternoon",30);
	message.mtype = 2;
	len2 = strlen(message.mtext);
	
	strncpy(message.mtext,"good evening",30);
	message.mtype = 3;
	len = strlen(message.mtext);
	
	if(msgsnd(qid,&message,len,1) == -1)
	{
		perror("msgsnd failed");
		exit(1);
	}
	printf("the message send is %s\n",message.mtext);
	if(msgrcv(qid,&buff,len,1,0) == -1) 
	{
		perror("msgrcv failed");
		exit(1);
		
	}
	printf("the message received is %s\n",buff.mtext);
}
