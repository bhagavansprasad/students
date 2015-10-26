#include <stdio.h>
#include <fcntl.h>
main()
{
	char buff[100];
	int fd=0,r,l=10,w,fd1;
	fd=open("venky.txt",O_RDONLY,0);
	printf("%d\n",fd);
	fd1=open("b.txt",O_CREAT|O_WRONLY,0777);
	printf("%d\n",fd1);
	while(1)
	{
		r=read(fd,buff,l);
		buff[r]='\0';
		printf("%s",buff);
		w=write(fd1,buff,r);
		if(r<l)
		break;
	}
	close(fd);
	close(fd1);
}
