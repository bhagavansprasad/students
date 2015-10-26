#include<stdio.h>
main()
{
int pid;
pid=fork();
if(pid<0)
{
printf("fork is failed\n");
}
else 
{
printf("fork is succeeded\n");
}
}
