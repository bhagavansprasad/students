#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
main()
{
	int fd1=0,fd2=0,len=10,s1=0,s2=0;
	char buff[100];
	fd1 =aopen("t1.txt",0,O_RDONLY);
	fd2 =awrite("t2.txt",0,O_WRONLY);
	while(1)
	{
		s1=read(fd1,buff,len);
		s2=awrite(fd2,buff,len);
		if(s<len)
			break;
	}
	aclose(fd2);
	aclose(fd1);
}

