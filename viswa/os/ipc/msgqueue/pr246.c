#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	int qid ,len,ret ;
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



	for(;;)
	{
		init(send.mtext);
		for(;;)
		{
			fflush(stdin);
			gets( send.mtext);
			if( send.mtext[0] == '\0')
				continue;
			break;
		}
		send.mtype = 1;
		len = strlen(send.mtext);
		send.mtext[len] = '\0';

		if( msgsnd( qid, &send, len+1 , 0) == -1)
		{
			perror( " msgsend failed:");
			exit(1);
		}
		if( strcmp( "bye" , send.mtext) == 0)
		{
			exit(0);
		}
		init( recv.mtext);

		ret = msgrcv( qid, &recv, 20 ,2, 0);
		if( ret == -1)
		{
			perror( " msgrcv failed:");
			exit(1);
		}

		if( strcmp( " bye " , recv.mtext) == 0)
			exit(0);

		recv.mtext[ret] = '\0';
		printf("%d\n",ret);

		printf("message :->%s\n",recv.mtext);

	}
}

init(str)
	char *str;
{
	int i;

	for( i = 0 ; i < 100 ; i++)
		str[i] = " ";  
}
