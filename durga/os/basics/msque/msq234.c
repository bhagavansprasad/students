#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include<stdio.h>
main()
{
	int qid, len, i;
	struct 
	{
		long mytype;
		char mtext[15];
		
	}msg;
	qid = msgget((key_t)10, IPC_CREAT|0666);
	if(qid == -1)
	{
		perror("msget faild");
		exit(1);

	}
     strncpy(msg.mtext, "hello world\n", 15);
	 msg.mytype = 1;
	 len = strlen(msg.mtext);
	 for(i = 0; i<10000; i++)
	 {
	   printf("l is %d\n", i);
	   if(msgsnd(qid, &msg, len,0) == -1)
	   {
	   	perror("msgsand faild");
		exit(1);
	   }
	   
	 }
}

