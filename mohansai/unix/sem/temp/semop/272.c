#include "stdio.h"
#include "sys/types.h"
#include "sys/ipc.h"
#include "sys/sem.h"
#include "stdlib.h"
main(int argc,char *argv[])
{	
	int semid, val, set_semctl, get_semctl;
	
	val=atoi(argv[1]);

	semid=semget((key_t)0x20, 1, IPC_CREAT|0666);
	if(semid<0)
	{
		perror("error in creating semaphore");
		exit(1);
		}
	
	set_semctl = semctl(semid, 0, SETVAL, val);
	get_semctl = semctl(semid, 0, GETVAL, 0);
	printf("-->getsemctl --> %d\r\n", get_semctl );
	
	sleep(30);	
	
	//set_semctl = semctl(semid, 0, SETVAL, val*2);
	get_semctl = semctl(semid, 0, GETVAL, 0);
	printf("---->getsemctl --> %d\r\n", get_semctl );
}

