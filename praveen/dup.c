#include <stdio.h>
#include <fcntl.h>
main()
{
	int i;
	int fd,dfd,pid,cpfd,cpdfd;
	char buff[100];
	fd = open("t.txt",O_RDONLY,0);
	printf("the fd value is = %d\n",fd);
	dfd = dup(fd);
	printf("the dfd value is = %d\n",dfd);
	pid = fork();
	if(pid == 0)
	{
		read(fd,buff,10);
		printf("the valu in the buff is fd %s\n",buff);
		close(fd);
	}
	else
	{
		wait();
		//cpfd = close(fd);
		cpdfd = close(dfd);
		printf("the close value is %d\n",cpdfd);
		read(dfd,buff,10);
		printf("the valu in the buff is dfd %s\n",buff);
		read(fd,buff,10);
		printf("the valu in the buff is fd %s\n",buff);
	}
}
