#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"unistd.h"
#include"string.h"

int main(void)
{
	int socketfd;
	int connected;
	struct sockaddr_in myclientaddr;
	char buff[]="Hi, I am client, how are you server";
	int retval = 0;

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

	//read and write via sockfd
	write(socketfd, buff, strlen(buff));
	retval = read(socketfd, buff, sizeof(buff));
	buff[retval] = '\0';
	printf("-->C: Got the reply from  .....:%s\n",buff);

	close(socketfd);

	return 0;

}
