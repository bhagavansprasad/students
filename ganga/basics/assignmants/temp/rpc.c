#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	char buff[100];
	int fd1=0, fd2 = 0, rd=0, ld=0, wd = 0;

	fd1=open("t.txt",O_RDONLY,0);
	printf("fd :%d\n",fd1);

	fd2 = open("s.txt", O_WRONLY, 0);
	printf("fd :%d\n",fd2);

	rd=read(fd1,buff,10);
	rd[buff]='\0';
	printf("buff : %s \n ",buff);

	wd = write(fd2, buff,10);
	printf("wd :%d \n", wd);
	wd[buff]='\0';
	printf("buff :%s \n",buff);


	ld = lseek( fd1, -10,SEEK_END);
	printf("ld :%d \n",ld);

	rd=read(fd1,buff,10);
	rd[buff]='\0';
	printf("rd :%d \n", rd);

	wd = write(fd2, buff,10);
	printf("wd :%d \n", wd);
	wd[buff]='\0';
	printf("buff :%s \n",buff);

	return wd;
	close(fd1);
	close(fd2);
}
