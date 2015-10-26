#include <stdio.h>
main()
{
fork();
printf("process id is %d\n",getpid());
printf("parent id is %d\n",getppid());
}
