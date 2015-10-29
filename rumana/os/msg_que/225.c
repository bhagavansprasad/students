#include<sys/types.h>
#include <sys/ipc.h>
#include<sys/msg.h>
#include <stdio.h>
main()
{
int i,msqid;
key_t key=12;
msqid=msgget(key,IPC_CREAT|IPC_EXCL);
if(msqid<0)
perror("message failed");
else
printf("message queue successfully created%d\n",msqid);

}
