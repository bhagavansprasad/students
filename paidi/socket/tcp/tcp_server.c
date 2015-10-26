#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include <poll.h>

int main(void)
{
	struct sockaddr_in mysockaddr;
	int socketfd;
	char sbuffer[1024]="hi";
	char rbuffer[1024];
	int newfd;
	int retval,sd_retval;
	int i = 1;
	struct pollfd fdarray[4];

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("--->server: failed to  create a socket \r\n");
		exit(1);
	}

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(9999);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr)) == -1)
	{
		perror("--->server: bind system call failed\n");
		close(socketfd);
		exit(1);
	}

	if(listen(socketfd, 5) == -1)
	{
		perror("--->server: listen system call failed\n");
		close(socketfd);
		exit(1);
	}

	printf("--->server: Going for accepting connection \r\n");
    sd_retval=sizeof(struct sockaddr_in);
	printf("-->sdretval:%d\n",sd_retval);

/*	while(1)
	{
		newfd = accept(socketfd, ((struct sockaddr *)&mysockaddr),&sd_retval);
		if(newfd == -1)
		{
			perror("--->server: accept system call failed\n");
			close(newfd);
			exit(1);
		}

        fdarray[i].fd=newfd;
		fdarray[i].events = POLLIN;
		fdarray[i].revents=0;
		printf("--->server: Got the connection request from client \r\n");



        retval=poll(fdarray,4,10);
		if(fdarray[i].events == POLLIN)
		{
*/
		while(1)
		{
			sleep(1);
			retval=read(fdarray[i].fd, rbuffer, 30);
			if(retval < 0)
			{
				break;
			}
            rbuffer[retval]='\0';
			printf("-->%d. read success retval :%d\n", i++, retval);
			printf("--->server:buffer:%s\n",rbuffer);

			retval=write(fdarray[i].fd, sbuffer, 30);
			if(retval < 0)
			{
				break;
			}
			printf("--->server: write retval :%d\n",retval);
		}
	// }
	
	close(newfd);
	//return 0;

}











/*#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include <poll.h>

int main(void)
{
	struct sockaddr_in mysockaddr;
	int socketfd;
	char sbuffer[1024]="how are you";
	char rbuffer[1024];
	int newfd;
	int retval,sd_retval;
	int i = 1;
	struct pollfd fdarray[4];

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("--->server: failed to  create a socket \r\n");
		exit(1);
	}

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(9999);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr)) == -1)
	{
		perror("--->server: bind system call failed\n");
		close(socketfd);
		exit(1);
	}

	if(listen(socketfd, 5) == -1)
	{
		perror("--->server: listen system call failed\n");
		close(socketfd);
		exit(1);
	}

	printf("--->server: Going for accepting connection \r\n");
    sd_retval=sizeof(struct sockaddr_in);
	printf("-->sdretval:%d\n",sd_retval);

	while(1)
	{
		newfd = accept(socketfd, ((struct sockaddr *)&mysockaddr),&sd_retval);
		if(newfd == -1)
		{
			perror("--->server: accept system call failed\n");
			close(newfd);
			exit(1);
		}

        fdarray[i].fd=newfd;
		fdarray[i].events = POLLIN;
		fdarray[i].revents=0;
		printf("--->server: Got the connection request from client \r\n");



        retval=poll(fdarray,4,10);
		if(fdarray[i].events == POLLIN)
		{

		while(1)
		{
			sleep(1);
			retval=read(fdarray[i].fd, rbuffer, 30);
			if(retval < 0)
			{
				break;
			}
            rbuffer[retval]='\0';
			printf("-->%d. read success retval :%d\n", i++, retval);
			printf("--->server:buffer:%s\n",rbuffer);

			retval=write(fdarray[i].fd, sbuffer, 30);
			if(retval < 0)
			{
				break;
			}
			printf("--->server: write retval :%d\n",retval);
		}
		}
	}
	close(newfd);

	return 0;

}
*/
