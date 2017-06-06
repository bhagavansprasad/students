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
    int retval = 0,i;

	socketfd = socket(AF_INET, SOCK_STREAM, 0);

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(9999);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	bind(socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr));

	listen(socketfd, 5);

	printf("--->server : Going for accepting connection \r\n");
	newfd = accept(socketfd, NULL, NULL);

	printf("--->server : Got the connection request from client \r\n\n");
	retval = read(newfd, buffer, 50);
	buffer[retval]='\0';
	printf("S. data from client :%s\n", buffer);
	close(socketfd);
	return 0;
}


