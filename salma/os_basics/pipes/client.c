#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
extern int errno;
#define QKEY (key_t)0100
#define QPERM 0666
#define MAXOBN 50
#define MAXPRIOR 10
struct q_entry
{
long mtype;
char mtext[MAXOBN+1];
};
main(argc,argv)
int argc;
char *argv[];
{
int priority;
if(argc!=3)
{
 fprintf(stderr,"USAGE :%s objname priorty \n ", argv[0]);
 exit(1);
}
 if((priority = atoi(argv[2])) <=0 || priority > MAXPRIOR )
 {
 warn("invalid priority ");
 exit(2);
 }
 if(enter(argv[1],priority)<0)
 {
 warn("enter failure ");
 exit(3);
 }
 exit(0);
 }
 static int s_qid = -1;
 enter(objname,priority)
 char *objname;
 int priority;
 {
 int len;
 char *strncpy();
 struct q_entry s_entry;
 if((len = strlen(objname))>MAXOBN)
 {
 warn("Name too long ");
 return(-1);
 }
if(priority > MAXPRIOR || priority <0)
{
 warn("Invalid priority level ");
 return(-1);
}
 if(s_qid == -1 && (s_qid = init_queue())==-1)
  return(-1);
 s_entry.mtype = (long)priority;
 strncpy(s_entry.mtext,objname,MAXOBN);
 if(msgsnd(s_qid,&s_entry,len,0)==-1)
 {
 perror("msgsnd failed ");
 return(-1);
 }
 else
  return(0);
 }
init_queue()
{
int queue_id;
if((queue_id = msgget(QKEY,IPC_CREAT|QPERM))==-1)
{
 perror("msgget failed ");
 return(queue_id);
}
}
warn(s)
char *s;
{
fprintf(stderr,"Warning :%s \n",s);
}
