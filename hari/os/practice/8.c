#include<stdio.h>
main()
{
 
 fork();
  printf("get pid:%d\n ",getpid());
  printf("get ppid: %d\n",getppid());
  fork();
  printf("get pid:%d\n ",getpid());
  printf("get ppid:%d\n ",getppid());
  fork();
  printf("get ppid:%d\n ",getpid());
  printf("get ppid:%d\n ",getppid());
  }

