#include <fcntl.h>

#include<stdio.h>
#include<errno.h>
main()
{
	int fd,fd1, r,w;
	char buf[100];

	fd=open("sample.txt", O_RDWR);
	r=read( fd, buf, 50 );
//	buf[r]='/0';
	printf("%s",buf);
	fd1=open("prasad.txt",O_RDWR|O_CREAT,0777);
    w=write( fd1, buf,r);
	if(w<0)
	{
	perror("not writen:");
	printf("%d",errno);
	}
	
	close(fd);
	printf("%d",fd);
}



