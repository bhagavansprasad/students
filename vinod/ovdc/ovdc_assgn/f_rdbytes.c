#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

int main()
{
	unsigned int i=0;
	unsigned char buff[3]={0};
	int fc=0;
	int fd = open("myown.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		exit(0);
	}
	for(i=0 ; i<256 ; i++)
	{
		sprintf(buff,"%X ",i);
		printf("%s", buff);
		if(i<=15)
			write(fd, buff, 2);
		else
			write(fd, buff, 3);
	}
	if(close(fd)<0)
		perror("fail to close the file:");
	printf("\n");
	return 0;
}
