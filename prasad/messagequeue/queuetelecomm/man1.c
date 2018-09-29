#include"stdio.h"
#include"sys/types.h"
#include"sys/ipc.h"
#include"sys/msg.h"
#include"stdlib.h"
#include"string.h"

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
strcpy(send.mtext,"hello howe are you\n");
send.mtype=1;
len=strlen(send.mtext);
if(msgsnd(qid,&send,len,0)==-1)
{
perror("msgsnd failed");
exit(1);
}
if(msgrcv(qid,&recv,100,2,0)==-1)
{
perror("msgrcv failed");
exit(1);
}
printf("%s \n",recv.mtext);
}
