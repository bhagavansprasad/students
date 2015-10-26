#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"

int main(void)
{
	struct sockaddr_in mysockaddr;
	int socketfd;
	int newfd;
	char sbuffer[1024]="hellow aura netwok";
	char rbuffer[1024];
	int retval,sd_retval;

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("--->server: failed to  create a socket \r\n");
		exit(1);
	}

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(8888);
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
	printf("--->server : Going for accepting connection \r\n");
	while(1)
	{
		sd_retval=sizeof(struct sockaddr_in);

		newfd = accept(socketfd, ((struct sockaddr *)&mysockaddr),&sd_retval);
		if(newfd == -1)
		{
			perror("--->server: accept system call failed\n");
			close(newfd);
			exit(1);
		}
		sleep(1);			
		retval=read(newfd, rbuffer, 20);
		if(retval < 0)
		{
			break;
		}

		printf("--->server:buffer read from client:%s\n",rbuffer);
		retval=write(newfd, sbuffer,20);
		if(retval < 0)
		{
			break;
		}

	}
	close(newfd);
	return 0;

}
