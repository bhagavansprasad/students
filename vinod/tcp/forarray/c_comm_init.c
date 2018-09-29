#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr

extern int c_sock;
//int c_nsock;

int c_comminit()
{
	struct sockaddr_in server;
	
	//Create socket
	c_sock = socket(AF_INET , SOCK_STREAM , 0);

	if (c_sock == -1)
	{
		printf("Could not create socket");
		return c_sock;
	}
	puts("Socket created");

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( 8888 );

	//Connect to remote server
	if (connect(c_sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror("connect failed. Error");
		return -1;
	}
	puts("Connected to server\n");

	return c_sock;
}
