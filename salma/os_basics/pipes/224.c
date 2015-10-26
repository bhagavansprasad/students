#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
main()
{
int msgid;
msgid=msgget((key_t)12,0);
printf("message queue is successfully created with key %d \n",msgid);
}
