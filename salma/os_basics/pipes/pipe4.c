#include<stdio.h>
main()
{
int pid,pid1,i;
printf("%d \n",getpid());
for(i=1;i<=3;i++)
{
pid=fork();
if(pid>0)
printf("parent:%d child:%d\n",getppid(),getpid());
else 
sleep(2);
/*pid1=fork();
if(pid1>0)
printf("parent:%d child:%d\n",getppid(),getpid());
else
sleep(2);*/
}
}
