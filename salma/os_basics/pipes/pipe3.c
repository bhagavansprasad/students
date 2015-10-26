#include<stdio.h>
main()
{
int pid,i;
printf("%d\n",getpid());
for(i=0;i<3;i++)
pid=fork();
printf("child:%d parent:%d\n",getpid(),getppid());
/*pid=fork();
printf("child:%d parent:%d\n",getpid(),getppid());
pid=fork();
printf("child:%d parent:%d\n",getpid(),getppid());*/

}
