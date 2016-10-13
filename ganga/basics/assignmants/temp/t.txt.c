#include<stdio.h>
#include<string.h>
#include<fcntl.h>
int main()
{
	int i,j=0;
	char buff[100];
	int fd=0,rd=0;
	fd=open("t.txt",O_RDONLY,0);
	printf("\n %d",fd);
	rd=read(fd,buff,10);
	rd[buff]='\0';
	printf(" \n%s",buff);
	for(buff[j]=30;buff[j]!='\0';buff[j++])
	{
		rd=read(fd,buff,10);
		rd[buff]='\0';
		printf("%s",buff);
	}
	return rd;
	close(fd);
}
