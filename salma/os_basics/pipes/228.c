#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define PERMS 0666
main()
{
int msqid;
key_t key=15;
msqid=msgget(key,IPC_CREAT|0);
if(msqid<0)
 perror("msgget failed \n ");
else
printf("msg queue successfully created with a queue %d \n",msqid);
}
