/* Create to Socket and Connect to Server */

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

int init_communication_channel_server(int port)
{	
	int sock_fd,client_sock,c;

	int client;

	struct sockaddr_in server;
	//Create socket
	sock_fd = socket(AF_INET , SOCK_STREAM , 0);
	if (sock_fd == -1)
	{
		printf("Could not create socket\n");
	}
	printf("-->Socket created fd :%d\n", sock_fd);

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);

	//Bind
	if( bind(sock_fd,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		//print the error message
		perror("Bind failed ");
		return 1;
	}
	printf("-->Bind success\n");

	printf("-->Listening.....\n");
	//Listen
	listen(sock_fd , 3);

	//Accept and incoming connection
	printf("-->Waiting for incoming connections...\n");
	c = sizeof(struct sockaddr_in);
	client_sock = accept(sock_fd, (struct sockaddr *)&client, (socklen_t*)&c);
	if (client_sock < 0)
	{
		perror("accept failed\n");
		return 1;
	}
	printf("-->Connection accepted client_sock :%d\n", client_sock);

	set_comm_id(client_sock);

	printf("Connected\n");

	return client_sock;
}

