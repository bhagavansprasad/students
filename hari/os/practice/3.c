#include<stdio.h>
main()
{
fork();
printf("the parent PPID is %d\n",getppid());
printf("the child PID is %d\n",getpid());
fork();
printf("the parent PPID is %d\n",getppid());
printf("the child PID is %d\n",getpid());
fork();
printf("the parent PPID is %d\n",getppid());
printf("the child PID is %d\n",getpid());

}
