#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd=open("t.txt",O_RDONLY);
	int pid=fork(),length=20;
	char buffer[512];
	if(pid>0)
	{
		//lseek(fd,20l,0);
		int rv=read(fd,buffer,length);
		buffer[length]='\0';
		printf("%s\n",buffer);
	}
	if(pid==0)
	{
		lseek(fd,20l,0);
		int rv=read(fd,buffer,length);
		buffer[length]='\0';
		printf("\n%s\n",buffer);
	}
}
