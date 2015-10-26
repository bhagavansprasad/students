#include<stdio.h>
main()
{
 fork();
 printf("parent pid is:%d \n",getppid());
 printf("child pid is:%d \n",getpid());
 }
