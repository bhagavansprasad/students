#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
main()
{
	char buff[100];
	int fd1,s11=0,fd2,s=0,i;
	fd1=open("t1.txt",O_RDONLY);
	fd2=open("t3.txt",O_WRONLY);
	printf("%d",fd2);
	if(fd2<0)
	perror("fd2");
	while(1)
	{
		s=read(fd1,buff,10);
		s11=write(fd2,buff,10);
		//printf("%d",s11);
		buff[s]='\0';
		printf("%s",buff);
		//printf("%d",f);
		if(s<10)
			break;	
	}
}
