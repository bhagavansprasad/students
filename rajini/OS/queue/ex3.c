#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

main()
{
  int i,msqid;
  key_t key=15;
  msqid=msgget(key,IPC_CREAT|0644);

  if(msqid<0)
    perror("msgget failed");
  else
    printf("Messsage queue successfully created with key %d\n",msqid);
}

