#include <stdio.h>
#include <fcntl.h>
main()
{
	int rfd,fd,cfd;
	char buff[100];
	//pid = fork();
	//if(pid == 0)	
	fd = open("t.txt",O_RDONLY,0);
	rfd = read(fd,buff,10);
	printf("the read return vaLUE of the read %d\n",rfd);	
	printf("the read vaLUE of the read %s\n",buff);
	cfd = close(fd);
	printf("the close return vaLUE of the read %d\n",cfd);	
}
