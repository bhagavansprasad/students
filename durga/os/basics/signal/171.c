#include<stdio.h>
#include<signal.h>
void abc ();
main()
{
	printf("press the DEL key\n");
	signal(SIGINT, abc);
	signal(SIGINT, abc);
	signal(SIGINT, abc);
   for( ; ;);
}
void abc()
{
	printf("you have to press the DEL key\n");
}
