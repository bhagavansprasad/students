#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>

int main()
{
	int rd,sockfd, sockfd2,n,i;

	char buff[1024],buffer[1024] = "I am server";

	struct sockaddr_in serv_addr, cli_addr;
	socklen_t clilen;

	if((sockfd=socket(AF_INET, SOCK_STREAM, 0)) <0)
	{
		perror(" Error opening the socket \n");
		exit(1);
	}

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(6102);
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

	memset(serv_addr.sin_zero, '\0', sizeof serv_addr.sin_zero);

	if(bind(sockfd,( struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
	{
		perror("Errro binding Socket");
		exit(1);
	}

	if(listen(sockfd,4)==0)
		printf(" Listening\n");
	else
		printf(" Not listening.. Error !!! \n" );

	clilen = sizeof cli_addr;
	bzero(buff,1024);

	if((sockfd2= accept(sockfd, (struct sockaddr *) &cli_addr,&clilen))<0)
	{
		perror(" Error on accept !! \n");
		exit(1);
	}
	memset(serv_addr.sin_zero,'\0',sizeof serv_addr.sin_zero);

label:    
	rd = read(sockfd2,buff,1024);

	printf("S: Received msg : %s\n",buff);
	//	printf("size of buff : %d strlen of buff :%d\n",sizeof(buff),strlen(buff));
	bzero(buff,sizeof(buff));

	send(sockfd2, buffer, strlen(buffer), 0);
	goto label;

	close(sockfd2);
}	














