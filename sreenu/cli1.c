#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<error.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
	struct sockaddr_in server_addr;
	char buff[100];
	int n,sd=0;
	sd=socket(AF_INET,SOCK_STREAM,0);
	if(sd<0)
	{
		perror("error in creating socket");
	}
	else
	{
		printf("socket created sucesfully");
	}
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(9292);
	server_addr.sin_addr.s_addr=inet_addr("192.168.1.35");
	if(connect(sd,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
	{
		perror("error in connecting");
	}
	else
	{
	printf("socket connected sucerssfully");
	}
	printf("enter message");
	fgets(buff,sizeof(buff),stdin);
	n=write(sd,buff,strlen(buff));
	if(n<0)
	{
		printf("error in writing the message");
	}
	close(sd);
	return 0;
}
