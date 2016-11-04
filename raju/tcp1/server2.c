//SERVER
#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#define MAX 80
#define PORT 43454
#define SA struct sockaddr
void func(int sockfd)
{
	char buff[MAX];
	int n;
	for(;;)
	{
		bzero(buff,MAX);
		read(sockfd,buff,sizeof(buff));
		printf("From client: %s\t To client : ",buff);
		bzero(buff,MAX);
		n=0;
		while((buff[n++]=getchar())!='\n');
		write(sockfd,buff,sizeof(buff));
		if(strncmp("exit",buff,4)==0)
		{
			printf("Server Exit...\n");
			break;
		}
	}
}
int main()
{
	int sockfd,connfd[10],len,i;
	struct sockaddr_in servaddr,cli;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	printf("sd:%d\n",sockfd);
	if(sockfd==-1)
	{
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(PORT);
	if((bind(sockfd,(SA*)&servaddr, sizeof(servaddr)))!=0)
	{
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");
	if((listen(sockfd,5))!=0)
	{
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");
	len=sizeof(cli);

	for(i=0 ;i<5 ;i++)
	{
		connfd[i]=accept(sockfd,(SA *)&cli,&len);
		printf("connfd[%d]:%d\n",i,connfd[i]);
		if(connfd[i]<0)
		{
			printf("server acccept failed...\n");
			exit(0);
		}
		else
			printf("server acccept the client...\n");
		func(connfd[i]);
		
		bzero(&cli,sizeof(cli));

	}

	close(sockfd);
}
