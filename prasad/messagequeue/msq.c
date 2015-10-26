#include"stdio.h"
#include"sys/types.h"
#include"sys/ipc.h"
#include"sys/msg.h"

main()
{
int msqid;

msqid=msgget((key_t)14,IPC_CREAT|0666);

if(msqid==-1)
perror("msq failed");
else
printf("message queue successfully created with key %d\n",msqid);


}
