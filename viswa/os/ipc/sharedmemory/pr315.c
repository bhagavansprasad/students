#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>

main()
{
	int shmid, i;
	char c,*ptr;

	shmid = shmget((key_t)200000,1, IPC_CREAT|0666);
	ptr = (char *)shmat(shmid, 0,0);
	while(1)
	{
		gets(&ptr[1]);
		ptr[0] = '$';

		if(ptr[1] == '@')
			break;
		while(1)
		{
			if(ptr[0] == '*')
				break;
		}
		puts(&ptr[1]);
	}
	shmctl(shmid, IPC_RMID,0);
}
