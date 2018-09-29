#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
main()
{
	int semid,key,flag,nsem,i,j;
	flag = IPC_CREAT|0666;
	nsem = 25;
	for(j=0;j<10;j++)
	{
		key=(key_t)(j+1);
		semid = semget(key,nsem,flag);
		if(semid > 0)
			printf("created sema");
	}
}
