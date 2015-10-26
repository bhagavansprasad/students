#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	int welcomeSocket, newSocket;
	char rbuffer[1024];
	char wbuffer[1024] = "I am server: How are you client ?";
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;
	int rretval = 0, wretval = 0;

	welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(8888);
	//serverAddr.sin_addr.s_addr = inet_addr("192.168.196.135");
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

	bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	if(listen(welcomeSocket,5)==0)
		printf("Listening\n");
	else
		printf("Error\n");

	addr_size = sizeof serverStorage;
	newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);

	rretval = read(newSocket, rbuffer, 100);
	rbuffer[rretval] = '\0';
	printf("-->server: read retval :%d\n", rretval);
	printf("-->server: received data from client :%s\n", rbuffer);

	wretval = write(newSocket, wbuffer, strlen(wbuffer));
	printf("-->server: write retval :%d\n", wretval);



	return 0;
}
