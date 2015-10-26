#include<stdio.h>
main()
{
 int pid;
 pid=fork();
 if(pid==0)
 {
  printf("\n");
  printf("i am the, my process ID is%d\n",getpid());
  printf("the child's parent process ID is%d\n",getpid());
  //wait(1);
 printf("\n");
  sleep(30);
  printf("\n");
  printf("i am the child,my process ID is%d\n",getpid());
  printf("the child's parent process ID is%d\n",getpid());

 }
 else
 {
 printf("\n");
  printf("i am the parent, my process ID is%d\n",getpid());
  printf("the parent process ID is%d\n",getpid());
 }
}
