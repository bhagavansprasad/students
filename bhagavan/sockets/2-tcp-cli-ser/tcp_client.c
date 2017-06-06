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
	int connected, retval = 0;
	struct sockaddr_in myclientaddr;
	char buff[30]="hi server im fine";

	socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(socketfd == -1)
	{
		perror("Failed to create a socket \r\n");
		exit(1);
	}

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port = htons(8888);

	printf("client : Connecting to the server\r\n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("connect system call failed\r\n");
		exit(1);
	}

	sleep(5);
	//read and write via sockfd
	retval = write(socketfd, buff, sizeof(buff));
	if (retval <= 0)
	{
		perror("Write failed\n");
		printf("Write failed :%d\n", retval);
		close(socketfd);
		exit(1);
	}

	sleep(5);
	retval = read(socketfd, buff, sizeof(buff));
	if (retval <= 0)
	{
		perror("Read failed\n");
		printf("Read failed :%d\n", retval);
		close(socketfd);
		exit(1);
	}

	buff[retval] = '\0';
	printf("string read from server:%s\r\n", buff);

	close(socketfd);

	return 0;
}

