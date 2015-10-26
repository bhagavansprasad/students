#include<stdio.h>
main()
{
int pid;
pid=fork();
if(pid==0)
{
 printf("child pid:%d\n",getpid());
 printf("parent  ppid:%d\n",getppid());
 }
 else
 {
 printf("parentpid:%d\n",getpid());
 printf("parents parent pid:%d\n",getppid());\
 }
 }
  
