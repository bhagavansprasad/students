#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
main()
{
int msgid;
msgid = msgget((key_t)12,IPC_CREAT);
printf("message queue is successfully created:%d \n",msgid);
}
