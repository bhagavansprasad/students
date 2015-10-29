#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdlib.h>
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
		perror("msgget is failed");
		exit(1);
	}
	for(;;)
	{
		init(send.mtext);
		for(;;)
		{
			fflush(stdin);
			gets(send.mtext);
			if(send.mtext[0]=='\0')
				continue;
			break;
		}
		send.mtype=1;
		len=strlen(send.mtext);
		send.mtext[len]='\0';
		if(msgsnd(qid,&send,len+1,0)==-1)
		{
			perror("msgsnd failed");
			exit(1);
		}
		if(strcmp("bye",send.mtext)==0)
		{
			exit(0);
		}
		init(recv.mtext);
		if(msgrcv(qid,&recv,100,2,0)==-1)
		{
			perror("msgrcv failed");
			exit(1);
		}
		if(strcmp("bye",recv.mtext)==0)
			exit(0);
		printf("%s\n",recv.mtext);
	}
}
init(str)
	char *str;
{
	int i;
	for(i=0;i<100;i++)
		str[i]=' ';

}
