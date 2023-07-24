#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int sockfd = 0;
	char recvBuff[1024];
	char sendBuff[1024] = "Hello world";
	struct sockaddr_in serv_addr;
	int retval = 0;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(5000);

	connect (sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	retval = send(sockfd, sendBuff, strlen(sendBuff), 0);
	retval = recv(sockfd, recvBuff, sizeof(recvBuff), 0);
	printf("C: recv retval :%d\n", retval);
	recvBuff[retval] = '\0';

	printf("Server response :%s\n", recvBuff);

	close(sockfd);

	return 0;
}
