/****************** SERVER CODE ****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
    int welcomeSocket, newSocket;
    char buffer[256];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero); 

    bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    if(listen(welcomeSocket, 5) == 0)
        printf("Listening\n");
    else
        printf("Error\n");

    addr_size = sizeof serverAddr;
    newSocket = accept(welcomeSocket, (struct sockaddr *) &serverAddr, &addr_size);

    recv(newSocket, buffer, 256, 0);
    printf("Data received: %s",buffer);  

    strcpy(buffer, "Hello, i am server \n");
    send(newSocket, buffer, 100, 0);

    return 0;
}
