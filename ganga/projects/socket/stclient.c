/****************** CLIENT CODE ****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include "defs.h"

int main()
{
	int clientSocket;
	struct data bdata;
	struct sockaddr_in serverAddr;
	socklen_t addr_size;

	clientSocket = socket(PF_INET, SOCK_STREAM, 0);

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(8080);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero); 

	addr_size = sizeof serverAddr;
	connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

	strcpy(bdata.buff, "Hai,i am client");
	bdata.length = 10;
	send(clientSocket, &bdata, 100, 0);

	recv(clientSocket, &bdata, 256, 0);
	printf("Data received: %s \n",bdata.buff);
	printf("Data received: %d \n",bdata.length);

	return 0;
}

