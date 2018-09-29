#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
main()
{
  int qid,len,i;
  struct{
    long mtype;
	char mtext[15];
  }message;
   
   qid = msgget((key_t)14,IPC_CREAT|0666);

   if(qid==-1)
   {
    perror("msgget failed to create \n");
    exit(1);
   }
    strncpy(message.mtext,"hello world \n",10);
	message.mtype=1;
	len=strlen(message.mtext);
	for(i=0;i<1850;i++)
	{
      printf(" i is :%d \n ",i);
	  if((msgsnd(qid,&message,len,IPC_NOWAIT))==-1)
	  {
          perror("message sent failed \n");
		  exit(1);
	  }
	}

}
