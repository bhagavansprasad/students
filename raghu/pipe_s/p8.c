#include <stdio.h>

main()
{
	int i,pid,p[2];
	char *msg = "hello";
	char inbuff[10];
	pipe(p);
	pid = fork();

	if(pid == 0)
	{
		write(p[1],msg,10);
	}
	else
	{
		sleep(1);
		write(p[1],msg,10);
		for(i=0;i<2;i++)
		{
			read(p[0],inbuff,10);
			printf("the first read valu = %s\n",inbuff);
		}
	}
}
