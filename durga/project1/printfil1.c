#include<stdio.h>
#include<fcntl.h>
main()
{
	int fd, fd1, r, w, ln=20;
	char buf[100];
	
	fd = open("prasad.c",O_RDONLY);
	fd1 = open("b.txt", O_WRONLY);
	
	r = read(fd, buf,ln);
	buf[r]='\0';
	w = write( fd1, buf,r);
	
	lseek(fd, -20l,2);
	
	r = read(fd, buf,ln);
	buf[r]='\0';
	w = write(fd1,buf,r);
	
	close(fd);
	close(fd1);
	}




