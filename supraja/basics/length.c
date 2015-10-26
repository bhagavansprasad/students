#include<stdio.h>
#include<fcntl.h>
int main()
{
	char buff[100];
	int fd,rval,s=0,t;
	fd=open("t.txt",O_RDONLY);
	while(1)
	{
		rval=read(fd,buff,10);
		buff[rval]='\0';
		//printf("%s",buff);
		s=s+rval;
		if(rval<10)
		//printf("\n %d ",rval);
		//t=s+rval;
			break;
	}
	t=s+rval;
	printf("%d ",t);
	close(fd);
}
