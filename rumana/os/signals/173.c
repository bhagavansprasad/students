#include<stdio.h>
#include<signal.h>
void abc();
main()
{
signal(SIGINT,abc);
printf("press del key\n");
for(;;);
}
void abc()
{
printf("you have pressd del key \n");
signal(SIGINT,abc);
}
