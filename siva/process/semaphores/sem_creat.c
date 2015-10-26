#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
int semget(key_t,int,int);
int main()
{
int semid,key,nsem;
key=(key_t)90;
nsem=1;
semid=semget(key,nsem,IPC_CREAT|0666);
printf("Created Semaphore with Id :%d\n",semid);
return 0;
}
