#include<stdio.h>
#include <sys/types.h>
#include<sys/ipc.h>
#include <sys/shm.h>
main()
{
	int shmid,i;
	char *msg;
	shmid=shmget((key_t)1,1,IPC_CREAT|0666);
	printf("shmid is %d\n",shmid);
	msg=(char *)shmat(shmid,(char *)0,0);
	printf("msg is %u\n",msg);
	i=shmat((char *)msg,0,0);
	printf(" i%d\n",i);

}
