#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
main()
{
	int qid,i;
	struct
		{
			long mtype;
			char mtext[25];
		}buff;

		qid=msgget((key_t)11,IPC_CREAT|0666);
		printf("qid is %d\n",qid);
		if(qid==-1)
		{
			perror("message is failed");
			exit(1);

		}

		for(;;)
		{
        	if(msgrcv(qid,&buff,21,1,IPC_NOWAIT|MSG_NOERROR)==-1)
			{
				perror("msg is failed");
				exit(1);
				
			}

			printf("message is %s\n",buff.mtext);

		}


}
