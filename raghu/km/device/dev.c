#include <stdio.h>
#include <fcntl.h>

main()
{
	int fd,wfd,rfd;
	char buff[100];
	fd = open("/dev/chardev",O_RDWR,0777);

	if(fd < 0)
	 perror("error is : ");

	printf("fd-->%d\n",fd);

	while(1)
	{
		rfd=read(fd,buff,10);
		buff[rfd]='\0';
		printf("%s",buff);
		if(rfd<10)
			break;
	}
	wfd = write(fd,buff,rfd);
	printf("write %d\n",wfd);
		printf("%s",buff);
	if(wfd < 0)
	{
		perror("write failed   :");
	}
	close(fd);
}
