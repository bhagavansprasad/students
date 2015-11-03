#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
main()
{
 int qid,len;
 struct
 {
 long mtype;
 char mtext[100];
 }send,receive;
 qid=msgget((key_t)10,IPC_CREAT|0666);
 if(qid==-1)
 {
   perror("msgget failed \n");
   exit(1);
 }
  if(msgrcv(qid,&receive,100,1,0)==-1)
  {
       perror("msgrcv failed \n");
	   exit(1);
  }
printf("message received %s \n",receive.mtext);
 strcpy(send.mtext,"i am okay what about u \n");
 send.mtype=2;
 len=strlen(send.mtext);
if((msgsnd(qid,&send,len,0))==-1)
{
 perror("msg snd failed \n");
exit(1);
}
}

