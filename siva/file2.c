#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
main()
{
	int fd,val;
	char buff[100];
	fd=open("sd.txt",O_RDONLY);
	if(fd == -1)
	{
		printf("ther is no file\n");
		exit(10);
	}
	while(1)
	{
		val=read(fd,buff,3);
		buff[val]='\0';
		printf("%d\n",val);
		printf("%s\n",buff);
		if(val== 0)
		{
			printf("file read completed\n");
			break;
		}
		
	}
close(fd);
}
