#include<stdio.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<error.h>

#define QKEY (key_t)0100
#define QPERM 0666
#define MAXOBN 50
#define MAXPRIOR 10

struct q_entry
{
long mtype;
char mtext[MAXOBN+1];
};
main()
{
 int pid;
 switch(pid = fork())
 {
  case 0:
    setpgrp();
	serv();
	break;
 case -1:
  warn("fork to startserver failed ");
  break;
 }
exit(pid != -1 ? 0 :1 );
}

static int r_qid = -1;
int fd;
void usr1();
void usr2();
serv()
{
long pro_type;
struct q_entry  r_entry;
int mlen;
char buf[10];
fd = creat("ser.txt",O_WRONLY|O_CREAT|O_EXCL,0644);
if(fd < 0)
{
printf("server already installed \n");
exit(0);
}
else
{
 printf("server process PID is %d \n ", getpid());
}
sprintf(buf,"%d",getpid());
write(fd,buf,sizeof(int));
chmod("ser.txt",0400);
if(r_qid == -1 && (r_qid = init_queue()) == -1)
{
 return (-1);
}
signal(SIGUSR1,usr1);
signal(SIGUSR2,usr2);
for(;;)
{
  if((mlen = msgrcv(r_qid,&r_entry,MAXOBN,0,MSG_NOERROR))==-1)
  {
      perror("msgrcv failed ");
	  return(-1);
  }
  else
  {
    r_entry.mtext[mlen]='\0';
	proc_obj(r_entry.mtext);

  }
}
}
proc_obj(msg)
char *msg;
{
 printf("%s \n",msg);
 system(msg);
}
void usr1()
{
 pause();
}
void usr2()
{
signal(SIGUSR1,usr1);
signal(SIGUSR2,usr2);
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
fprintf(stderr,"warning :%s \n",s);
}
