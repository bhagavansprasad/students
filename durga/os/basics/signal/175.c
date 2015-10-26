#include<stdio.h>
#include<signal.h>
void sigkey();
main()
{
	printf("press the DEL key\n");
	signal(SIGQUIT, sigkey);
   for( ; ;);
}
void sigkey()
{
	printf("recive the siganl\n");
}

