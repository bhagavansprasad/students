#include"stdio.h"
#include"sys/types.h"
#include"sys/ipc.h"
#include"sys/msg.h"
#include"string.h"
#include"stdlib.h"
main()
{

int qid,len,i;
struct{
long mtype;
char mtext[15];
}message;
qid=msgget((key_t)18,IPC_CREAT|0666);
if(qid==-1)
{
perror("msgget failed");
exit(1);
}
strncpy(message.mtext,"hello world\n",15);
message.mtype=1;
len=strlen(message.mtext);
printf("%d \n",len);
for(i=0; i<100000; i++)
{
printf("l is %d\n",i);

if(msgsnd(qid,&message,len,IPC_NOWAIT)==-1)
{
perror("msgsnd  failed");
exit(1);
}
}
}
