#include<stdio.h>
#include<signal.h>
void sigkey();
main()
{
	printf("press the DEL key\n");
	signal(SIGINT, sigkey);
	signal(SIGQUIT, sigkey);
   for( ; ;);
}
void sigkey(signo)
int signo;
{
	printf("you have killed the process with signal NO is %d\n",signo);
}

