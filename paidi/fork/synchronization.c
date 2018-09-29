#include <stdio.h>
main()
{
 int i=0,pid;
 printf("ready to fork\n");
 pid=fork();
 if(pid==0)
 {
  printf("child starts\n");
  for(i=0;i<=10;i++)
   printf("%d\t",i);
   printf("child ends\n");
 }
 else
 {
  wait(0);
  for(i=0;i<10;i++)
  {
  printf("%d\t",i);
  printf("parent process\n");
  }
 }
}
