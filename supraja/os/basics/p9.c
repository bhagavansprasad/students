#include<stdio.h>
int a=20;
int main()
{
printf("%d\n",a);
int pid,ppid;
pid=fork();
if(pid > 0)
 printf("parent process pid is %d\n",pid);
pid=fork();
if(pid > 0)
 printf("parent process pid is %d\n",pid);
 printf("%d\n",a);
pid=fork();
if(pid > 0)
 printf("parent process pid is %d\n",pid);
}
