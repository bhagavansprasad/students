#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int qid,j;
	struct 
	{
		long mtype;
		char mtext[25];
	}buff;
	qid = msgget(10,IPC_CREAT|0666);                  
}
