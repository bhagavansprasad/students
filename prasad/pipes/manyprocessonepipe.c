#include"stdio.h"
main()
{
int p[2],j,pid;
char msg[20];
pipe(p);
pid=getpid();
fork();
fork();
if(pid==getpid())
{
for(j=0;j<3;j++)
wait((int *)0);
for(j=0;j<3;j++)
{
read(p[0],msg,12);
printf("%s \n",msg);
}
}
else
write(p[1],"hello world",12);
}

