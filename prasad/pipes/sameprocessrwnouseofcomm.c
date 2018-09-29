#include"stdio.h"
#include"stdlib.h"
#define MSGSIZE 16
main()
{
char *msg1="i am your parent";
char *msg2="i am your child";
char inbuf[MSGSIZE];
int p[2],j,pid;
pipe(p);
pid=fork();
if(pid>0)
{
write(p[1],msg1,MSGSIZE);
read(p[0],inbuf,MSGSIZE);
}
else{
//close(p[1]);
write(p[1],msg2,MSGSIZE);
sleep(10);
read(p[0],inbuf,MSGSIZE);
printf("%s\n",inbuf);
}
exit(0);
}
