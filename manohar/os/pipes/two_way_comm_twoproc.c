#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 64
main()
{
	char *msg1[5]={"hi","how are u","where are u","hello"};
	char *msg2[5]={"hello","fn","bang","bye"};
	char inbuf[MSGSIZE];
	int p[2],c[2],i,read_retval=0,j,pid;
	pipe(p);
	pipe(c);
	pid=fork();

	if(pid>0)
	{
		for(i=0;i<5;i++)
		{
			write(p[1],msg1[i],MSGSIZE);
			sleep(2);
			read_retval=read(c[0],inbuf,MSGSIZE);

			if(read_retval == 0)
			{
				printf("pipe is empty\n");
				exit(0);
			}
			else
			{
				if(strcmp(inbuf,"bye") == 0)
				{
					printf("parent---->%s\n",inbuf);
					printf("end of conversation\n");
					exit(0);
				}
			printf("parent---->%s\n",inbuf);
			}
		}
	}

	else
	{
		for(j=0;j<5;j++)
		{
			read_retval = read(p[0],inbuf,MSGSIZE);
			if(read_retval == 0)
			{
				printf("pipe is empty\n");
				exit(0);
			}
			else
			{
				if(strcmp(inbuf,"bye") == 0)
				{
			
				printf("child---->%s\n",inbuf);
					printf("end of conversation\n");
					exit(0);
				}
				printf("child---->%s\n",inbuf);
			}

			write(c[1],msg2[j],MSGSIZE);
			sleep(3);
		}
	}
	exit(0);
}
