#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

main()
{
	int semid;

	semid = semget( (key_t)0x60 , 30 , IPC_CREAT|0666);

	printf(" semid :->%d",semid);
}
