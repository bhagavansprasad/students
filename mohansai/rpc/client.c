/*
** talker.c -- a datagram "client" demo
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "cl_se.h"
#define MAXBUFLEN 100

#define SERVERPORT "4950"	// the port users will be connecting to
FILE *fd;
int main(int argc, char *argv[])
{
	int sockfd,i=0;
	struct addrinfo hints, *servinfo, *p;
	int rv;
	int numbytes;
	char buffer[100];
	int bytesread2;
	info data;
	
	if (argc != 3) {
		fprintf(stderr,"usage: talker hostname message\n");
		exit(1);
	}

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;

//  int getaddrinfo(const char *node, const char *service,const struct addrinfo *hints,struct addrinfo **res);

#define MAXBUFLEN 100

	if ((rv = getaddrinfo(argv[1], SERVERPORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and make a socket
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("talker: socket");
			continue;
		}

		break;
	}

	if (p == NULL)
	{
		fprintf(stderr, "talker: failed to bind socket\n");
		return 2;
	}
	fd=fopen("sample_data.txt","r");
		
		data.cmd=AURA_open;
		strcpy(data.fname,argv[2]);
		
		//strcpy(buffer, argv[2]);
		
		sendto(sockfd, &data, strlen(buffer), 0, p->ai_addr, p->ai_addrlen);
		//sendto(sockfd, buffer, strlen(buffer), 0, p->ai_addr, p->ai_addrlen);
		

#if 0
	if ((numbytes = sendto(sockfd, buffer, strlen(buffer), 0,
					p->ai_addr, p->ai_addrlen)) == -1) {
		perror("talker: sendto");
		exit(1);
	}
#endif

	freeaddrinfo(servinfo);

	printf("talker: sent %d bytes to %s\n", numbytes, argv[1]);
	close(sockfd);

	return 0;
}
