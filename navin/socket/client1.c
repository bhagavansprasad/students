#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>



int main()
{

	int sockfd, n;
	char buff[1024];
	struct sockaddr_in serv_addr;

	socklen_t addr_size;


	sockfd=socket(AF_INET,SOCK_STREAM,0);

	if(sockfd < 0)
	{ 

		perror(" Error opening Socket \n");
		exit(1);
	}

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(5060);
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

	memset(serv_addr.sin_zero, '\0',sizeof serv_addr.sin_zero);
	 addr_size=sizeof serv_addr;
	connect(sockfd,(struct sockaddr *) &serv_addr, addr_size);

label:

    printf("Enter the message: ");
	fgets(buff,255,stdin);
	send(sockfd,buff,1024,0);
	bzero(buff,sizeof(buff));

	recv(sockfd,buff,1024,0);

	printf("Date received : %s ", buff);
    goto label;

   close(sockfd);
}





