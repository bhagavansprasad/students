#include<stdio.h>
#include <sys/types.h>
#include<sys/ipc.h>
#include <sys/msg.h>
main()
{
	int msqid;
	key_t key=15;
	msqid=msgget(key,IPC_CREAT|0644);
	if(msqid<0)
	perror("message get failed");
	else
	printf("message queue id is %d\n",msqid);


}
