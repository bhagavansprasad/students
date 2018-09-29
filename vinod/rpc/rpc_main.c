#include <stdio.h>
#include <stdlib.h>
#include "rpcstructs.h"

int rpc_fop(struct a_open *, struct a_read *, struct a_write *, struct a_lseek *, struct a_close *);

int main(int argc, char *argv[])
{
	char buff[100];
	int rdval=0, wrval=0;
	int fds=0, fdt=0;
	
	if(argc != 3)
	{
		printf("-------> Incorrect no of arguments <-------\n");
		exit(1);
	}

	struct a_open rpc_open1 = {argv[1], O_RDONLY , 0644};

	fds = rpc_fop( & rpc_open1, NULL, NULL, NULL, NULL );

	if( fds < 0)
	{
		perror("First file not opens ---> ");
		printf("errno --- >%d \n", errno);
		exit(1);
	}

	struct a_open rpc_open2 = {argv[2], O_RDWR | O_CREAT | O_TRUNC , 0644};
	
	fdt = rpc_fop( & rpc_open2, NULL, NULL, NULL, NULL );

	if( fdt < 0)
	{
		perror("Second file not opens ---> ");
		printf("errno --- >%d \n", errno);
		exit(1);
	}

	while(1)
	{
		struct a_read rpc_read = { fds, buff, 100};
		
		rdval = rpc_fop( NULL, & rpc_read, NULL, NULL, NULL );
		
		struct a_write rpc_write = { fdt, buff, rdval};
		
		wrval = rpc_fop( NULL, NULL, & rpc_write, NULL, NULL );
		
		if(rdval < 100)
			break;
	}

	struct a_close rpc_close1 = { fds };
	
	rpc_fop( NULL, NULL, NULL, NULL, & rpc_close1 );

	struct a_close rpc_close2 = { fdt };
	
	rpc_fop( NULL, NULL, NULL, NULL, & rpc_close2 );

	return 0;
}
