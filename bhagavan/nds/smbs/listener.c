/*
** listener.c -- a datagram sockets "server" demo
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
#include "mydefs.h"
#include "nds_smb_api.h"
#include "sys_fop.h"

#define MYPORT "9999"	// the port users will be connecting to

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(void)
{
	int sockfd;
	struct addrinfo hints, *servinfo, *p;
	int rv;
	int numbytes;
	struct sockaddr_storage caddr;
	socklen_t addr_len;
	char s[INET6_ADDRSTRLEN];

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE; // use my IP

	if ((rv = getaddrinfo(NULL, NDS_SMB_SRVR_UDP_PORT, &hints, &servinfo)) != 0) 
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and bind to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) 
	{
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) 
		{
			perror("listener: socket");
			continue;
		}

		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) 
		{
			close(sockfd);
			perror("listener: bind");
			continue;
		}
		break;
	}

	if (p == NULL) 
	{
		fprintf(stderr, "listener: failed to bind socket\n");
		return 2;
	}

	freeaddrinfo(servinfo);

	printf("listener: waiting to recvfrom...\n");


	while(1)
	{
		client_request creq;
		client_request sreply;
		char *reply;
		int retval;

		addr_len = sizeof caddr;

		if ((numbytes = recvfrom(sockfd, &creq, sizeof(client_request), 0, (struct sockaddr *)&caddr, &addr_len)) == -1) 
		{
			perror("recvfrom");
			exit(1);
		}

		printf("-->smbS: got packet from %s\n",
				inet_ntop(caddr.ss_family,
					get_in_addr((struct sockaddr *)&caddr),
					s, sizeof s));
		printf("-->smbS: listener: packet is %d bytes long\n", numbytes);

		printf("-->smbS: received command :%d\n", creq.cmd);
		switch(creq.cmd)
		{
			case OPEN_REQUEST:
				sys_open(&creq, &sreply);
				sendto(sockfd, &sreply, sizeof(client_request), 0, (struct sockaddr *)&caddr, sizeof(caddr));
				break;
			case READ_REQUEST:
				reply = malloc(sizeof(client_request) + creq.len);
				retval = sys_read(&creq, reply);
				sendto(sockfd, reply, sizeof(client_request)+retval, 0, (struct sockaddr *)&caddr, sizeof(caddr));
				free(reply);
				break;
			case WRITE_REQUEST:
				break;
			case LSEEK_REQUEST:
				break;
			case CLOSE_REQUEST:
				break;
			case OPEN_REPLY:
				break;
			case READ_REPLY:
				break;
			case WRITE_REPLY:
				break;
			case LSEEK_REPLY:
				break;
			case CLOSE_REPLY:
				break;
			default:
				break;
		}
	printf("\n");
	}

	close(sockfd);

	return 0;
}
