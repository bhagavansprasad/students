#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
main()
{
 int qid,len;
 struct
 {
  long mtype;
  char mtext[35];
 }send,receive;

qid = msgget((key_t)10,IPC_CREAT|0666);
if(qid == -1)
{
  perror("msgget failed \n");
   exit(1);
} 
  strcpy(send.mtext,"hello how r u");
  send.mtype=1;
  len=strlen(send.mtext);
  if((msgsnd(qid,&send,len,0))==-1)
  {
    perror("message send failed \n");
	exit(1);
  }
  if((msgrcv(qid,&receive,100,2,0))==-1)
  {
    perror("message received failed \n");
	exit(1);
  }
  printf("message received  %s \n",receive.mtext);
}