#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
main()
{
int msgid;
key_t key=13;
msgid= msgget(key, IPC_CREAT||IPC_EXCL);
if(msgid<0)
printf("msgget failed \n");
else
printf("message is successfully created with key %d \n",msgid);
}
