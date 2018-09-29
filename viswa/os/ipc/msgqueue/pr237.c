#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


main()
{
	int qid ,len,i ;
	
	struct
	{
		long mtype;
		char mtext[15];
	}message;

	qid = msgget((key_t)10, IPC_CREAT|0666);
	printf("qid ->%d \n", qid);

	if( qid  == -1)
	{
		perror("msgget failed :");
		exit(1);
	}

	strncpy( message.mtext, "Hello World \n",15);
	message.mtype = 5;
	len = strlen(message.mtext);

	if( msgsnd( qid, &message, len , IPC_NOWAIT) == -1)
	{
		perror( " msgsend failed:");
		exit(1);
	}
	strncpy( message.mtext, "welcome to  AMRUTHALA\n",15);
	message.mtype = 3;
	len = strlen(message.mtext);

	if( msgsnd( qid, &message, len , IPC_NOWAIT) == -1)
	{
		perror( " msgsend failed:");
		exit(1);
	}
	strncpy( message.mtext, "  viswanath  YADAV \n",15);
	message.mtype = 2;
	len = strlen(message.mtext);

	if( msgsnd( qid, &message, len , IPC_NOWAIT) == -1)
	{
		perror( " msgsend failed:");
		exit(1);
	}

}
