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
int mtype;
char mtext[100];
}send,receive;
qid = msgget((key_t)10,IPC_CREAT|0666);
if(qid==-1)
{
  perror("msgget failed \n");
   exit(1);
}
 for(;;)
 {
   init(send.mtext);
   for(;;)
   {
      fflush(stdin);
	  gets(send.mtext);
	  if(send.mtext[0]=='\0')
	   continue;
	  break;
   }
  send.mtype=1;
  len=strlen(send.mtext);
  send.mtext[len]='\0';
  if(msgsnd(qid,&send,len+1,0)==-1)
  {
   perror("msgsnd failed ");
   exit(1);
  }
  if(strcmp("bye",send.mtext)==0)
  {
     exit(0);
  }
  init(receive.mtext);
  if(msgrcv(qid,&receive,100,2,0)==-1)
  {
    perror("msgrcv failed ");
	exit(1);
  }
  if(strcmp("bye",receive.mtext)==0)
   exit(0);
   printf("%s \n",receive.mtext);
 }
}
init(str)
char *str;
{
int i;
for(i=0;i<100;i++)
 str[i]=' '; 
}
