#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"unistd.h"

int main(void)
{
    int socketfd;
    int connected;
    struct sockaddr_in myclientaddr;
    char buff[30]="hi paidi ";

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd == -1)
    {
	perror("Failed to create a socket \r\n");
	exit(1);
    }

    myclientaddr.sin_family = AF_INET;
    myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    myclientaddr.sin_port = htons(1919);
   
    printf("client : Connecting to the server\r\n");
    connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
    if(connected == -1)
    {
	perror("connect system call failed\r\n");
	exit(1);
    }

    write(socketfd, buff, sizeof(buff));
    read(socketfd, buff, sizeof(buff));
    printf("string read from server:%s\r\n",buff);

    close(socketfd);

    return 0;

}

