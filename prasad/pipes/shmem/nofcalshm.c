#include"stdio.h"
#include"sys/types.h"
#include"sys/ipc.h"
#include"sys/shm.h"
#include"stdlib.h"
main()
{
int shmid,flag;
key_t key=0x10;
shmid=shmget(key,100,IPC_CREAT|0666);
if(shmid<0)
perror("1st shmid failed:");
else
printf("success shmid is %d \n",shmid);

shmid=shmget(key,10,IPC_CREAT|0666);
if(shmid<0)
perror("2nd shmid failed:");
else  
printf("success shmid is %d \n",shmid);

shmid=shmget(key,99,IPC_CREAT|0666);
if(shmid<0)
perror("3rd shmid failed:");
else  
printf("success shmid is %d \n",shmid);
}
