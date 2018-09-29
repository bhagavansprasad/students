#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

int main()
{
	int socketfd;
	struct sockaddr_in mysockaddr;
	char buff1[3][20] = {"hellow", "i am fine", "bye"};
	char buff[100];
	int retval = 0, i;
	int newfd;
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("failed to create a socket\n");
		exit(1);
	}

    memset(&mysockaddr, 0, sizeof(mysockaddr));
	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_addr.s_addr = INADDR_ANY;
	mysockaddr.sin_port = htons(7898);
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
	printf("server : going for accepting connection\r\n");
	newfd = accept(socketfd, NULL, NULL);
	if(newfd == -1)
	{
		perror("accept system call failed\r\n");
		close(socketfd);
		exit(1);
	}
	printf("server : got the connection request from client\r\n");

		retval = read(newfd, buff, 30);
		buff[retval] = '\0';
		printf("server : receive from client : %s\r\n", buff);
		retval = write(newfd, &buff1[i], 20);
		printf("server : buff1 write retval : %d\n", retval);
	close(socketfd);
	return 0;
}

