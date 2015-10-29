#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
main()
{
 int qid,len;
 struct
 {
  long mtype;
  char mtext[35];
 }message;
 qid=msgget((key_t)10,IPC_CREAT|0666);
 if(qid==-1)
 {
  perror("msg get failed \n");
  exit(1);
 }
  strcpy(message.mtext,"hello world good morning ");
  message.mtype=1;
  if((msgsnd(qid,&message,23,0))==-1)
  {
    perror("message received failed \n");
	exit(1);
  }
  strcpy(message.mtext,"hello world good afternoon ");
  message.mtype=2;
  if((msgsnd(qid,&message,23,0))==-1)
  {
   perror("message send failed \n");
   exit(1);
  }
  
  strcpy(message.mtext,"hello world good evening");
  message.mtype=3;
  if((msgsnd(qid,&message,28,0))==-1)
  {
    perror("message send failed \n");
    exit(1);
  }
 }
