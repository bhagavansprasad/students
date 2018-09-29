#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
main()
{
	int msgqid;
	char buff[100];
	msgqid=msgget((key_t)10,IPC_CREAT);
	printf("message queue successfully created with key %d\n",msgqid);
	write(msgqid,"hi",3);
	read(msgqid,buff,6);
printf("%s\n",buff);
}	

