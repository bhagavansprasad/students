#include<stdio.h>
#define MSGSIZE 16
main()
{
	char *msg1[]={"hai","how r u","bye"};
	char *msg2[]={"hello","am fine","bye"};
	int p[2],pid,i=0,j=0;
	char inbuf[MSGSIZE];
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		while(1)
		{
			write(p[1],msg1[i],MSGSIZE);
			sleep(2);
			read(p[0],inbuf,MSGSIZE);
			printf("parent:%s\n",inbuf);
			if(strcmp(inbuf,"bye")==0)
			{
				break;
			}
			i++;
		}
	}
	else
	{
		while(1)
		{
			read(p[0],inbuf,MSGSIZE);
			printf("chaild : %s\n",inbuf);
			write(p[1],msg2[j],MSGSIZE);
			sleep(2);
			if(strcmp(inbuf,"bye")==0)
			{
				break;
			}
			j++;
		}
	}
}
