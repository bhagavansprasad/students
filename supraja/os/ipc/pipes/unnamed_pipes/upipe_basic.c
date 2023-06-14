#include<stdio.h>
#define MSGSIZE 16
int main()
{
	char *msg1={"hai"};
	char *msg2={"hellow"};
	char inbuff[MSGSIZE];
	int p[2],pid,i;
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		write(p[1],msg1,MSGSIZE);
		sleep(10);
		read(p[0],inbuff,MSGSIZE);
		printf("parent:%s\n",inbuff);
	}
	else
	{
		sleep(5);
		read(p[0],inbuff,MSGSIZE);
		printf("child:%s\n",inbuff);
		write(p[1],msg2,MSGSIZE);
		sleep(15);
	}
}
