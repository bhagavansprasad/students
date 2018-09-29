#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 16
main()
{
	char *msg1[3]={"hai","hello","world"};
	char inbuf[MSGSIZE];
	int p[2],pid,i,j;
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		for(i=0;i<3;i++)
		{
			write(p[1],msg1[i],MSGSIZE);
			sleep(1);
		}
	}
	else
	{
		for(j=0;j<3;j++)
		{
			read(p[0],inbuf,MSGSIZE);
			printf("%s\n",inbuf);
			sleep(1);
		}
	}

}
