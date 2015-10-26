#include<stdio.h> 
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>  
int main()
{
	int sock;
	struct sockaddr_in server;
	char message[3][1000]={"hai","how are you","bye"} , server_reply[2000];

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
	int retval;
	while(i<=2)
	{
		if( send(sock , &message[i][0] , strlen(&message[i][0]) , 0) < 0)
		{
			printf("client:Send failed\n");
			return 1;
		}
		if( (retval=recv(sock , server_reply , 2000 , 0)) < 0)
		{
			printf("client:recv failed\n");
			break;
		}
		server_reply[retval]='\0';
		printf("Server reply :%s\n",server_reply);
	i++;
	}
	close(sock);
	return 0;
}
