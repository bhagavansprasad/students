#include<stdio.h>
main()
{
int pid,i;
printf("%d\n",getpid());
//pid=fork();
for(i=0;i<10;i++)
{
pid=fork();
if(pid>0)
printf(" child:%d  parent:%d\n",getpid(),getppid());
/*else
printf(" child:%d  parent:%d\n",getpid(),getppid());*/
}
}
