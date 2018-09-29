#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 16
char *m1="hello";
char *m2="bye";
void parent(int p[])
{
	int nread;
	char buf[MSGSIZE];
	close(p[1]);
	for(;;)
	{
		nread = read(p[0],buf,MSGSIZE);
		if(nread == 0)
		{
			printf("pipe empty\n");
			sleep(1);
		}
		else
		{
			if(strcmp(buf,m2) == 0)
			{
				printf("end of conversation\n");
				exit(0);
			}
			else 
				printf("message is : %s\n",buf);
		}
	}
}

void child(int p[])
{
	int count;
	close(p[0]);
	for(count = 0; count < 3; count++)
	{
		write(p[1],m1,MSGSIZE);
		sleep(3);
	}
	write(p[1],m2,MSGSIZE);
	exit(0);
}
main()
{
	int pfd[2];
	pipe(pfd);
	fcntl(pfd[0],F_SETFL,O_NDELAY);
	if(fork() == 0)
		child(pfd);
	else
		parent(pfd);
}
