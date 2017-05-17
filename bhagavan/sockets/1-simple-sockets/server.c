#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"

int main()
{
	struct sockaddr_in mysockaddr;
	int socketfd;
	char buffer[100];
	int newfd;
    int retval = 0;

	socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	printf ("S: Opening socket :%d\n", socketfd);

	memset(&mysockaddr, 0, sizeof(mysockaddr));
	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(9999);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	retval = bind(socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr));
	printf ("S: bind retval :%d\n", retval);

	retval = listen(socketfd, 5);
	printf ("S: listen retval :%d\n", retval);

	printf("S : Going for accepting connection \r\n");
	newfd = accept(socketfd, NULL, NULL);
	printf ("S: Accept newfd :%d\n", newfd);

	printf("--->server : Got the connection request from client \r\n");

	retval = read(newfd, buffer, 100);
	buffer[retval]='\0';
	printf("S. Received data from client :'%s'\n", buffer);
	printf ("S: Closing socket\n");
	close(newfd);
	close(socketfd);
	return 0;
}

