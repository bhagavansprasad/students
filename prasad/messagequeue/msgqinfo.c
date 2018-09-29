#include"stdio.h"
#include"sys/types.h"
#include"sys/ipc.h"
#include"sys/msg.h"
#include"stdlib.h"

main(argc,argv)
    int argc;
    char *argv[];
{
    int qid;
    struct msqid_ds qstatus;
   
     qid=msgget((key_t)atoi(argv[1]),IPC_CREAT);
if(qid==-1)
    {
	perror("megget failed");
	exit(1);
    }
if(msgctl(qid,IPC_STAT,&qstatus)<0)
    {
	perror("msgctl failed");
	exit(1);
    }
    printf("Real user id of queue creater:%d\n",qstatus.msg_perm.cuid);

    printf("Real Group id of queue creater:%d\n",qstatus.msg_perm.cgid);

    printf("Effective user id of queue creater:%d\n",qstatus.msg_perm.uid);

    printf("Effective group id of queue creater:%d\n",qstatus.msg_perm.gid);

    printf("Permissions :%o \n",qstatus.msg_perm.mode);

    printf("\n Message queue id:%d \n\n",qid);

    printf("%d message(s) on queue\n\n",qstatus.msg_qnum);

    printf("last msg. send by process:%3d at %s \n",qstatus.msg_lspid,
    ctime(&(qstatus.msg_stime)));

    printf("last msg. recev by process:%3d at %s \n",qstatus.msg_lrpid,
    ctime(&(qstatus.msg_rtime)));

    printf("Current no of bytes on queue %d \n",qstatus.msg_cbytes);

    printf("max no of bytes allowed on queue %d \n",qstatus.msg_qbytes);

}
