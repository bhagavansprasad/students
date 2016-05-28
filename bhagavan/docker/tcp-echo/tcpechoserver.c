/*
 * tcpserver.c - A simple TCP echo server
 * usage: tcpserver <port>
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

void error(char *msg) 
{
	perror(msg);
	exit(1);
}

int main(int argc, char **argv) 
{
	int parentfd;
	int childfd; 
	int portno; 
	int clientlen; 
	struct sockaddr_in serveraddr;
	struct sockaddr_in clientaddr;
	struct hostent *hostp;
	char buf[BUFSIZE];
	char *hostaddrp; 
	int optval; 
	int n;

	if (argc != 2) 
	{
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(1);
	}
	portno = atoi(argv[1]);
	printf("starting on %i\n", portno);

	printf("create parent socket ... ");
	fflush(stdout);
	parentfd = socket(AF_INET, SOCK_STREAM, 0);
	if (parentfd < 0)
		error("ERROR opening socket");
	printf("OK\n");

	printf("setup/build IP:port ... ");
	fflush(stdout);

	optval = 1;
	setsockopt(parentfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval , sizeof(int));

	bzero((char *) &serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons((unsigned short)portno);
	printf("OK\n");

	printf("binding parent socket ... ");
	fflush(stdout);
	if (bind(parentfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
		error("ERROR on binding");
	printf("OK\n");

	printf("listen ... ");
	fflush(stdout);
	if (listen(parentfd, 5) < 0) 
		error("ERROR on listen");

	printf("OK\n");

	clientlen = sizeof(clientaddr);

	printf("main loop starting\n");

	while (1) 
	{

		printf("    waiting for request ... ");
		fflush(stdout);
		childfd = accept(parentfd, (struct sockaddr *) &clientaddr, &clientlen);
		if (childfd < 0)
			error("ERROR on accept");
		printf("RECIEVED\n");

		printf("    |determining host\n");
		fflush(stdout);

		printf("    |    hostp->h_name:");
		fflush(stdout);

		hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, sizeof(clientaddr.sin_addr.s_addr), AF_INET);
		if (hostp == NULL)
			error("ERROR on gethostbyaddr");
		printf("%s\n", hostp->h_name);

		printf("    |    hostaddrp=");
		fflush(stdout);
		hostaddrp = inet_ntoa(clientaddr.sin_addr);
		if (hostaddrp == NULL)
			error("ERROR on inet_ntoa\n");
		printf("%s\n", hostaddrp);

		printf("    |reading\n");
		bzero(buf, BUFSIZE);
		printf("    |    [");
		fflush(stdout);
		n = read(childfd, buf, BUFSIZE);
		if (n < 0)
			error("ERROR reading from socket");

		printf("%s]\n", buf);

		printf("    |writing\n");
		printf("    |    [");
		fflush(stdout);
		n = write(childfd, buf, strlen(buf));
		if (n < 0)
			error("ERROR writing to socket");
		printf("%s]\n", buf);

		printf("    |closing\n");
		close(childfd);
		printf("    |    closed\n");
	}
}
