#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int socketfd;
	int connected;
	struct sockaddr_in myclientaddr;
	char buff1[3][20] = {"hi", "how are you", "bye"};
	char sbuff[1024];
	int retval = 0, i;
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("client : failed to create a socket\n");
		exit(1);
	}
	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("192.168.0.104");
	myclientaddr.sin_port = htons(7898);
	printf("client : connect to the server\n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("client : connect system call failed\n");
		close(socketfd);
		exit(1);
	}
		retval = write(socketfd, &buff1[i], 20);
		printf("client : write buff1 retval : %d\n", retval);
		retval = read(socketfd, sbuff, sizeof(sbuff));
		sbuff[retval]= '\0';
		printf("client : buffer read from server : %s\n", sbuff);
	close(socketfd);
	return 0;
}
