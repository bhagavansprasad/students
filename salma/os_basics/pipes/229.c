#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#define PERMS 0666
main()
{
	int msqid;
	key_t i;
	for(i=0;i<=10;i++)
	{
		msqid=msgget(i,PERMS|IPC_CREAT);
		if(msqid < 0)
			perror("msgget failed \n ");
		else
			printf("msg queue create with msqid :%d \n", msqid);
	} 
}
