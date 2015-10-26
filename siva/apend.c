#include<stdio.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
main()
{
	int fd1,fd2,val;
	char buff[100];
	fd1=open("s.txt",O_RDONLY);
	if(fd1== -1)
	{
		perror("there is no file\n");
	}
	fd2=open("es.txt",O_WRONLY|O_APPEND);
	while(1)
	{
		val= read(fd1,buff,3);
                buff[val]='\0';
		write(fd2,buff,val);
		if(val<3)
		{
			break;
		}
	}
}

