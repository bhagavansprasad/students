#include <stdio.h>
main()
{
printf("before exec my id is %d\n",getpid());
printf("my parent process id is %d\n",getppid());
printf("exec starts\n");
execl("/home/bhagavan/students/supraja/os/exec/ex3","ex3",(char*)0);
printf("this will not print\n");
}
