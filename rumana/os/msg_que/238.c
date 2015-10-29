#include <stdio.h>
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
		char mtext[19];
	}buff;
	qid=msgget((key_t)11,IPC_CREAT|0666);
	printf("qid is %d\n",qid);
	if(qid==-1)
	{
     perror("message failed");
	 exit(1);
    
	}
	for(i=0;i<3;i++)
	{
    	if(msgrcv(qid,&buff,15,0,IPC_NOWAIT|MSG_NOERROR)==-1)
		{
         	perror("message failed");
			exit(1);
        
		}
		printf("message rcv is %s\n",buff.mtext);
      
	}

}
