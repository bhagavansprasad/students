#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"unistd.h"

int main(void)
{
	int socketfd;
	int retval = 0;
	struct sockaddr_in myclientaddr;
	char buffer[]="This is my first program for TCP/IP";

	socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	printf ("C: Opening socket SUCCESS:%d\n", socketfd);

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port = htons(9999);

	printf("C: Connecting to the server\n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	printf ("C: Connect success retval :%d\n", connected);

	printf("Begin chat\n");
	printf ("C: Writing '%s' to server\n", buffer);

	retval = write(socketfd, buffer, strlen(buffer));
	printf ("C: Write retval '%d'\n", retval);

	printf ("C: Closing the socket\n");
	close(socketfd);

	return 0;
}
