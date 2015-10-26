#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
main()
{
	int msgqid;
	char buff[100];
//	int pid;
//key_t key =0;
	msgqid=msgget((key_t),10,IPC_CREAT);
	printf("message queue successfully created with key %d\n",msgqid);
	read(msgqid,buff,3);
	printf("%s\n",buff);
	write(msgqid,"hello",6);
}
