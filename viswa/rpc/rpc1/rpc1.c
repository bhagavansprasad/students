#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

main()
{
	int fd1=-1,fd2=-1,s=0,s2=0,len=10;
	char buff[100];
	fd1 = open("t1.txt",O_RDONLY);
	fd2 =open("t2.txt",O_WRONLY);
	while(1)
	{
		s=read(fd1,buff,len);
		write(fd2,buff,len);
		if(s<len)
			break;
	}
	close(fd1);
	close(fd2);
}
