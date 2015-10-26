#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF 1024
int main()
{
	int fd;
	char buf[MAX_BUF];
	char ch='c';
	int i;
	fd = open("testpipesize", O_RDWR);
	for(i=0;;i++)
	{
		printf("--------->:%d\n",i+1); 
		int	rval=	write(fd,&ch,1);
		if(rval!=1)
		{
			printf("write systemcall failed");
			break;

		}
	}
}
