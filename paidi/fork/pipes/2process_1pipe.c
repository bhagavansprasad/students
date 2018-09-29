#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define  paidi 20 
int retval = 0;
char s1[3][20] = {"hello,world1","sudha","ravi"};
char s2[] = "aura network";

main()
{ 
	char buf[paidi];
	int p[2],pid,i;

	pipe(p);
//	fcntl(p[0],F_SETFL,O_NDELAY);
	pid = fork();

	if(pid == 0)
	{
		printf("s1--->%s\n",s1);
		close(p[0]);
		for(i=0;i<3;i++)
		{
			write(p[1],s1[i],paidi);
			sleep(2);
		}
		write(p[1],s2,paidi);
		exit(0);
	}
	else
	{
		close(p[1]);
		for( ; ; )
		{
			retval = read(p[0],buf,paidi);
			if(retval == 0)
			{
				printf("the pipe is empty\n");
				exit(0);
			}
			else
			{
				if(strcmp(buf,s2) == 0)
				{
					printf("end converston\n");
					exit(0);
				}
				else
				{
					printf("mesage---->= %s\n",buf);
			//		sleep(2);
				}
			}
		}
	}
}
