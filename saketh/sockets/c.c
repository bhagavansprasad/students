#include <sys/socket.h>
#include <stdio.h>
#include <sys/types.h> 
#include <arpa/inet.h>
#include <stdlib.h>
#include"unistd.h"
#include"string.h"
int main()
{
	int sfd, retval;
	struct sockaddr_in	server_add;
	char buff[128] = "Hello Sunny Saketh";
	sfd = socket(AF_INET, SOCK_STREAM, 0);

	server_add.sin_family = AF_INET;
	server_add.sin_port   = htons(9999);
	server_add.sin_addr.s_addr = inet_addr("10.0.2.15");

	connect(sfd,(struct sockaddr*)&server_add, sizeof(server_add));

	retval = write(sfd, buff, strlen(buff));
	close(sfd);

	return 0;
}

