#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
int main()
{
char buffer[100];
int n,sd=0,sd1=0;
int addlen;
struct sockaddr_in client_addr,server_addr;
sd=socket(AF_INET,SOCK_STREAM,0);
if(sd<0)
{
perror("error in connecting socket");
exit(1);
}
server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(9876);
server_addr.sin_addr.s_addr=inet_addr("192.168.1.44");
if(bind(sd,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
{
perror("error in binding");
exit(1);
}
listen(sd,5);
addlen=sizeof(client_addr);
sd1=accept(sd,(struct sockaddr*)&client_addr,&addlen);
label:
read(sd1,buffer,strlen(buffer));
printf("%s",buffer);
write(sd1,buffer,strlen(buffer));
goto label;
close(sd);
close(sd1);
}
