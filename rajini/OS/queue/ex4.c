#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"

struct msg_st messages[] = {
		{6, "Hello world"},
		{2, "I am rajini"},
		{3, "This is aura"},
		{4, "I am bau"},
		{5, "balu is sreenu"},
		{1, "band balu"}
};

main()
{
	int qid, retval, i;

	printf("My process id is %d \n",getpid());

	qid = msgget((key_t)405, IPC_CREAT | 0666);
	if(qid==-1)
	{
		perror("msgget failed");
		exit(1);
	}
	printf("qid success retval :%d\n", qid);

	for ( i = 0; i < 5; i++)
	{
		retval = msgsnd(qid, &messages[i], strlen(messages[i].mtext), 0);
		if(retval == -1)
		{
			perror("msgsnd failed");
			printf("retval :%d\n", retval);
			exit(1);
		}
		printf("%d. sending success retval :%d\n", i+1, retval);
	}
/*	if(msgctl(qid,IPC_STAT,&qstatus)<0)
	{
		perror("sgctl failed");
		exit(1);
	}
	printf("\n Message queue id :%d\n\n",qid);
	printf("%ldmessage(s) on queue \n\n",qstatus.msg_qnum);
	//printf("Last Msg.send by Process :%3d at %s\n",qstatus.msg_lspid,ctime(&qstatus.msg_stime));
	//printf("Last Msg.recv by Process :%3d at %s\n",qstatus.msg_lrpid,ctime(&qstatus.msg_rtime));
*/
}



