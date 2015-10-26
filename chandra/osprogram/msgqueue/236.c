#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int qid, len;
	struct 
	{
		long mtype;
		char mtext[5];
	} message,buff;
	qid = msgget((key_t) 11, IPC_CREAT | 0666);
	if(qid == -1)
	{
		perror("msgget failed\n");
		exit(1);
	}
	strncpy(message.mtext, "hello world\n", 15);
	message.mtype = 1;
	len = strlen(message.mtext);
	if(msgsnd(qid, &message, len, 0) == -1)
	{
		perror("msgsnd failed\n");
		exit(1);
		
	}
	if(msgrcv(qid, &buff, len, 0, 0) == -1)
	{
		perror("msgrcv failed\n");
		exit(1);
		
	}
	printf("message is : %s\n", buff.mtext);
}
