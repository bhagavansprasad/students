#include<stdio.h>
#include<signal.h>

main()
{
	printf("press the DEL key\n");
	signal(SIGINT, SIG_IGN);
   for( ; ;);
}

