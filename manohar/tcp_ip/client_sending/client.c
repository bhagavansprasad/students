#include<stdio.h> 
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>  
int main()
{
	int sock;
	struct sockaddr_in server;
	char message[1000]="hai" , server_reply[2000];

	sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
		printf("Could not create socket");
		return 0;
	}
	printf("Socket created\n");
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( 8888 );

	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror("connect failed. Error");
		return 1;
	}

	printf("Server Connected\n");

	int i=0;
	while(i<1)
	{
		if( send(sock , message , strlen(message) , 0) < 0)
		{
			printf("client:Send failed\n");
			return 1;
		}
	i++;
	}
	close(sock);
	return 0;
}
