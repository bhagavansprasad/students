#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

main()
{

	int qid,i;

	struct {
		long mtype;
		char mtext[25];
	}buff;

	qid=msgget((key_t)10,IPC_CREAT |0666);

	if(qid==-1)
	{
		perror("msgget failed");
		exit(1);
	}

	for(i=0;i<3;i++)
	{
		if(msgrcv(qid,&buff,21,0,0)==-1)
		{
			perror("msgrcv failed");
			exit(1);
		}
		printf("message is %s\n",buff.mtext);
	}

}
