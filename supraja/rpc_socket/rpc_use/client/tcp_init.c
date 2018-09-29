#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
int client_sock_fd = -1;

int tcp_client_init(void)
{
	printf("%d %s \n ",__LINE__,__FILE__);
	int connected;
	struct sockaddr_in myclientaddr;

	client_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(client_sock_fd == -1)
	{
		perror("--->client: Failed to create a socket \n");
		exit(1);
	}

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("192.168.0.30 ");
	myclientaddr.sin_port = htons(10000);

	printf("--->client: Connecting to the server\n");
	connected = connect(client_sock_fd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed\n");
		close(client_sock_fd);
		exit(1);
	}

	return 0;
}

