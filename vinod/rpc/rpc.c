#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "rpc.h"

int main(int argc, char *argv[])
{
	char buff[100];
	int rdval=0, wrval=0;

	if(argc != 3)
	{
		printf("-------> Incorrect no of arguments <-------\n");
		exit(1);
	}

	int fds = rpc_open( argv[1], O_RDONLY, 0644);

	if( fds < 0)
	{
		perror("First file not opens ---> ");
		printf("errno --- >%d \n", errno);
		exit(1);
	}

	int fdt = rpc_open( argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);

	if( fdt < 0)
	{
		perror("Second file not opens ---> ");
		printf("errno --- >%d \n", errno);
		exit(1);
	}

	while(1)
	{
		rdval = rpc_read( fds, buff, 100);
		wrval = rpc_write( fdt, buff, rdval);
		if(rdval < 100)
			exit(1);
	}

	return 0;
}
