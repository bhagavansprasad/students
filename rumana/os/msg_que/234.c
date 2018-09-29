#include<stdio.h>
#include <sys/types.h>
#include<string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
main()
{
	int qid,len,i;
	struct 
	{
    	long mtype;
		char mtext[15];
	}message;
	printf("my process id is %d\n",getpid());
	qid=msgget((key_t)10,IPC_CREAT|0666);
	printf("qid is %d\n",qid);
	if(qid==-1)
	{
		perror("message failed");
		exit(1);

	}
    strncpy(message.mtext,"hello world\n",15);
	message.mtype=1;
	len=strlen(message.mtext);
	for(i=0;i<10000;i++)
	{
		printf("i is %d\n",i);
		if(msgsnd(qid,&message,len,0)==-1)
		{
    		perror("message failed");
			exit(1);
		}
	}
}
