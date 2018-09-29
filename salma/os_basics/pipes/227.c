#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
main()
{
int i,msqid;
key_t key=15;
msqid=getmsg(key,IPC_CREAT||0666);
if(msqid<0)
perror("msgget failed\n");
else
printf("message queue successfully created with key %d \n",msqid);
}
