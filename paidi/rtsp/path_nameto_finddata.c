#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SOCKET_PORT "49154"
#define SOCKET_ADR "192.168.1.3"
#define filename "/home/paidi/students/prem/unix/pipes/unnamed_pipes/students/sudhir/FLV/sixth.flv"

void error(const char *msg);

int main()
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[256];

	fb = fopen(filename, "rb");
	if (fb == NULL)
	{
		printf("File not found!\n");
		return 1;
	}
	else
	{
		fseek(fb, 0, SEEK_END);
		fsize = ftell(fb);
		rewind(fb);

		printf("File contains %ld bytes!\n", fsize);
	}
	fclose(fb);
	close(sockfd);
	return 0;
}
void error(const char *msg)
{
	perror(msg);
	exit(0);

}

