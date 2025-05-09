#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int udpSocket, nBytes, retval = 0;
	char buffer[1024];
	struct sockaddr_in serverAddr, clientAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size, client_addr_size;
	int i;

	udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

	bind(udpSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

	addr_size = sizeof serverStorage;

	nBytes = recvfrom(udpSocket, buffer, 1024, 0, (struct sockaddr *)&serverStorage, &addr_size);
	printf ("S: recvfro retval :%d\n", nBytes);
	printf ("S: data received from client :%s\n", buffer);

	for(i = 0; i < nBytes-1; i++)
		buffer[i] = toupper(buffer[i]);

	retval = sendto(udpSocket, buffer, nBytes, 0, (struct sockaddr *)&serverStorage, addr_size);
	printf ("S: sendto retval :%d\n", retval);

	sleep(3);
	close(udpSocket);

	return 0;
}
