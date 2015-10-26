#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<unistd.h>
#include<error.h>
#include<stdlib.h>
#include"strc.h"
#include"struct.h"
#include<fcntl.h>
int socketfd=-1;
void client_req(void)
{
int connected;
struct sockaddr_in myclientaddr;
socketfd=socket(AF_INET,SOCK_STREAM,0);
if(socketfd==-1)
{
perror("client:failed to creat a socket\n");
exit(1);
}
myclientaddr.sin_family=AF_INET;
myclientaddr.sin_addr.s_addr=inet_addr("192.168.1.30");
myclientaddr.sin_port=htons(7777);
printf("client : connecting to the server\n");
connected=connect(socketfd,(struct sockaddr
*)&myclientaddr,sizeof(myclientaddr));
if(connected==-1)
{
perror("client: connect system failed\n");
close(socketfd);
exit(1);
}
}
int client (struct ch *q)
{
int retval;
retval=write(socketfd,q,sizeof(struct ch));
printf("client :write retval %d\n",retval);
return(retval);
}
int client_read(struct server *y)
{
int retval;
retval=read(socketfd,y,sizeof(struct server));
printf("client :read retval from server %d\n",retval);
return(retval);

}
