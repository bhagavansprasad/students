#include "stdio.h"
#include "fcntl.h"

int main()
{
	char buff[100];
	int fd,rval,len = 10,pid;
	fd  =  open("t.txt",O_RDONLY, 0);

	pid=fork();
	if(pid==0)
	{
		printf("iam in child :");


		//	while( 1 )
		//	{
		rval=read(fd,buff,len);

		buff[rval]='\0';

		printf("%s\n",buff);


		//		if(rval < len)
		//		  break;
		//	}
		close(fd);

		//return 0;
	}
	else
	{
		printf("iam in parent :");
		sleep(5);
		rval=read(fd,buff,len);
		buff[rval]='\0';
		printf("%s\n",buff);
		close(fd);
	}
}

