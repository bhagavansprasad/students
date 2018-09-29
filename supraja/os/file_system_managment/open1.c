#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd,nfd,rval,len=10,pid;
	char buff[100];
	fd=open("t.txt",O_RDONLY);
 //   nfd=dup(fd);
	
	pid=fork();
	//fd=open("t.txt",O_RDONLY);
	if(pid==0)
	{
		printf("iam in child :");
		printf("child fd:%d\n",fd);
//	rval=read(fd,buff,len);
//		write(fd,buff,rval);
//		buff[rval]='\0';
//		printf("%s\n",buff);
		close(fd);
	}
	else
	{
		printf("iam in parent :");
		printf("parent fd:%d\n",fd);
		rval=read(fd,buff,len);
		write(fd,buff,rval);
		buff[rval]='\0';
		printf("%s\n",buff);
//	close(fd);
	}
}
