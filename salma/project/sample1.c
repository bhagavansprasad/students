// server program
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<strings.h>
#include<stdlib.h> 
#define SERV_UDP_PORT 6000
#define SERV_TCP_PORT 6000
#define SERV_HOST_ADDR  "192.43.235.6"
char *pname;
main(argc, argv)
int argc;
char *argv[];
{
int  sockfd,newsockfd,clilen,childpid;
struct sockaddr_in cli_addr,serv_addr;
pname=argv[0];
if(sockfd=socket(AF_INET,SOCK_STREAM,0)<0)
perror("server:cant open stream socket");
bzero((char *)&serv_addr,sizeof(serv_addr));
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
serv_addr.sin_port=htons(SERV_TCP_PORT);
if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
perror("server:cant bind local address");
listen(sockfd,5);
for(; ;)
{
clilen=sizeof(cli_addr);
newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
if(newsockfd<0)
perror("server:accept error");
if((childpid=fork())<0)
perror("server:fork error");
else if(childpid==0)
{
close(sockfd);
doprocessing(newsockfd);
exit(0);
}
close(newsockfd);
}
}

