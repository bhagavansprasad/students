#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
main()
{
	char c,*ptr;
	int shmid,i;
	shmid=shmget((key_t)1,500,IPC_CREAT|0666);
	printf("shmid is %d\n",shmid);
	ptr=(char *)shmat(shmid,0,0);
	while(1)
	{
		gets(&ptr[1]);
		ptr[0]='$';
		if(ptr[1]=='@')
		break;
		while(1)
		{
			if(ptr[0]=='*')
			break;
		}
		puts(&ptr[1]);
	}
	shmctl(shmid,IPC_RMID,0);
}
