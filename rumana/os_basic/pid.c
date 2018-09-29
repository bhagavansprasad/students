#include<stdio.h>
main()
{
int pid,i;
pid=getpid();
printf("process id is %d\n",pid);
for(i=0;i<=400000;i++);
printf("i is %d\n",i);
}
