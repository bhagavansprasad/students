#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"

int main(void)
{
	struct sockaddr_in mysockaddr;
	int socketfd;
	char rbuffer[1024];
	int newfd;
	int retval,sd_retval;


	socketfd = socket(AF_INET, SOCK_STREAM, 0);

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(9999);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	bind(socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr));
	listen(socketfd, 5);
	newfd = accept(socketfd, ((struct sockaddr *)&mysockaddr), &sd_retval);
	retval = read(newfd, rbuffer, 50);
	rbuffer[retval]='\0';
	printf("Server: Received data from client :%s\n", rbuffer);
	close(newfd);
	close(socketfd);

	return 0;
}
