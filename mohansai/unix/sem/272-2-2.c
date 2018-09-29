#include "stdio.h"
#include "sys/types.h"
#include "sys/ipc.h"
#include "sys/sem.h"

main()
{
	int semid, get_semctl, i=0;
	
	semid = semget((key_t)0x21, 1, IPC_CREAT|0666);
	while(i++ < 10)
	{
		get_semctl = semctl(semid, 0, GETVAL, 0);
		printf("get_semctl--> %d\r\n", get_semctl);
		sleep(1);
	}	
}


