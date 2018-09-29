#include <stdio.h>
#include <stdlib.h>
#include "rpc.h"
#include "rpcstructs.h"
#define MAX_READ_LEN 100

int main(int argc, char *argv[])
{
	char buff[MAX_READ_LEN];
	int rdval=0, wrval=0, flag=0;
	int fdt = -1, fds = -1;

	if(argc != 3)
	{
		printf("-------> Incorrect no of arguments <-------\n");
		exit(1);
	}

	fds = rpc_open( argv[1], O_RDONLY, 0644);
	if( fds < 0)
	{
		perror("First file not opens ---> ");
		printf("errno --- >%d \n", errno);
		exit(1);
	}

	fdt = rpc_open( argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if( fdt < 0)
	{
		perror("Second file not opens ---> ");
		printf("errno --- >%d \n", errno);
		exit(1);
	}

	while(1)
	{
		rdval = rpc_read( fds, buff, MAX_READ_LEN);
		wrval = rpc_write( fdt, buff, rdval);

		if(rdval < MAX_READ_LEN)
			break;
	}

	flag = rpc_close( fds );
	if(flag == -1)
	{
		perror(" --------- > Unable to close first file < ---------\n");
		printf("errno --- >%d\n", errno);
	}

	flag = rpc_close( fdt );
	if(flag == -1)
	{
		perror(" --------- > Unable to close second file < ---------\n");
		printf("errno --- >%d\n", errno);
	}

	return 0;
}
