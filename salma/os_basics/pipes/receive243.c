#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
main(argc,argv)
int argc;
char **argv;
{

int qid;
struct{
      long mtype;
	  char mtext[35];
    }buff;
 
 qid =msgget((key_t)10,IPC_CREAT|0666);
 if(qid == -1)
 {
   perror("msgget failed \n");
    exit(1);
 }
  

  if(msgrcv(qid,&buff,30,atoi(argv[1]),IPC_NOWAIT|MSG_NOERROR) ==-1)
  {
    perror("msgrcv failed \n");
	exit(1);
  }
  printf("msg received %s \n ",buff.mtext);
}
