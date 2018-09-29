#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

main()
{
	int qid,ret,len;
	char buff[100];
	qid = msgget((key_t)12,IPC_CREAT|0666);

	struct
	{
		long type;
		char text[100];
	}send,recv;

	printf("enter the string :");
	scanf("%s\n",buff);

	strncpy(send.text,buff,100);
	send.type = 1;
	len = strlen(send.text);
	printf("the send.text value is :-->%s\n",send.text);	
	msgsnd(qid,&send,len,0);

	ret = msgrcv(qid,&recv,100,2,0);
	printf("the message from the client :-->%s\n",recv.text);
	
	msgctl(qid,IPC_RMID,0);

}
