#include "stdio.h"
#include "arpa/inet.h"
#include "netinet/in.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"

#define BUFLEN 512
#define NPACK 10
#define PORT 9930

int main(void)
{
    struct sockaddr_in si_me,si_other;
    int socketfd,i,slen=sizeof(si_other);
    char buf[BUFLEN];

    if((socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
    {
	perror("socket systemcall failed:\r\n");
	exit(1);
    }

    memset((char *)&si_me, 0, sizeof(si_me));
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(PORT);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(socketfd, (struct sockaddr *)&si_me, sizeof(si_me))==-1)
    {
	perror("bind system call failed:\r\n");
	exit(1);
    }

    for(i=0; i<NPACK; i++)
    {
	if(recvfrom(socketfd, buf, BUFLEN, 0, (struct sockaddr *)&si_other, &slen)==-1)
	{
	    perror("recvfrom system call failed :\r\n");
	    exit(1);
	}
	printf("Received packet from %s:%d\n Data: %s\n",inet_ntoa(si_other.sin_addr),ntohs(si_other.sin_port), buf);
    }

    close(socketfd);
    return 0;

}

