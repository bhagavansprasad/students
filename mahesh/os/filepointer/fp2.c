#include <stdio.h>
#include <fcntl.h>
main()
{
	int pid;
	int fd1,fd2,rv,len=10;
	char buff[512];
	fd1= open ("t.txt", O_RDONLY  ) ;
	pid=fork();
	if(pid==0)
	{
			rv = read ( fd1, buff,len ) ;
			buff[rv]='\0';
	}
	if(pid>0)
	{
		printf("%s\n",buff);
	}
		close ( fd1) ;
}
