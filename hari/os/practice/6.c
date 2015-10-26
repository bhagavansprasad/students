#include<stdio.h>
main()
{
 int pid;
 pid=fork();
 if(pid<0)
  printf("fork failed\n");
  else
   printf("fork succedded\n");
 }  
