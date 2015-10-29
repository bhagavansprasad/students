#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
main()
{
 int qid;
 struct
 {
   long mtype;
   char mtext[35];
 }buff;

 qid=msgget((key_t)10,IPC_CREAT|0666);
 if(qid==-1)
 {
  perror("msgget failed \n");
  exit(1);
 }
 if(msgrcv(qid,&buff,29,1,IPC_NOWAIT|MSG_NOERROR)==-1)
 {
   perror("message received failed \n");
   exit(1);
 }
 printf("message received %s \n",buff.mtext);
}
