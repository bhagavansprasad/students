#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>


main()
{
	int semid, nsem , key , flag , j, i;
	for( j = 0 ; j< 10; j++ )
	{

		flag = IPC_CREAT |0666 |IPC_EXCL;
		nsem = 21;

		key = (key_t)0x100;
		nsem = 1;

		semid = semget(key , nsem, flag);
		if( semid > 0)
			printf("created semaphore with ID :%d\n", semid);
		else
		{
			printf("j->%d\t",j);
			perror("semget:");
		}
	}
}

