#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	int i, welcomeSocket, newSocket;
	char buffer[256];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;

	welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
	printf("-->welcome Socket : %d\n", welcomeSocket);

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(8080);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero); 

	int b = bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
	printf("--> bind: %d \n", b);

	if(listen(welcomeSocket, 5) == 0)

		printf("Listening\n");
	else

		printf("Error\n");

	addr_size = sizeof serverStorage;
	newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
	printf("-->new Socket : %d\n", newSocket);

	for( ; ; )
	{
		recv(newSocket, buffer, 256, 0);
		printf("Data received: %s",buffer);  

		strcpy(buffer, "Hello, i am from server \n");
		send(newSocket, buffer, 100, 0);
	}
	return 0;
}
