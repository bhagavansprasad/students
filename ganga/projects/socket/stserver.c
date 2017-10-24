/***************server code***************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include "defs.h"

int main()
{
	int welcomeSocket, newSocket;
	//  char buffer[256];
	struct data bdata;
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;

	welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(8080);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

	bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	if(listen( welcomeSocket, 5) == 0)

		printf("Listening\n");
	else
		printf("Error\n");

	addr_size = sizeof serverStorage;
	newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);

	recv(newSocket, &bdata, sizeof(bdata), 0);
	printf("Data received: %d \n", bdata.length);
	printf("Data received: %s \n", bdata.buff);

	strcpy(bdata.buff, "Hello, i am server");
	bdata.length = 10;
	send(newSocket, &bdata, sizeof(bdata), 0);

	return 0;
}                                          
