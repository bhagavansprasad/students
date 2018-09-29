#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


main()
{
	int qid ,len,ret;

	struct
	{
		long mtype;
		char mtext[15];
	}send , recv;

	qid = msgget((key_t)10, IPC_CREAT|0666);
	printf("qid ->%d \n", qid);

	if( qid  == -1)
	{
		perror("msgget failed :");
		exit(1);
	}
	 ret = msgrcv( qid, &recv, 20 ,1,0);

	if( ret == -1)
	{
		perror( " msgrcv failed:");
		exit(1);
	}
	
	recv.mtext[ret] = '\0';
	
	printf("message :->%s\n",recv.mtext);

	strncpy( send.mtext, "welcome to earth \n" , 20);
	send.mtype = 2;
	
	len = strlen(send.mtext);

	if( msgsnd( qid, &send, len , 0) == -1)
	{
		perror( " msgsend failed:");
		exit(1);
	}
	msgctl(qid,IPC_RMID,0);

}
