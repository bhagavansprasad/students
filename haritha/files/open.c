#include<stdio.h>
#include<fcntl.h>
main()
{
	char buff[100];
	int fd=0,ret,i;
	for(i=0;i<=100;i++)
		while(1)
		{
			fd=open("t.txt",0,O_RDONLY);
			ret=read(fd,buff,10);
			//ret=read(fd,buff,10);
			//	printf("%d\n",ret);
				buff[ret]='\0';
			printf("%s\n",buff);
			if(i>=buff)
			{
				break;
			}
		}
	close(fd);
}
