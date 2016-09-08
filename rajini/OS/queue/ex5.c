#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"

main()
{
	int qid,len,i, retval;
	char buff[100] ={0};
	struct msg_st rcvbuff;

	qid = msgget((key_t)333, IPC_CREAT|0666);
	if(qid ==-1)
	{
		perror("msgget Failed");
		exit(1);
	}

	printf("qid success retval :%d\n", qid);

	for(;;)
	{
		retval = msgrcv(qid, &rcvbuff,50, 0, 0);

		if(retval == -1)
		{
			perror("msgrcv failed");
			printf("retval :%d\n", retval);
			exit(1);
		}
		printf("msgrcv retval :%d\n", retval);
		printf("message is    %ld:%s\n", rcvbuff.mtype, rcvbuff.mtext);
		sleep(5);
	}
}



