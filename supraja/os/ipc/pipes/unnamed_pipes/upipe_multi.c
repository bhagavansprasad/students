#include<stdio.h>
#include<stdlib.h>
#define MSGSIZE 16
int main()
{
	char *msg1[]={"hai","how are you","bye"};
	char *msg2[]={"hellow","fine","bye"};
	char inbuff[MSGSIZE+1];
	int p[2],pid,i=0,j=0;
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		while(1)
		{
			write(p[1],msg1[i],MSGSIZE+1);
			sleep(3);
			read(p[0],inbuff,MSGSIZE+1);
			printf("parent:%s\n",inbuff);
			if(strcmp(inbuff,"bye")==0)
			{
			exit(1);
			}
			i++;

		}
	}
	else
	{
		while(1)
		{
			read(p[0],inbuff,MSGSIZE+1);
			printf("child:%s\n",inbuff);
			if(strcmp(inbuff,"bye")==0)
			{
			exit(1);
			}
			write(p[1],msg2[j],MSGSIZE+1);
			sleep(3);
			j++;
		}
	}
}
