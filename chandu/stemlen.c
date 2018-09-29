#include<stdio.h>
#include <fcntl.h>
#include <string.h>

main()
{
	char buffer[100];
	int revtal=0,l=10,a=0;
	int fd;
	fd=open("r.txt",O_RDONLY);
	while(1)
	{
	revtal=read(fd,buffer,l);
	a=a+revtal;
			buffer[revtal]='\0';
			printf("%s",buffer);
		if(revtal<l)
		{
		//	printf("%s\n",buffer);
			break;

		}
	//	printf("%d",revtal);
	}
	
		printf("%d\n",a);
	close(fd);
}
