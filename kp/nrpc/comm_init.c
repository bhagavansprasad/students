#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr

int fd = 0;

int get_comm_id(void)
{
	return fd;
}

int set_comm_id(int sock_fd)
{
	return (fd = sock_fd);
}

int init_communication_channel(char *ip_addr, int port)
{	
	int sock_fd;
	struct sockaddr_in server;

	//Create socket
	sock_fd = socket(AF_INET , SOCK_STREAM , 0);
	if (sock_fd == -1)
	{
		printf("Could not create socket\n");
	}
	printf("Socket created\n");

	server.sin_addr.s_addr = inet_addr(ip_addr);
	server.sin_family = AF_INET;
	server.sin_port = htons(port);

	//Connect to remote server
	if (connect(sock_fd , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror("connect failed. Error");
		return 1;
	}

	set_comm_id(sock_fd);

	printf("Connected\n");

	return sock_fd;
}

