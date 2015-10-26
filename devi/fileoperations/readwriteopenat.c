#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
main()
{
	char buff[10];
	int fd1,fd2,rval,len=10;
	fd1=open("a.txt",O_RDONLY);
	fd2=openat("ravi","r.txt",0777,O_CREAT|O_RDWR);
	/*while(1)
	{
		rval=read(fd1,buff,len);
		buff[rval]='\0';
	//	printf("%s",buff);
		write(fd2,buff,rval);
		if(rval<len)
			break;
	}*/
	close(fd1);
	close(fd2);
}
