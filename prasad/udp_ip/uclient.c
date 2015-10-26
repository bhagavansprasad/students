#include "stdio.h"
#include "arpa/inet.h"
#include "netinet/in.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"

#define SRV_IP "127.0.0.1"
#define BUFLEN 512
#define NPACK 10
#define PORT 9930

int main(void)
{
    struct sockaddr_in si_var;
    int socketfd,i,slen=sizeof(si_var);
    char buf[BUFLEN];

    if((socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
    {
	perror("socket systemcall failed:\r\n");
	exit(1);
    }

    memset((char *)&si_var, 0, sizeof(si_var));
    si_var.sin_family = AF_INET;
    si_var.sin_port = htons(PORT);
    if(inet_aton(SRV_IP, &si_var.sin_addr)==0)
    {
	fprintf(stderr, "inet_aton() failed\n");
	exit(1);
    }

    for(i=0; i<NPACK; i++)
    {
	printf("sending packet%d\n",i);
	sprintf(buf, "this is packet %d\n",i);
	if(sendto(socketfd, buf, BUFLEN, 0, (struct sockaddr *)&si_var, slen)==-1)
	{
	    perror("sendto systemcall failed:\r\n");
	    exit(1);
	}
    }
    close(socketfd);
    return 0;

}
