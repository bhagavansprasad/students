#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "sys/ipc.h"
#include "sys.shm.h"


main(int argc,char *argv[])
{
	int shmid,pid,i;
	char *prt;
	shmid = shmget ( (key_t)1024 , 2000 , IPC_CREAT|0666);
	
	ptr=shmat(shmid,0,0);

pid=fork();
if(pid==0)
{
	read
