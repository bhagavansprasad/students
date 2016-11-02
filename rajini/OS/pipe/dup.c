#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MSGSIZE 16
main()
{
	char m1[MSGSIZE];
	char buff[MSGSIZE];
	int p[2],pid,i;
	pipe(p);
	pid = fork();
	if(pid == 0)
	{
		for(;;)
		{
		//	printf("-->child<--\n");
			read(p[0],buff,MSGSIZE);
			printf("receiving from parent : %s\n",buff);
			if(strcmp(buff,"bye")==0)
			{
				printf("child exiting\n");
				break;
			}
			printf("-->in child<--\n");
			gets(m1);
			write(p[1],m1,MSGSIZE);
			sleep(3);
		}
		exit(0);
	}
	else
	{
		for(;;)
		{
			printf("-->in parent<--\n");
			gets(m1);
			write(p[1],m1,MSGSIZE);
			sleep(2);
			read(p[0],buff,MSGSIZE);
			printf("receiving from child : %s\n",buff);
			if(strcmp(buff,"bye")==0)
			{
				printf("parent exiting\n");
				exit(0);
				break;
			}
		}
		exit(0);
	}
}
