#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"

int toggle_case(char ch)
{
	if (ch >= 'A' && ch  <= 'Z')
		return (ch + ('a' - 'A'));
	else if (ch >= 'a' && ch  <= 'z')
		return (ch - ('a' - 'A'));
	else
		return ch;
}

int convert_case(char *dst, char *src)
{
	int i = 0;

	for (i = 0; (dst[i] = toggle_case(src[i])); i++);

	return i;
}

int main()
{
	struct sockaddr_in mysockaddr;
	int socketfd;
	char buffer[100];
	char sresponse[100];
	char rbuffer[100];
	int newfd;
    int retval = 0;
	int i;
	socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(socketfd == -1)
	{
		perror("failed to  create a socket \r\n");
		exit(1);
	}

	printf ("S: Opening socket :%d\n", socketfd);

	memset(&mysockaddr, 0, sizeof(mysockaddr));
	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(9999);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	retval = bind(socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr));
	if(retval == -1)
	{
		perror("bind system call failed\n");
		close(socketfd);
		exit(1);
	}
	printf ("S: bind retval :%d\n", retval);

	retval = listen(socketfd, 5);
	if(retval == -1)
	{
		perror("listen system call failed\n");
		close(socketfd);
		exit(1);
	}
	printf ("S: listen retval :%d\n", retval);

	while(1)
	{
		printf("S : Going for accepting connection \n");

		newfd = accept(socketfd, NULL, NULL);
		if(newfd == -1)
		{
			perror("accept system call failed\r\n");
			close(socketfd);
			exit(1);
		}
		printf ("S: Accept newfd :%d\n", newfd);

		printf("S : Got the connection request from client\n");
		while(1)
		{
			sleep(2);
			retval = read(newfd, buffer, 100);
			printf ("S. read retval :%d\n", retval);
			if(retval < 0)
			{
				break;
			}
			buffer[retval]='\0';
			printf("S. Received data from client :'%s'\n", buffer);
			convert_case(sresponse, buffer);

			retval = write(newfd, sresponse, strlen(sresponse));
			printf ("S. write retval :%d\n", retval);
			if(retval < 0)
			{
				break;
			}
			printf("S. Wrote %d, bytes to client response :'%s'\n", retval, sresponse);
			if(strcmp(buffer, "bye") == 0)
			{
				close(newfd);
				break;
			}
		}
	}
	close(socketfd);
	return 0;
}
