#include <stdio.h>
main()
{
int pid;
printf("fork examle");
pid=fork();
if(pid==0)
{
printf("\nI am child=%d",pid);
}
else
{
printf("\n I am parent=%d",pid);
}
}

