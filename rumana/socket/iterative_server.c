#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"

int main()
{
	struct sockaddr_in mysockaddr;
	int socketfd;
	//	char buff1[3][20]={"hellow","i am fine","bye"};
	char ruffer[100];
	char wuffer[100];
	int newfd;
	int retval = 0,i;
	socketfd = socket(AF_INET, SOCK_STREAM,0);
	if(socketfd == -1)
	{
		perror("failed to  create a socket \r\n");
		exit(1);
	}

	memset(&mysockaddr, 0, sizeof(mysockaddr));

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(9999);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr)) == -1)
	{
		perror("bind system call failed\r\n");
		close(socketfd);
		exit(1);
	}

	if(listen(socketfd, 5) == -1)
	{
		perror("listen system call failed\r\n");
		close(socketfd);
		exit(1);
	}


	while(1)
	{
		printf("--->server : Going for accepting connection \r\n");
		newfd = accept(socketfd,NULL,NULL);
		if(newfd == -1)
		{
			perror("accept system call failed\r\n");
			close(socketfd);
			exit(1);
		}

		printf("--->server : Got the connection request from client \r\n\n");
		while(1)
		{
			sleep(2);
			retval = read(newfd, ruffer, 30);
			if(retval < 0)
			{
				break;
			}
			ruffer[retval]='\0';
			printf("--->server:  receive from client :%s\r\n",ruffer);
			gets(wuffer);
			retval=write(newfd, wuffer, 20);
			if(retval < 0)
			{
				break;
			}
			printf("--->server: buff1 write retval : %d\n",retval);
			if(strcmp(ruffer, "bye") == 0)
				break;

		}
	}
	close(socketfd);
	return 0;
}
