#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>
main()
{
int which=PRIO_PROCESS;
int pid=7270;
int prio=9;
int retval= getpriority(which, pid);
printf("retval:%d\n",retval);
int reval= setpriority(which,pid,prio);   
printf(":%d\n",reval);
}
