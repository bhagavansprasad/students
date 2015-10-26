#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

main(argc , argv)
int argc;
char *argv[];
{
	int semid, val = 0;

	val = atoi(argv[1]);

	semid = semget( (key_t)0x20 , 1, IPC_CREAT);
	semctl(semid , 0, SETVAL,val);
}
