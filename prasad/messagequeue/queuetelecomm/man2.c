#include"stdio.h"
#include"sys/types.h"
#include"sys/ipc.h"
#include"sys/msg.h"
#include"string.h"
#include"stdlib.h"

main()
{
int qid,len;
struct{
long mtype;
char mtext[100];
}send,recv;
qid=msgget((key_t)10,IPC_CREAT|0666);
if(qid==-1)
{
perror("msgget failed");
exit(1);
}
if(msgrcv(qid,&recv,100,1,0)==-1)
{
perror("msgrcv failed");
exit(1);
}
printf("%s \n",recv.mtext);
strcpy(send.mtext,"i am ok what about you\n");
send.mtype=2;
len=strlen(send.mtext);
if(msgsnd(qid,&send,len,0)==-1)
{
perror("msg snd failed");
exit(1);
}
}

