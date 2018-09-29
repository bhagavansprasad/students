#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

main()
{
	int qid,len,ret;
	char buff[100];

	qid = msgget((key_t)12,IPC_CREAT|0666);
	
	struct 
	{
		long type;
		char text[100];
	}send,recv;
	
	ret = msgrcv(qid,&recv,100,1,0);
	recv.text[ret] = '\0';
	printf("message received from the server :-->%s\n",recv.text);
	
	printf("enter the text :");
	scanf("%s\n",buff);
	strncpy(send.text,buff,100);
	send.type = 2;
	len = strlen(send.text);

	msgsnd(qid,&send,len,0);

	msgctl(qid,IPC_RMID,0);
}
