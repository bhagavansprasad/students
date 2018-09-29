#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *name[]={"onion","ennui","ashes","aegis","realm"};
char *nos[]={"651145","522387","5124058","587305","235064"};
int main()
{
int i;
	int qid,len;
	struct{
		long mtype;
		int pid;
		char mtext[100];
	}recv;
	struct{
		long mtype;
		char mtext[100];
	}send;
	if(fork()>0)
		exit(0);
	setpgrp();
	qid = msgget((key_t)10,IPC_CREAT | 0666);
	if(qid == -1)
	{
		perror("msgget failed");
		exit(1);
	}
	for(;;)
	{
		init(recv.mtext);
		msgrcv(qid,&recv,100,1,0);
		for(i=0;name[i];i++)
		{
			if(strncmp(recv.mtext,name[i],5)==0)
			{
				init(send.mtext);
				strcpy(send.mtext,nos[i]);
				send.mtype=recv.pid;
				len=strlen(send.mtext);
				msgsnd(qid,&send,len,0);
				break;
			}
		}
	}
}
init(str)
	char *str;
{
	int i;
	for(i=0;i<100;i++)
		str[i]=' ';
}
