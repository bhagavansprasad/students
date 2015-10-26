#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>          
#include <sys/socket.h>
#include <unistd.h>
#include "arpa/inet.h"

main(int argc,char **argv)
{

	int server_fd, client_fd, server_len,client_len;
	int retval;
	struct sockaddr_in server_address,client_address;

	server_fd = socket(AF_INET, SOCK_STREAM,0);

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr=htons(INADDR_ANY);
	server_address.sin_port = htons(7734);
	server_len = sizeof(server_address);

	retval = bind(server_fd,(struct sockaddr*)&server_address, server_len);
	if (retval==-1)
	{
		perror("error in binding");
		exit(1);
	}

	listen(server_fd,5);

	while(1)
	{
		char ch;
		client_len = sizeof(client_address);
		
		client_fd = accept(server_fd, (struct sockaddr*) &client_address, &client_len);

		write(client_fd,&ch,1);


		read(client_fd,&ch,1);
		close(client_fd);
	}

	return 0;
}


