#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


#define MSGSIZE 16
int main()
{
	char buff[100];
	char *msg1="aura networks";
	int fd,pid;
	fd=open("testfilelseek",O_RDONLY);
	pid=fork();
	if(pid>0)
	{
		write(fd,msg1,MSGSIZE);
	}
	else
	{
		read(fd,buff,MSGSIZE);
		printf("%s\n",buff);
	}
	exit(0);
}
