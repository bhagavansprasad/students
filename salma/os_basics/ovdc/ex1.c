#include<stdio.h>
#include<sys/resource.h>
#include<sys/time.h>
main()
{
 int d,pid,s;
 pid=getpid();
 printf("%d\n",pid);
 d=getpriority(PRIO_PROCESS,pid);
 printf("%d\n",d);
 s=setpriority(PRIO_PROCESS,pid,d-5);
 printf("%d\n",s);
d=getpriority(PRIO_PROCESS,pid);
 printf("%d\n",d);


}
