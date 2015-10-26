#include<stdio.h>
#include<signal.h>
main()
{
printf("press del key to terminate \n");
signal(SIGINT,SIG_DFL);
for(;;);
}
