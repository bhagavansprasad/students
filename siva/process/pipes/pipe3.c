#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void abc();
main()
{
	int pid,p[2],val;
	char *msg="AuRA NETWORKS";
	char inbuff[25];
	pipe(p);
	signal(SIGPIPE,abc);
	pid=fork();
	if(pid==0)
	{
	//close(p[1]);
	//sleep(5);
	printf("child exiting\n");
		}
	else
	{
	close(p[0]);
	val=write(p[1],inbuff,10);
	printf("value returned%d\n",val);
    printf("parent Existing\n"); 
	}
}
void abc()
{
printf("parent failed\n");
}
