#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write

extern int s_sockfd;
extern int nsockfd;

int s_comminit()
{
	struct sockaddr_in server, client;
	int c;

	//Create socket
	s_sockfd = socket(AF_INET , SOCK_STREAM , 0);
	if (s_sockfd == -1)
	{
		printf("Could not create socket");
		return s_sockfd; 
	}
	puts("Socket created");

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 8888 );

	//Bind
	if( bind(s_sockfd,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		//print the error message
		perror("bind failed. Error");
		return -1;
	}
	puts("bind done");

	//Listen
	listen(s_sockfd, 3);

	//Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);

	//accept connection from an incoming client
	nsockfd = accept(s_sockfd, (struct sockaddr *)&client, (socklen_t*)&c);
	if (nsockfd < 0)
	{
		perror("accept failed");
		return -1;
	}
	puts("Connection accepted");
	return s_sockfd;
}
