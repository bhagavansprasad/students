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
	char sbuffer[3][20]={"hellow","i am fine","bye"};
	char rbuffer[1024];
	int newfd;
	int retval,sd_retval,i;


	socketfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(socketfd == -1)
	{
		perror("--->server: failed to  create a socket \n");
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


	printf("--->server: Going for accepting connection \n");

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
		if(fork() == 0)
		{
			printf("--->server: Got the connection request from client \n");

	    	for(i=0;i<3;i++)
	    	{
				sleep(1);
				retval=read(newfd, rbuffer, 50);
				printf("--->consrvr: read retval:%d\n",retval);
				if(retval < 0)
				{
					break;
				}
                rbuffer[retval]='\0';
				printf("--->server:buffer read from client:%s\n",rbuffer);
				retval=write(newfd, &sbuffer[i],50);
				printf("--->consrvr: write retval:%d\n",retval);
				if(retval < 0)
				{
					break;
				}

			}
			close(newfd);
			exit(1);
		}
		else
		{
			close(newfd);
		}

	}
	close(newfd);

	return 0;

}
