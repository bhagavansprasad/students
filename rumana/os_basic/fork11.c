#include <stdio.h>
main()
{
int pid;
pid=fork();
printf(" %d\n",pid);
if(pid>0)
{
printf("parent process id is %d\n",pid);
}
}
