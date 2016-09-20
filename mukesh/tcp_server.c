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
	char buffer[100];
	int newfd;
	char buff[]="Hi Client, I am fine...server";
	int retval = 0;

	socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(socketfd == -1)
	{
		perror("failed to  create a socket \r\n");
		exit(1);
	}

	memset(&mysockaddr, 0, sizeof(mysockaddr));

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(8888);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr)) == -1)
	{
		perror("bind system call failed\r\n");
		close(socketfd);
		exit(1);
	}

	if(listen(socketfd, 5) == -1)
	{
		perror("listen system call failed\r\n");
		close(socketfd);
		exit(1);
	}

	printf("--->server : waiting from connection..\r\n");
	newfd = accept(socketfd,NULL,NULL);
	if(newfd == -1)
	{
		perror("accept system call failed\r\n");
		close(socketfd);
		exit(1);
	}

	printf("--->server : Got the connection request from client \r\n");

	retval = read(newfd, buffer, 30);
	buffer[retval] = '\0';

	printf("--->S. Got the message from client .... :%s\n",buffer);

	write(newfd, buff, strlen(buff));

	shutdown(socketfd, SHUT_RDWR);

	close(socketfd);

	return 0;

}





