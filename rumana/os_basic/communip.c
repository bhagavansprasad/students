#include<stdio.h>
#include<stdlib.h>
#define MSGSIZE 16
main()
{
char *msg1="hello,world";
char inbuf[MSGSIZE];
int p[2],pid;
pipe(p);
pid=fork();
printf("pid value is %d\n",pid);
if(pid>0)
{
write(p[1],msg1,MSGSIZE);
}
else
{
sleep(1);
read(p[0],inbuf,MSGSIZE);
printf(" in chaild is %s \n ",inbuf);
}
exit(0);
}

