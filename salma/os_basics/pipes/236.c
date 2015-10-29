#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
main()
{
 int qid,i,len;
 struct{
   long mtype;
   char mtext[15];
   }message,message1;
  qid=msgget((key_t)10,IPC_CREAT|0666);
  if(qid==-1)
  {
     perror("msgget failed \n");
	 exit(1);
  }
  strncpy(message.mtext,"hello world\n",15);
   len=strlen(message.mtext);
   message.mtype=1;
   if((msgsnd(qid,&message,len,0))==-1)
   {
     perror("message send failed \n");
	 exit(1);
    }
    
  if((msgrcv(qid,&message1,len,0,0))==-1)
  {
    perror("message received failed \n");
	exit(1);
  }
   printf("message received %s \n",message1.mtext);
}
