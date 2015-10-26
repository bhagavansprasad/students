#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#define MSGSIZE 32
char *msg1="helloworld";
char *msg2="hai how are you";
char *msg3="bye";
main()
{
	int pfd[2],j,pid;
	pipe(pfd);
//	fcntl(pfd[0],F_SETFL,O_NDELAY);
	if(fork()== 0)
		child(pfd);
	else
		parent(pfd);
}
parent(p)
	int p[2];
{ 
	int nread;
	char buf[MSGSIZE];
	close(p[1]);
	for(;;)
	{
		nread=read(p[0],buf,MSGSIZE);
		if(nread==0)
		{
			printf("pipe is empty\n");
			sleep(1);
		}
		else
		{
			if(strcmp(buf,msg3) == 0)
			{	
				printf("%s\n",msg3);
				printf("conversion is closed\n");
				exit(0);
			}
			else
				printf("MSG=====>%s\n",buf);
		}

	}
}

child(p)
	int p[2];
{
	int count;
	close(p[0]);
//	for(count=0;count<3;count++)
	{
		write(p[1],msg1,MSGSIZE);
	write(p[1],msg2,MSGSIZE);
		sleep(3);
	}
	
	write(p[1],msg3,MSGSIZE);
	exit(0);
}



