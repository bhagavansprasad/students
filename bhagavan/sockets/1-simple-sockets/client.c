#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"

main(int argc, char argv[])
{
	int socketfd;
	struct sockaddr_in myclientaddr;
	char buff1[]="This is my first class for TCP/IP";

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	
	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port = htons(9999);

	printf("--->client: Connecting to the server\n");
	connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));

	printf("begin chat\n");

	write(socketfd, buff1, 10);

	close(socketfd);

	return 0;
}
