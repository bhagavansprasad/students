#include "stdio.h"
#include <stdlib.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <unistd.h>
#include "arpa/inet.h"

int main(int argc,char **argv)
{

	char ch ='A';

	int client,return_val,client_len;

	struct sockaddr_in address;

	client = socket(AF_INET,SOCK_STREAM,0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(7734); 
	
		client_len = sizeof(address);
		return_val = connect (client, (struct sockaddr*)&address, &client_len);
		if(return_val == -1)
		{
			printf("error in  connection");
			exit(1);
		}

		write(client,&ch,1);

		read(client,&ch,1);
		printf("-->%c \n \r",ch);
		close(client);
	
}



