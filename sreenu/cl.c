#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
int main()
{
char buffer[100];
int n;
struct sockaddr_in server_addr;
int sd=0;
sd=socket(AF_INET,SOCK_STREAM,0);
if(sd<0)
{
perror("error in connecting socket");
exit(1);
}
server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(9876);
server_addr.sin_addr.s_addr=inet_addr("192.168.1.44");
if((connect(sd,(struct sockaddr*)&server_addr,sizeof(server_addr)))<0)
{
perror("error in connecting socket");
exit(1);
}
label:
printf("enter the message");
scanf("%s",buffer);
n=write(sd,buffer,strlen(buffer));
if(n<0)
{
perror("error in writitng the socket");
exit(1);
}
read(sd,buffer,strlen(buffer));
printf("%s",buffer);
goto label;
close(sd);
return 0;
}

