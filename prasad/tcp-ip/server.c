#include"stdio.h"
#include"stdlib.h"
#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"unistd.h"

int main(int argc, char *argv[])
{
//Declaring process variables
int server_sockfd, client_sockfd;
int server_len, client_len;
struct sockaddr_in server_address;
struct sockaddr_in client_address;

//remove any old socket and create an unnamed socket for server
server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
server_address.sin_family = AF_INET;
server_address.sin_addr.s_addr = htons(INADDR_ANY);
server_address.sin_port = htons(7766) ;
server_len = sizeof(server_address);
bind(server_sockfd, (struct sockaddr *) &server_address, server_len);

//create a connection queue and wait for clients
listen(server_sockfd,5);
while(1)
{
char ch;
printf("server waiting\n");

//Accept a connection 
client_len = sizeof(client_address);
client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address, &client_len);

//read write to client on client_sockfd
read(client_sockfd, &ch, 1);
ch++;
write(client_sockfd,&ch, 1);
close(client_sockfd);

}
return 0;

}
