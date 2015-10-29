#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
main()
{
	int shmid,flag;
	key_t key=0x10;
	shmid=shmget(key,100,IPC_CREAT|0666);
	if(shmid<0)
	{
		perror("1st shmid failed");
	}
	else
	printf("sucess 1st shmid is %d\n",shmid);
	shmid=shmget(key,110,IPC_CREAT|0666);
	if(shmid<0)
	printf("2nd shmid is failed");
	else
	printf("success 2nd shmid is %d\n",shmid);
    shmid=shmget(key,90,IPC_CREAT|0666);
	if(shmid<0)
	perror("3rd shmid is failed");
	else
	printf("success 3rd shmid is %d\n",shmid);


}
