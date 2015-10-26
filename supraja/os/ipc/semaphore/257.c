#include <sys/types.h>
#include <sys/ipc.h>
#include <fcntl.h>
main()
{
	int semid,key,nsem,flag;
	key=(key_t)0x20;
	nsem=1;
	semid=semget(key,nsem,IPC_CREAT|0666);
	printf("%d\n",getpid());
	printf("created semaphore with ID:%d\n",semid);
}
