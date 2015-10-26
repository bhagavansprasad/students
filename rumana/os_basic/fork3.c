#include<stdio.h>
main()
{
printf("pid value is %d \n",getpid());
fork();
fork();
fork();
printf("hello world \n");
}
