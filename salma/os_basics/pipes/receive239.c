#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
main()
{
int qid,i;
struct{
 long mtype;
 char mtext[25];
}buff;
qid=msgget((key_t)10,IPC_CREAT|0666);
if(qid==-1)
{
perror("msg get failed \n");
exit(1);
}
 for(i=0;i<3;i++)
 {
    if((msgrcv(qid,&buff,21,0,IPC_NOWAIT))==-1)
	{
      perror("message receiving  failed \n");
	  exit(1);
	}
	printf("message received %s \n",buff.mtext);
 }
}
