#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int i,fd=0,p;
	char buff[100];
	fd=open("p.txt",0,O_RDONLY);
	for(i=0;i<=p;i++)
	{
		p=read(fd,buff,11);
		buff[p]='\0';
		printf("%s",buff);
		printf("%d",p);
	}
	close(fd);
}
