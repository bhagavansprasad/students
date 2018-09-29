#include<stdio.h>
#include<signal.h>
void sigkey();
main()
{
printf("press ctrl key.\n");
signal(SIGQUIT,sigkey);
for(;;);
}
void sigkey()
{
printf("received signal \n");
}
