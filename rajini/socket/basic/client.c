
#include<stdio.h> 
#include<string.h>    
#include<sys/socket.h>    
#include<arpa/inet.h> 
 
int main(int argc , char *argv[])
{
    int sockfd;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];
     
    //Create socket
    sockfd = socket(AF_INET , SOCK_STREAM , 0);
    if (sockfd == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
 
    //Connect to remote server
    if (connect(sockfd , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
     
    puts("Connected\n");
     
    //keep communicating with server
    while(1)
    {
        printf("Enter message : ");
        scanf("%s" , message);
         
        //Send some data
        if( send(sockfd , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
         
        //Receive a reply from the server
        if( recv(sockfd , server_reply , 2, 0) < 0)
        {
            puts("recv failed");
            break;
        }
         
        puts("Server reply :");
        puts(server_reply);
    }
     
    close(sockfd);
    return 0;
}
