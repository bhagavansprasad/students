#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


main( argc , argv)
int argc;
char **argv;
{
	int qid , i , len  = 15;

	struct
	{
		long mtype;
		char mtext[15];
	}buff;

	qid = msgget((key_t)10, IPC_CREAT|0666);
	printf("qid ->%d \n", qid);

	if( qid  == -1)
	{
		perror("msgget failed :");
		exit(1);
	}
	for( i = 0 ; i< 3 ; i++)
	{
		if( msgrcv( qid, &buff, len ,atoi(argv[1]), IPC_NOWAIT | MSG_NOERROR) == -1)
		{
			perror( " msgrcv failed:");
			exit(1);
		}
		printf("message :->%s\n",buff.mtext);
	}
}
