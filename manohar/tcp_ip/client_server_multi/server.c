#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write

int main(int argc , char *argv[])
{
	int socket_desc , client_sock , c , read_size;
	struct sockaddr_in server , client;
	char client_message[2000],message[3][1000]={"hello","iam fine","bye"};
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
		return 0;
	}
	printf("Socket created\n");
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 8888 );
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror("bind failed. Error");
		return 1;
	}
	printf("bind done\n");
	listen(socket_desc , 3);
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if (client_sock < 0)
	{
		perror("accept failed");
		return 1;
	}
	printf("Connection accepted");
	int i=0;
	int retval;
	while(i<=2)
	{
		if( (retval=recv(client_sock , client_message , 2000 , 0)) < 0 )
		{
			printf("server:reciving failed\n");
			return 0;
		}
		client_message[retval]='\0';
		printf("Client request :%s\n",client_message);
		if(send(client_sock ,&message[i][0] , strlen(&message[i][0]),0)< 0)
		{
			printf("server:sending failed\n");
			return 0;
		}
		i++;
	}
	return 0;
}
