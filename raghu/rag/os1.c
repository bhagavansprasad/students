#include <stdio.h>
#include <fcntl.h>

main()
{
	int fd,pid,len =10,rfd=0,wfd=0,cfd = 0;
	char buff[100];
	fd = open("t.txt",O_RDWR,0);
	pid = fork();
	if(pid == 0)
	{
		//wait();
		rfd = read(fd,buff,len);
		buff[rfd] = '\0';
		printf("the read return value of the parent = %d\n",rfd);
		printf("the read value of the parent = %s\n",buff);
		cfd = close(fd);
		printf("the close return value of the parent = %d\n",cfd);
	}
	else
	{
		wait();
		rfd = read(fd,buff,len);
		buff[rfd] = '\0';
		printf("the read return value of the child = %d\n",rfd);
		printf("the read value of the child = %s\n",buff);
/*		wfd = write(fd,buff,rfd);
		printf("the write return value of the child = %d\n",wfd);
		printf("the write value of the child = %s\n",buff);
*/
	}
}
