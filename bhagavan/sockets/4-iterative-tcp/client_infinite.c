#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"unistd.h"
#include"string.h"

int main(void)
{
	int socketfd;
	int retval = 0;
	int connected =  0;
	struct sockaddr_in myclientaddr;
	char buffer[]="This is my second program for TCP/IP";
	int i = 0;

	socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(socketfd == -1)
	{
		perror("Failed to create a socket \r\n");
		exit(1);
	}

	printf ("C: Opening socket SUCCESS:%d\n", socketfd);

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port = htons(9999);

	printf("C: Connecting to the server\n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("connect system call failed\r\n");
		exit(1);
	}
	printf ("C: Connect success retval :%d\n", connected);

	printf("Begin chat\n");

	for (i = 1; i <= 5; i++)
	{
		printf ("C: Writing '%s' to server\n", buffer);

		retval = write(socketfd, buffer, strlen(buffer));
		if (retval <= 0)
		{
			perror("Write failed\n");
			printf("Write failed :%d\n", retval);
			close(socketfd);
			exit(1);
		}
		printf ("C: Write retval '%d'\n", retval);

		printf ("C: Going to sleep for 5 sec, before read the response from server \n");
		sleep(1);
		printf ("C: Going to read response from server\n");
		retval = read(socketfd, buffer, 100);
		if (retval <= 0)
		{
			perror("Read failed\n");
			printf("Read failed :%d\n", retval);
			close(socketfd);
			exit(1);
		}

		buffer[retval] = '\0';
		printf("C: read retval :%d\n", retval);
		printf("C: Read response '%s' from server\n", buffer);
	}
	write(socketfd, "bye", strlen("bye\n"));

	printf ("C: Closing the socket\n");
	close(socketfd);

	return 0;
}
