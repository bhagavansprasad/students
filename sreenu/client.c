#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
int main()
{
struct sockaddr_in client_addr,server_addr;
char buff[100];
int n,addrlen;
int sd=0,sd1=0;
sd=socket(AF_INET,SOCK_STREAM,0);
if(sd<0)
{
perror("error in creating socket");
}
else
{
printf("socket created successfully");
}
server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(9292);
server_addr.sin_addr.s_addr=inet_addr("192.168.1.30");
if(bind(sd,(struct sockaddr*) &server_addr,sizeof(server_addr))<0)
{
perror("error in binding");
}
if(listen(sd,5))
{
perror("error in listening");
}
addrlen=sizeof(client_addr);
if(sd1=accept(sd,(struct sockaddr*)&client_addr,&addrlen)<0)
{
perror("error in acceptinfg");
}
n=read(sd1,buff,sizeof(buff));
if(n<0)
{
perror("error in reading");
}
printf("%s",buff);
return 0;
}

