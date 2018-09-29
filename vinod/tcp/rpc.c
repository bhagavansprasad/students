#include <stdio.h>
#include <stdlib.h>
#include "rpc_calls.h"
#include "rpc_structs.h"
#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#define MAX_READ_LEN 100

int c_sock = -1;
asuds d1;
st_dump dmp;

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

	if((c_sock = c_comminit()) == -1)
	{
		printf("Failed to communicate\n");
		exit(1);
	}
	
	
	rpc_open( argv[1], O_RDONLY, 0644);
	fds = d1.asust.rp_open.o_fd;
	printf("\nfirst file fds : %d\n", fds);

	if( fds < 0)
	{
		perror("First file not opens ---> ");
		printf("errno --- >%d \n", d1.asust.rp_open.o_errno);
		exit(1);
	}

	rpc_open( argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);
	fdt = d1.asust.rp_open.o_fd;
	printf("\nsecond file fdt : %d\n", fdt);

	if( fdt < 0)
	{
		perror("Second file not opens ---> ");
		printf("errno --- >%d \n", d1.asust.rp_open.o_errno);
		exit(1);
	}

	while(1)
	{
		rpc_read( fds, buff, MAX_READ_LEN);
		rdval = d1.asust.rp_read.rdval;
				
		if( rdval < 0)
		{
			perror("Error ");
			printf("errno->\n",d1.asust.rp_read.r_errno);
			exit(1);
		}
	
		strcpy(buff, d1.asust.rp_read.buff);
		
		rpc_write( fdt, buff, rdval);
		wrval = d1.asust.rp_write.wrval;
				
		if( wrval < 0)
		{
			perror("Error ");
			printf("errno->\n",d1.asust.rp_write.w_errno);
			exit(1);
		}

		if(rdval < MAX_READ_LEN)
			break;
	}

	rpc_close( fds );
	flag = d1.asust.rp_close.c_retval;
	
	if(flag == -1)
	{
		perror(" ---> Unable to close first file <---\n");
		printf("errno --- >%d\n",  d1.asust.rp_close.c_errno);
	}

	rpc_close( fdt );
	flag = d1.asust.rp_close.c_retval;
	
	if(flag == -1)
	{
		perror(" ---> Unable to close second file <---\n");
		printf("errno --- >%d\n",d1.asust.rp_close.c_errno);
	}

	printf("\n---> Task done and exiting client <---\n\n");

	return 0;
}
