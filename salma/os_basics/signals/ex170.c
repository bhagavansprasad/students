#include<stdio.h>
#include<signal.h>
void abc();
main()
{
printf("Press <Del> key.\n");
signal(SIGINT,abc);
for(;;);
}
void abc()
{
printf("you have pressed the <Del> key\n");
}
