#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


main()
{
	int qid, len , ret ;

	struct 
	{
		long mtype;
		char mtext[15];
	}message,buff;
	qid = msgget( (key_t)11 , IPC_CREAT | 0666);

	if( qid == -1)
	{
		perror( "msgget failed :");
		exit(1);
	}
	strncpy( message.mtext , "Hello world \n" , 15);
	message.mtype = 1 ;
	len = strlen(message.mtext);
	printf("len :-> %d\n",len);

	if( msgsnd( qid , &message , len , 0) == -1)
	{
		perror(" msgsnd failed :");
		exit(1);
	}

	if(ret = msgrcv( qid , &buff , len , 0 ,0 ) == -1)
	{
		perror( "msgrcv failed :");
		exit(1);
	}
	printf("ret :-> %d\n",ret);
	//buff.mtext[ret] = '\0';
	printf("  message is:-> %s\n" ,buff.mtext);
}
