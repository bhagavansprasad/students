#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
int main(int argc, char *argv[])
{
	char buff[100];
	int rdval=0,wrval=0;
	
	if(argc != 3)
	{
		printf("Incorrect no of arguments\n");
		exit(1);
	}

	int fds = open(argv[1],O_RDONLY);
	int fdt = open(argv[2], O_CREAT | O_RDWR | O_TRUNC , 0664);


	if(fds < 0)
	{
		perror("Unable to open FIRST file because --> ");
		printf("--> errno : %d \n", errno);
		exit(1);
	}

	if(fdt < 0)
	{
		perror("Unable to open SECOND file because --> ");
		printf("--> errno : %d \n", errno);
		exit(1);
	}

	while(1)
	{
		rdval = read(fds,buff,100);
		if(rdval == 0)
			exit(1);
		wrval = write(fdt,buff,rdval);
	}

	return 0;
}
