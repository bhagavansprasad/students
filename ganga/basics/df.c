#include<stdio.h>
#include<fcntl.h>
int main()
{
	char buff[100];
	int fd=0,rd=0,ld=0;
	fd=open("t.txt",O_RDONLY,0);
	printf("\n%d",fd);
	rd=read(fd,buff,10);
	rd[buff]='\0';
	printf("\n %s ",buff);
	ld = lseek( fd, -10,SEEK_END);
	printf("ld :%d \n",ld);
	rd=read(fd,buff,10);
	rd[buff]='\0';
	printf("rd :%d \n", rd);
	printf("buff :%s\n", buff);
	return rd;
	close(fd);
}
