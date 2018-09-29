//client program
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define SERV_UDP_PORT 6000
#define SERV_TCP_PORT 6000
#define SERV_HOST_ADDR  "192.43.235.6"
char *pname;
main(argc,argv)
int argc;
char *argv[];
{
int sockfd;
struct sockaddr_in serv_addr;
pname=argv[0];
bzero((char *)&serv_addr,sizeof(serv_addr));
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr(SERV_HOST_ADDR);
serv_addr.sin_port=htons(SERV_TCP_PORT);
if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
err_sys("client :cant open stream socket");
if(connet(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
err_sys("client :cant connect to server");
str_cli(stdin,sockfd);
close(sockfd);
exit(0);
}
